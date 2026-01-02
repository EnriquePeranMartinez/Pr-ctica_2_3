#ifndef DICCIONARIOCUACS_H
#define DICCIONARIOCUACS_H

#include "TablaHash.h"
#include "Arbol.h"

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
     void last (int N);
     void date (Fecha f1, Fecha f2);
     int numElem ()
          { return tabla.numElem(); }
};

#endif