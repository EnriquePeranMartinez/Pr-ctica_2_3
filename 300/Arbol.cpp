#include "Arbol.h"

Arbol::Arbol (){
    raiz = NULL;
}

int Arbol::getAlturaNodo(Nodo *n){      // Función auxilixar para manejar cuando el nodo sea NULL
    if (n == NULL){
        return -1;
    }
    else {
        return n->getAltura();
    }
}


void Arbol::insertar (Cuac *ref){
    if (raiz == NULL)           // Si el árbol está vacío
    {
        Nodo *nuevo = new Nodo();   // Creamos un nuevo nodo e inicializamos todos sus valores
        nuevo->setCuac(ref);
        nuevo->setIzq(NULL);
        nuevo->setDer(NULL);
        nuevo->setAltura(0);
    }
    else {
        Cuac r = raiz->getCuac();
        if (ref->es_anterior(r));
        {
            /* code */
        }
        
    }
    

}

void Arbol::last (int N){

}

void Arbol::date (Fecha f1, Fecha f2){

}

// Rotaciones

void Arbol::RSI(Nodo *&A){
    Nodo *B = A->getIzq();
    A->setIzq(B->getDer());
    B->setDer(A);
    A->setAltura(1 + max(getAlturaNodo(A->getIzq()),  
                         getAlturaNodo(A->getDer())));
    B->setAltura(1 + max(getAlturaNodo(B->getIzq()),  
                         getAlturaNodo(A)));
    A = B;
}


void Arbol::RSD(Nodo *&A){
    Nodo *B = A->getDer();
    A->setDer(B->getIzq());
    B->setIzq(A);
    A->setAltura(1 + max(getAlturaNodo(A->getDer()),  
                         getAlturaNodo(A->getIzq())));
    B->setAltura(1 + max(getAlturaNodo(B->getDer()),  
                         getAlturaNodo(A)));
    A = B;
}

void Arbol::RDI(Nodo *&A){
    Nodo *A_izq = A->getIzq();      // De nuevo, el valor A->getIzq() se perdería en la misma línea de código de RSD()
    RSD(A_izq);                 // Esto es una copia de la dirección del nodo izquierdo
    A->setIzq(A_izq);           // Entonces volvemos a asignar el nodo inmediatamente después
    RSI(A);
}

void Arbol::RDD(Nodo *&A){
    Nodo *A_der = A->getDer();      // De nuevo, el valor A->getDer() se perdería en la misma línea de código de RSI()
    RSI(A_der);                 // Esto es una copia de la dirección del nodo derecho
    A->setDer(A_der);           // Entonces volvemos a asignar el nodo inmediatamente después
    RSD(A);                     
}