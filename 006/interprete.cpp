#include<iostream>
#include "DiccionarioCuacs.h"

int contador = 0;

DiccionarioCuacs dic;   // Declaramos el diccionario aquí
Cuac actual;		// !!! Esto probablemente ya no hará falta !!!

void procesar_exit(){
	
}

void procesar_pcuac(){
	if (actual.leer_pcuac()){	// Lo leemos y nos aseguramos de que es correcto
		cout << ++contador << " cuac";		// Tenemos un cuac nuevo
		cout << endl;			// Salto de línea para el siguiente comando
	}
	else {
		cerr << "Error al procesar pcuac";
		procesar_exit();	// Forzamos la salidad del programa
	}

}

void procesar_mcuac(){
	if (actual.leer_mcuac()){	// Lo leemos y nos aseguramos de que es correcto
		cout << ++contador << " cuac";		// Tenemos un cuac nuevo
		cout << endl;			// Salto de línea para el siguiente comando
	}
	else {
		cerr << "Error al procesar pcuac";
		procesar_exit();	// Forzamos la salidad del programa
	}

}

void procesar_last(){
	int n;
	cin >> n;	// Leemos el número de los últimos cuacs que hay que mostrar

	cout << "last " << n << endl;	// Escribimos exactamente el mismo comando
	cout << "1. ";
	actual.escribir();	// Ponemos "1. " y escribimos el cuac (de momento solo el actual)
	cout << endl << "Total: 1 cuac" << endl;	// Ponemos el total de cuacs que de momento solo es 1
}

void procesar_follow(){
	string u;
	cin >> u;	// Leemos el nombre de usuario

	cout << "follow " << u << endl;	// Escribimos exactamente el mismo comando
	cout << "1. ";
	actual.escribir();	// Ponemos "1. " y escribimos el cuac (de momento solo el actual)
	cout << endl << "Total: 1 cuac" << endl;	// Ponemos el total de cuacs que de momento solo es 1
}

void procesar_date(){
	Fecha fecha_ini, fecha_fin;
	fecha_ini.leer();	// Leemos la fecha inicial
	fecha_fin.leer();	// Leemos la fecha final

	cout << "date ";	// Escribimos exactamente el mismo comando
	fecha_ini.escribir();
	cout << " ";
	fecha_fin.escribir();
	cout << endl;

	cout << "1. ";
	actual.escribir();	// Ponemos "1. " y escribimos el cuac (de momento solo el actual)
	cout << endl << "Total: 1 cuac" << endl;	// Ponemos el total de cuacs que de momento solo es 1
}

void procesar_tag(){
	string t;
	cin >> t;	// Leemos la etiqueta

	cout << "tag " << t << endl;	// Escribimos exactamente el mismo comando
	cout << "1. ";
	actual.escribir();	// Ponemos "1. " y escribimos el cuac (de momento solo el actual)
	cout << endl << "Total: 1 cuac" << endl;	// Ponemos el total de cuacs que de momento solo es 1
}

void interprete(string comando){
	if (comando == "pcuac") procesar_pcuac();
	else if (comando == "mcuac") procesar_mcuac();
	else if (comando == "last") procesar_last();
	else if (comando == "follow") procesar_follow();
	else if (comando == "date") procesar_date();
	else if (comando == "tag") procesar_tag();
	else if (comando == "exit") procesar_exit();
}

int main(){
	
	string comando;
	while (cin >> comando && comando!="exit")
		interprete(comando);
	
    return 0;
}