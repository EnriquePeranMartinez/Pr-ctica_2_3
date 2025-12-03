#ifndef DICCIONARIOCUACS_H
#define DICCIONARIOCUACS_H

#include "TablaHash.h"

class DiccionarioCuacs {
     private:
          TablaHash tabla;
     public:
     void insertar (Cuac nuevo)
          { tabla.insertar(nuevo); }
     void follow (string nombre)
          { tabla.consultar(nombre); }
     void last (int N);
     void date (Fecha f1, Fecha f2);
     int numElem ()
          { return tabla.numElem(); }
};

#endif