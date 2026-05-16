#ifndef NODO_H
#define NODO_H

#include "Fecha.h"
#include "Cuac.h"
#include <iostream>  

using namespace std;

class Nodo {
   private:
      int altura;
      Cuac *cuac;    
      Nodo *izq;
      Nodo *der;

   public:
      Nodo ();
      ~Nodo ();

      // Getters
      Nodo *&getIzq() {return izq;}
      Nodo *&getDer() {return der;}
      int getAltura() {return altura;}
      Cuac *getCuac() {return cuac;}

      // Setters
      void setIzq(Nodo *nuevoizq) {izq = nuevoizq;}
      void setDer(Nodo *nuevoder) {der = nuevoder;}
      void setAltura(int nuevaAltura) {altura = nuevaAltura;}
      void setCuac(Cuac* nuevo) {cuac = nuevo;}
};

#endif