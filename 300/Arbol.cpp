#include "Arbol.h"

Arbol::Arbol (){
    raiz = NULL;
}

Arbol::~Arbol(){
    delete raiz;
}

int Arbol::getAlturaNodo(Nodo *n){      // Función auxilixar para manejar cuando el nodo sea NULL
    if (n == NULL){
        return -1;
    }
    else {
        return n->getAltura();
    }
}

void Arbol::insertar (Nodo *&A, Cuac *x){      // A será el nodo en el que insertar y x el Cuac a insertar
    if (A == NULL)           // Si el nodo no existea aún
    {
        Nodo *nuevo = new Nodo();   // Creamos un nuevo nodo e inicializamos todos sus valores
        nuevo->setCuac(x); 
        A = nuevo;
    }
    else if (x->es_anterior(*A->getCuac()))   // Si el que se va a insertar es anterior. 
    {   // Subárbol izquierdo
        insertar(A->getIzq(), x); // Metemos recursivamente el hijo en el subárbol izquierdo
        if ((getAlturaNodo(A->getIzq()) - getAlturaNodo(A->getDer())) > 1)
        {
            if (x->es_anterior(*A->getIzq()->getCuac())) RSI(A);    // Caso II(A)
            else RDI(A);    // Caso ID(A)
        } else {
            A->setAltura(1+ max(getAlturaNodo(A->getIzq()), getAlturaNodo(A->getDer())));
        }
    }
    else // Subárbol derecho: Si el que se va a insertar no es anterior.
    {   
        insertar(A->getDer(), x); // Metemos recursivamente el hijo en el subárbol derecho
        if ((getAlturaNodo(A->getDer()) - getAlturaNodo(A->getIzq())) > 1)
        {
            if (!(x->es_anterior(*A->getDer()->getCuac()))) RSD(A);    // Caso DD(A)
            else RDD(A);    // Caso DI(A)
        } else {
            A->setAltura(1+ max(getAlturaNodo(A->getIzq()), getAlturaNodo(A->getDer())));
        }
    }
}

void Arbol::last (int N){
    list<Nodo*> pila_cuacs;    // Pila para mantener el orden de los cuacs 
    Nodo *actual = raiz;
    int contador = 0;

    while (actual != NULL || !pila_cuacs.empty())   // Mientras haya nodos OR no hayamos imprimido todos 
    {                                                                // AND no nos hayamos pasado de los N que hay que imprimir
       while (actual != NULL)
       {
            pila_cuacs.push_back(actual);
            actual = actual->getIzq();              // Bajamos todo lo que podamos a la izquierda (los más recientes)
       }

       actual = pila_cuacs.back();      // Volvemos del NULL al último de la pila
       pila_cuacs.pop_back();       // Lo sacamos

       if (contador >= N)   // Ponemos la condición de no habernos pasado aquí, porque de otro modo podríamos imprimir de más
       {
        break;
       }

       contador++;
       cout << contador << ". ";
       actual->getCuac()->escribir();   // Escribimos el Cuac de actual
       cout << endl;

       actual = actual->getDer();   // Ahora al derecho y repetimos operación
    }
    cout << "Total: " << contador << " cuac" << endl;
}


void Arbol::date (Fecha f1, Fecha f2){
    return;
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