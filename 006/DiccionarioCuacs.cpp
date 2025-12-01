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
    itLista = lista.begin();
    Cuac cuac;
    int i = 0;

    while (itLista != lista.end()){         // Recorro toda la lista en el peor de los casos
        cuac = *itLista;
        if (nombre == cuac.getUsuario()){       // Para cada cuac compruebo si es el nombre que me pasan
            i++;
            cout << i << ". ";                      // Escribimos el número del cuac
            cuac.escribir();                        // Escribimos el cuac
            cout << endl;                           // Salto de línea para el siguiente
        }
        itLista++;
    }
    cout << "Total: " << i << " cuac" << endl; // Escribimos el total de cuacs que se han impreso
}

void DiccionarioCuacs::date (Fecha f1, Fecha f2){
    itLista = lista.begin();
    Cuac cuac;
    Fecha fecha;
    int i = 0;
    bool bajo_f2 = false;
    bool sobre_f1 = true;

    // Como están los de la fecha más alta al principio, comprobamos esa primero
    
    // Primer while para avanzar hasta llegar a f2
    while (itLista != lista.end() && bajo_f2 == false){ // Avanzamos hasta que se acabe la lista o bajemos de la fecha f2
        cuac = *itLista;
        fecha = cuac.getFecha();
        if (f2.es_menor(fecha)){        // Si la fecha del cuac va después que la máxima (f2), seguimos recorriendo, reduciendo fecha
            itLista++;
        }
        else bajo_f2 = true;
    }

    // Segundo while para imprimir hasta llegar a f1
    while (itLista != lista.end() && sobre_f1 == true)
    {
        cuac = *itLista;
        fecha = cuac.getFecha();        // Esto es código repetido de la última iteración del bucle anterior !!!
        if (!fecha.es_menor(f1)){
            i++;
            cout << i << ". ";                      // Escribimos el número del cuac
            cuac.escribir();                        // Escribimos el cuac
            cout << endl;                           // Salto de línea para el siguiente
        }
        else sobre_f1 = false;
        itLista++;
    }
    cout << "Total: " << i << " cuac" << endl; // Escribimos el total de cuacs que se han impreso
}
