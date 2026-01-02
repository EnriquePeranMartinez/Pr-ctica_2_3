#include "TablaHash.h"
#include <list>
#include <cmath>

unsigned int TablaHash::funcionDispersion(string usuario){
    unsigned int res = 0;
    short int longitud = usuario.length();
    for (int i = 0; i < longitud; i++)      // Suma posicional
    {
        res = res + usuario[i] * pow(PRIMO,longitud - (i + 1));
    }

    //cout << "Dispersión: " << res % M << endl;
    return res % M;
    
    
}

void TablaHash::reestructurar(){
    int antiguaM = M;          // Guardamos M para iterar en la tabla vieja
    M = 2 * M;                 // Duplicamos el tamaño

    list<Par> *vieja = T;      // Guardamos la tabla vieja 
    list<Par> *nueva = new list<Par>[M];    // Creamos la nueva tabla con el doble de listas
    list<Par>::iterator itPar;      // Iterador para las listas de pares
    Par par_actual;
    int h;                          // Nuevo valor de la función de dispersión para la nueva tabla
    
    // BUCLE PARA RECORRER LAS CASILLAS DE LA TABLA
    for (int i = 0; i < antiguaM; i++)
    {
        // BUCLE PARA RECORRER LA LISTA DE PARES
        itPar = vieja[i].begin();      // Empezamos a iterar la lista de pares de la casilla i
        while (itPar != vieja[i].end())
        {
            par_actual = *itPar;                             // Cogemos el par por valor
            h = funcionDispersion(par_actual.getUsuario()); // Calculamos la nueva h
            nueva[h].push_back(par_actual);                 // Metemos el par en la nueva tabla
            itPar++;     
        }
    }
    
    delete[] vieja;
    T = nueva;
}

TablaHash::TablaHash (){
    nElem = 0;
    M = TAM_TABLA;

    T = new list<Par>[M];  // Construimos la tabla con dispersión abierta y tamaño variable
}

TablaHash::~TablaHash (){
    delete[] T;
}

Cuac *TablaHash::insertar (Cuac nuevo){
    
    if (nElem > 2*M)            // Vemos si hace falta reestructurar (hay el doble de elementos que el tamaño de la tabla)
	{
		reestructurar();
	}

    string nuevo_usuario = nuevo.getUsuario();          // Guardamos el nombre del usuario del cuac que queremos insertar
    unsigned int h = funcionDispersion(nuevo_usuario);   // Casilla del array en la que lo meteremos
    
    list<Par>::iterator itPar = T[h].begin();               // Tratamos la casilla del array como una lista a iterar
    list<Cuac>::iterator itCuac;                            // Iterador para recorrer los Cuacs de un par


    // BUCLE ENCONTRAR EL PAR DEL USUARIO
    bool insertado = false;                                 // Condición para saber si se ha encontrado ya un par con el mismo usuario
    while (itPar != T[h].end() && insertado == false){       // Vamos recorriendo toda la lista de pares
    
        Par &par_usuario = *itPar;                             // Sacamos el contenido del iterador (el par) por referencia
        if (nuevo_usuario == par_usuario.getUsuario()){                 // Comparamos el usuario del cuac a insertar con el del par
            list<Cuac> &lista_cuacs = par_usuario.getCuacs();           // Sacamos la lista de cuacs del par por referencia
            
            // BUCLE INSERTAR EN LA LISTA DE CUACS DEL PAR
            itCuac = lista_cuacs.begin();                               // Iterador para la lista de cuacs
            while (itCuac != lista_cuacs.end() && insertado == false){  // Recorreremos la lista de cuacs hasta llegar al final o insertarlo
                if (nuevo.es_anterior(*itCuac))  {                      // Vamos comprobando si el nuevo es anterior (más reciente) que el del par a comparar

                    lista_cuacs.insert(itCuac, nuevo);          // Si es así, se inserta
                    insertado = true;                           // y se marca la condición de insertado
                    /*
                    

                    PASÁRSELO AL ÁRBOL AQUÍ SUPONGO

                    
                    */
                }
                else itCuac++;                                  // Si no, simplemente seguimos
            }
            if (!insertado){
                lista_cuacs.push_back(nuevo);       // Si la recorremos entera y no se insertó (es el menos reciente), lo metemos al final
                insertado = true;
            }
        }
        else itPar++;       // No hemos encontrado un par con el mismo nombre de usuario esta iteración, seguimos.
    }
    // No hemos encontrado ningún par que tenga el mismo nombre de usuario que el nuevo -> creamos otro y lo metemos al final
    if (!insertado){
        list<Cuac> lista_nuevo;                 // Creamos la lista de cuacs propia del nuevo par
        lista_nuevo.push_back(nuevo);           // Añadimos el nuevo Cuac a su lista
        Par nuevo_par(nuevo_usuario, lista_nuevo);  // Creamos el nuevo par con los dos valores anteriors
        T[h].push_back(nuevo_par);              // Insertamos el nuevo par en la lista de la tabla
    }
    nElem++;        // + 1 cuac nuevo
}


void TablaHash::consultar (string nombre){
    // Recibo el nombre, voy a buscar la casilla de la tabla (con funcDisp) donde estará el usuario.
    // Luego lo buscaré de entre la lista de Pares
    unsigned int h = funcionDispersion(nombre);
    list<Par>::iterator itPar = T[h].begin();               // Tratamos la casilla del array como una lista a iterar
    list<Cuac>::iterator itCuac;                            // Iterador para recorrer los Cuacs de un par
    Cuac cuac;
    int contador = 0;

    // BUCLE ENCONTRAR PAR (NOMBRE USUARIO)
    bool encontrado = false;
    while (itPar != T[h].end() && encontrado == false){     // Recorremos los pares hasta encontrar el del nombre que buscamos
        Par &par_usuario = *itPar;
        if (nombre == par_usuario.getUsuario()){
            encontrado = true;
            // BUCLE LISTAR LOS CUACS DEL USUARIO
            list<Cuac> &lista_cuacs = par_usuario.getCuacs();
            itCuac = lista_cuacs.begin();
            while (itCuac != lista_cuacs.end()){
                contador++;
                cuac = *itCuac;
                cout << contador << ". ";
                cuac.escribir();
                cout << endl;
                itCuac++;
            }
        }
        else itPar++;
    }
    cout << "Total: " << contador << " cuac" << endl;
}

