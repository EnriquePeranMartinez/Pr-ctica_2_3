#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "Cuac.h"
#include "Par.h"
#include <list>
#define TAM_TABLA 50000
#define PRIMO 11



class TablaHash {
   private:
      int nElem;      // Elementos de la tabla
      int M;          // Tamaño de la tabla
      list<Par> *T;     // Array de listas que contienen Pares de usuarios y sus listas de cuacs
      unsigned int funcionDispersion (string usuario);
      void reestructurar(void);

   public:
      TablaHash ();
      ~TablaHash ();
      void insertar (Cuac nuevo);
      void consultar (string nombre);
      int numElem (void) { return nElem; }
};

#endif