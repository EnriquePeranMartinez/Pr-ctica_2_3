#ifndef DICCIONARIOCUACS_H
#define DICCIONARIOCUACS_H

#include "TablaHash.h"
#include "Arbol.h"
#include "Cuac.h"
#include "Fecha.h"
#include <iostream>

using namespace std;

class DiccionarioCuacs {
     private:
          TablaHash tabla;
          Arbol arbol;
     public:
     void insertar (Cuac nuevo);
     void follow (string nombre);
     void last (int N);
     void date (Fecha f1, Fecha f2);
     int numElem () { return tabla.numElem(); }
};

#endif