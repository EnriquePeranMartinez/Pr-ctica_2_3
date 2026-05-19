#ifndef NODOAVL_H
#define NODOAVL_H

#include "Fecha.h"
#include "Cuac.h"

using namespace std;

class NodoAVL {
   private:
      int altura;
      Cuac *cuac;    
      NodoAVL *izq;
      NodoAVL *der;

   public:
      NodoAVL ();
      ~NodoAVL ();

      // Getters
      NodoAVL *&getIzq() {return izq;}
      NodoAVL *&getDer() {return der;}
      int getAltura() {return altura;}
      Cuac *getCuac() {return cuac;}

      // Setters
      void setIzq(NodoAVL *nuevoizq) {izq = nuevoizq;}
      void setDer(NodoAVL *nuevoder) {der = nuevoder;}
      void setAltura(int nuevaAltura) {altura = nuevaAltura;}
      void setCuac(Cuac* nuevo) {cuac = nuevo;}
};

#endif