#include "DiccionarioCuacs.h"


void DiccionarioCuacs::insertar(Cuac nuevo){
    // Insertar ordenado, los primeros elementos serán los Cuacs con fecha más reciente
    itLista = lista.begin();    // Inicializamos el iterador
    bool insertado = false;

    while (itLista != lista.end() && insertado == false){   // Mientras no llegue al final y no se haya insertado
        if (nuevo.es_anterior(*itLista)){                   // Se comprueba si el nuevo es anterior al actual de la lista
            lista.insert(itLista, nuevo);                   // Si es así, se inserta delante
            insertado = true;                               // Se marca que se ha insertado
        }
        else itLista++;                                     // Si no es anterior, se sigue iterando
    }
    if (!insertado) lista.push_back(nuevo);     // Si se ha recorrido toda la lista y no es anterior a ninguno, pues será el último
    
    contador++;             // +1 Cuac nuevo
}

void DiccionarioCuacs::last (int N){
    itLista = lista.begin();
    Cuac cuac;
    int i = 0;

    while (itLista != lista.end() && i < N){  // Mientras no llegue al final y todavía queden cuacs por mostrar
        i++;                                    // Uno menos para escribir
        cuac = *itLista;
        cout << i << ". ";                      // Escribimos el número del cuac
        cuac.escribir();                        // Escribimos el cuac
        cout << endl;                           // Salto de línea para el siguiente

        itLista++;                          // Avanzamos en la lista
    }
    cout << "Total: " << i << " cuac" << endl; // Escribimos el total de cuacs que se han impreso
}

void DiccionarioCuacs::follow (string nombre){

}

void DiccionarioCuacs::date (Fecha f1, Fecha f2){

}
