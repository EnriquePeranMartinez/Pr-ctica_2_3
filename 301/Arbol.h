#ifndef ARBOL_H
#define ARBOL_H

#include "Fecha.h"
#include "Cuac.h"
#include "NodoAVL.h"
#include <iostream>
#include <list>

class Arbol {
  private:
    NodoAVL *raiz;
    int getAlturaNodo(NodoAVL *n); // Función auxiliar para manejar cuando el nodo sea NULL
    
  public:
     Arbol ();
     ~Arbol ();
     void insertar (NodoAVL *&A, Cuac *x);
     void last (int N);
     void date (Fecha f1, Fecha f2);
    
     // Rotaciones
     void RSI(NodoAVL *&A);  
     void RSD(NodoAVL *&A);
     void RDI(NodoAVL *&A);
     void RDD(NodoAVL *&A);

     // Getters
      NodoAVL *&getRaiz() {return raiz;}    // Para que el diccionario pueda referirse al árbol
};


#endif