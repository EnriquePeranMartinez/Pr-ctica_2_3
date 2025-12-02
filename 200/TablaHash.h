#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "Cuac.h"
#define TAM_TABLA 50000 


class Par{
   private:
      string usuario;      // Nombre del usuario
      list<Cuac> cuacs;    // Lista de sus cuacs 
   public:
      Par();
      Par(string u, list<Cuac> c);
      ~Par();
      string getUsuario() { return usuario; }   // Necesitaremos el usuario para comparar al insertar
      list<Cuac>& getCuacs() { return cuacs; }  // Y la lista de cuacs para poder insertar el nuevo
};

class TablaHash {
   private:
      int nElem;      // Elementos de la tabla
      int M;          // Tamaño de la tabla
      list<Par> *T;     // Array de listas que contienen Pares de usuarios y sus listas de cuacs
      unsigned long long funcionDispersion (string usuario);
      void reestructurar(void);
      void insertarCuac(Cuac nuevo);   // Este será privado porque solo lo utiliza insertar

   public:
      TablaHash ();
      ~TablaHash ();
      void insertar (Cuac nuevo);
      void consultar (string nombre);
      int numElem (void) { return nElem; }
};

#endif