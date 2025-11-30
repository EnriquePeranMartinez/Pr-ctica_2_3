#include


class TablaHash {
  private:
     //...
     int nElem;
  public:
     TablaHash ();
     ~TablaHash ();
     void insertar (Cuac nuevo);
     void consultar (string nombre);
     int numElem (void) { return nElem; }
};