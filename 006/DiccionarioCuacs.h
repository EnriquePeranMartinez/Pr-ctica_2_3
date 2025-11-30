#ifndef DICCIONARIOCUACS_H
#define DICCIONARIOCUACS_H

#include "Cuac.h"
#include <list>

class DiccionarioCuacs {
   private:
        list<Cuac> lista;
        list<Cuac>::iterator itLista;
        int contador;
   public:
        DiccionarioCuacs(){ contador = 0; }    // Constructor que solo inicializa el contador a 0
        void insertar (Cuac nuevo);
        void last (int N);
        void follow (string nombre);
        void date (Fecha f1, Fecha f2);
        int numElem ()
            {return contador;}
};

#endif