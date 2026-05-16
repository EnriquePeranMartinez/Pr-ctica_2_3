#include "Nodo.h"


Nodo::Nodo () {
    altura = 0;
    cuac = NULL;
    izq = NULL;
    der = NULL;
}

Nodo::~Nodo(){ 
    delete izq;
    delete der;
}