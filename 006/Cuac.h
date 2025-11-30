#ifndef CUAC_H
#define CUAC_H

#include "Fecha.h"

#define NUMERO_FRASES 30
extern const string frases[NUMERO_FRASES];

string numero_a_frase(int num);

class Cuac {
  private:
    Fecha fecha;
    string usuario;
    string texto;
  public:
  	Cuac();
	// Getters
	Fecha getFecha();
	string getUsuario();
	string getTexto();
	// Funcionalidad
	
    bool leer_mcuac();
    bool leer_pcuac();
    void escribir();
    bool es_anterior(Cuac &otro);
};

#endif