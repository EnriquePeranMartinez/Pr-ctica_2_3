#ifndef DICCIONARIOCUACS_H
#define DICCIONARIOCUACS_H

#include "TablaHash.h"
#include "Arbol.h"
#include "Cuac.h"
#include <iostream>

using namespace std;

class DiccionarioCuacs {
     private:
          TablaHash tabla;
          Arbol arbol;
     public:
     void insertar (Cuac nuevo)
          {    Cuac *ref= tabla.insertar(nuevo);
               arbol.insertar(ref); }
     void follow (string nombre)
          { tabla.consultar(nombre); }
     void last (int N)
       { arbol.last(N); }
     void date (Fecha f1, Fecha f2)
       { arbol.date(f1, f2); }
     int numElem ()
          { return tabla.numElem(); }
};

#endif