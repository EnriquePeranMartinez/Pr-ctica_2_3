#include "TablaHash.h"
#include <list>


unsigned long long TablaHash::funcionDispersion(string usuario){
    return 0;   
}

void TablaHash::reestructurar(){

}

TablaHash::TablaHash (){
    nElem = 0;
    int M = TAM_TABLA;

    list<Par> *T = new list<Par>[M];  // Construimos la tabla con dispersión abierta y tamaño variable
}

TablaHash::~TablaHash (){
    delete[] T;
}

void TablaHash::insertar (Cuac nuevo){
    
    if (nElem > 2*M)
	{
		reestructurar();
	}

    string nuevo_usuario = nuevo.getUsuario();          // Guardamos el nombre del usuario del cuac que queremos insertar
    unsigned long long int h = funcionDispersion(nuevo_usuario);   // Casilla del array en la que lo meteremos
    
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
    //...
}

