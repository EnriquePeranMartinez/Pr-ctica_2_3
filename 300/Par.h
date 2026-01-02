#ifndef PAR_H
#define PAR_H

#include <string>
#include <list>
#include "Cuac.h"

class Par{
   private:
      string usuario;      // Nombre del usuario
      list<Cuac> cuacs;    // Lista de sus cuacs 
   public:
      Par();
      Par(string u, list<Cuac> c);
      string getUsuario() { return usuario; }   // Necesitaremos el usuario para comparar al insertar
      list<Cuac>& getCuacs() { return cuacs; }  // Y la lista de cuacs por referencia para poder insertar el nuevo
};
#endif