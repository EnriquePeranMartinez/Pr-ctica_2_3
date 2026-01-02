#ifndef ARBOL_H
#define ARBOL_H

#include "Cuac.h"
#include "Nodo.h"

class Arbol {
  private:
    Nodo *hijo;
     //...
  public:
     Arbol ();
     ~Arbol ();
     void insertar (Cuac *ref);
     void last (int N);
     void date (Fecha f1, Fecha f2);
     //...
};


#endif