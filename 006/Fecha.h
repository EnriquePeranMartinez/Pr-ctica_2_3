#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;    // No necesitamos usar std::, ni en Cuac.h ni en interprete.cpp

class Fecha {
	private:
		int day, month, year;
		int hour, minute, second;
		
	public:
		Fecha();
		// Getters
		int get_day();
		int get_month();
		int get_year();
		int get_hour();
		int get_minute();
		int get_second();
		// Funcionalidad
		void leer();
		void escribir();
		bool es_menor(Fecha &otra);
		bool es_igual(Fecha &otra);
};

#endif
