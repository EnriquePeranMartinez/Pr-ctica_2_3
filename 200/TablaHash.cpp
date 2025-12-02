#include "TablaHash.h"
#include <list>

Par::Par(string u, list<Cuac> c){
    usuario = u;
    cuacs = c;
}

unsigned long long TablaHash::funcionDispersion(string usuario){

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

void TablaHash::insertarCuac (Cuac nuevo){

}

void TablaHash::insertar (Cuac nuevo){
    
    if (nElem > 2*M)
	{
		reestructurar();
	}

    string nuevo_usuario = nuevo.getUsuario();          // Guardamos el nombre del usuario del cuac que queremos insertar
    Par par_usuario;                                    // Declaramos una variable auxiliar para ir recogiendo los nombres de la lista de pares

    unsigned long long int h = funcionDispersion(nuevo_usuario);   // Casilla del array en la que lo meteremos
    list<Par>::iterator it = T[h].begin();              // Tratamos la casilla del array como una lista a iterar

    bool insertado = false;                             // Condición para saber si se ha encontrado ya un par con el mismo usuario
    while (it != T[h].end() && insertado == false)      // Vamos recorriendo toda la lista de pares
    {
        par_usuario = *it;                              // Sacamos el contenido del iterador (el par)
        if (nuevo_usuario == par_usuario.getUsuario())  // Comparamos el usuario del cuac a insertar con el del par
        {
            insertado = true;                           // Se ha encontrado el mismo usuario -> Saldremos del bucle en cuanto se inserte
            insertarCuac(nuevo);        
        }
        else it++;
    }
    if (!insertado)
    {
        list<Cuac> lista_nuevo;                 // Creamos la lista de cuacs propia del nuevo par
        lista_nuevo.push_back(nuevo);           // Añadimos el nuevo Cuac a su lista
        Par nuevo_par(nuevo_usuario, lista_nuevo);  // Creamos el nuevo par con los dos valores anteriors
        T[h].push_back(nuevo_par);              // Insertamos el nuevo par en la lista de la tabla
    }
    
    

    while (it != lista.end() && insertado == false){   // Mientras no llegue al final y no se haya insertado
        if (nuevo.es_anterior(*it)){                   // Se comprueba si el nuevo es anterior al actual de la lista
            lista.insert(it, nuevo);                   // Si es así, se inserta delante
            insertado = true;                               // Se marca que se ha insertado
        }
        else it++;                                     // Si no es anterior, se sigue iterando
    }
    if (!insertado) lista.push_back(nuevo);     // Si se ha recorrido toda la lista y no es anterior a ninguno, pues será el último
    

    nElem++;
}


void TablaHash::consultar (string nombre){
    //...
}

