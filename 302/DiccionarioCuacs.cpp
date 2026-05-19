#include "DiccionarioCuacs.h"


void DiccionarioCuacs::insertar (Cuac nuevo){    
    Cuac *ref = tabla.insertar(nuevo);
    arbol.insertar(arbol.getRaiz(), ref); 
}

void DiccionarioCuacs::follow (string nombre){ 
    tabla.consultar(nombre); 
}

void DiccionarioCuacs::last (int N){ 
    arbol.last(N); 
}

void DiccionarioCuacs::date (Fecha f1, Fecha f2){ 
    arbol.date(f1, f2); 
}
