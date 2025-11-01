#include<iostream>

using namespace std;

int dias_meses[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
		string escribir();
		bool es_menor(Fecha &otra);
		bool es_igual(Fecha &otra);
};


Fecha::Fecha (){ }	// Constructor

int Fecha::get_day() { return day; }
int Fecha::get_month() { return month; }
int Fecha::get_year() { return year; }
int Fecha::get_hour() { return hour; }
int Fecha::get_minute() { return minute; }
int Fecha::get_second() { return second; }

void Fecha::leer()
{ 	
	// Leer Días
	char d[2];
	d[0] = cin.get();
	d[1] = cin.get();

	if (d[1] != '/')
	{
		day = atoi(d);		// Como es un char*, podemos usar atoi
		cin.ignore(); // Ignoramos la barra
	}
	else
	{
		day = d[0] - '0'; // Restamos 48 al código ascii del carácter para que nos dé el número entero 
	}

	// Leer meses
	char m[2];
	m[0] = cin.get();
	m[1] = cin.get();

	if (m[1] != '/')
	{
		month = atoi(m);	// Como es un char*, podemos usar atoi
		cin.ignore(); 		// Ignoramos la barra
	}
	else
	{
		month = m[0] - '0'; // Restamos 48 al código ascii del carácter para que nos dé el número entero 
	}

	// Leer año
	cin >> year; 	// Leemos hasta el espacio en blanco
	cin.ignore();	// Saltamos el espacio en blanco

	// Leer horas
	char h[2];
	h[0] = cin.get();
	h[1] = cin.get();
	hour = atoi(h);
	cin.ignore();
	// Leer minutos
	char mi[2];
	mi[0] = cin.get();
	mi[1] = cin.get();
	minute = atoi(mi);
	cin.ignore();
	// Leer minutos
	char s[2];
	s[0] = cin.get();
	s[1] = cin.get();
	second = atoi(s);
}


string Fecha::escribir()
{ 
	// Convertir a string ??
	string fecha = 
}

bool Fecha::es_menor(Fecha &otra)
{ 
	if (year < otra.get_year()) { return true; }
	else if (year > otra.get_year()) { return false; }
	if (month < otra.get_month()) { return true; }
	else if (month > otra.get_month()) { return false; }
	if (day < otra.get_day()) { return true; }
	else if (day > otra.get_day()) { return false; }
	if (hour < otra.get_hour()) { return true; }
	else if (hour > otra.get_hour()) { return false; }
	if (minute < otra.get_minute()) { return true; }
	else if (minute > otra.get_minute()) { return false; }
	if (second < otra.get_second()) { return true; }
	else { return false; }
}

bool Fecha::es_igual(Fecha &otra)
{ 
	if (year == otra.get_year() && 
		month == otra.get_month() &&
		day == otra.get_day() &&
		hour == otra.get_hour() &&
		minute == otra.get_minute() &&
		second == otra.get_second()) {
			return true; 
	} else {
		return false;
	}
}



int main(){
    int N;
    Fecha factual, fanterior;

    cin >> N;
    cin.ignore();	// Ignorar el salto de línea

	fanterior.leer();	// Leemos la primera línea (la primera no se compara con la anterior, no hay)

    for (int i = 0; i < N - 1; i++)
    {   
		factual.leer();

		if (factual.es_menor(fanterior)){
			cout << factual.escribir() << "ES ANTERIOR A " << fanterior.escribir() << endl;
		}
		else if (factual.es_igual(fanterior)){
			cout << factual.escribir() << "ES IGUAL A " << fanterior.escribir() << endl;
		}
		else {
			cout << factual.escribir() << "ES IGUAL A " << fanterior.escribir() << endl;
		}
		
		fanterior = factual;		//TODO esto está bien?? referencia y tal

    }

    return 0;

	
    
}