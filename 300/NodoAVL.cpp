#include "NodoAVL.h"


NodoAVL::NodoAVL () {
    altura = 0;
    cuac = NULL;
    izq = NULL;
    der = NULL;
}

NodoAVL::~NodoAVL(){ 
    delete izq;
    delete der;
}