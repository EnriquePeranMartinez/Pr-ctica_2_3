#ifndef ARBOL_H
#define ARBOL_H

#include "Fecha.h"
#include "Cuac.h"
#include "Nodo.h"
#include <iostream>
#include <list>

class Arbol {
  private:
    Nodo *raiz;
    int getAlturaNodo(Nodo *n); // Función auxiliar para manejar cuando el nodo sea NULL
    
  public:
     Arbol ();
     ~Arbol ();
     void insertar (Nodo *&A, Cuac *x);
     void last (int N);
     void date (Fecha f1, Fecha f2);
    
     // Rotaciones
     void RSI(Nodo *&A);  
     void RSD(Nodo *&A);
     void RDI(Nodo *&A);
     void RDD(Nodo *&A);

     // Getters
      Nodo *&getRaiz() {return raiz;}
};


#endif