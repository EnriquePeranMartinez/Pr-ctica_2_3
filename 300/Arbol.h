#ifndef ARBOL_H
#define ARBOL_H

#include "Cuac.h"

class Arbol {
  private:
     
  public:
     Arbol ();
     ~Arbol ();
     void insertar (Cuac *ref);
     void last (int N);
     void date (Fecha f1, Fecha f2);
};


#endif