#include<iostream>
#include<string>
#include<limits>
#include<cstdio>

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
		void escribir();
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

	cin >> day;
	cin.ignore();	// Ignorar el '/'
	cin >> month;
	cin.ignore();	// Ignorar el '/'
	cin >> year;
	cin.ignore();	// Ignorar el espacio
	cin >> hour;
	cin.ignore();	// Ignorar el ':'
	cin >> minute;
	cin.ignore();	// Ignorar el ':'
	cin >> second; 

}

void Fecha::escribir()
{ 
	// Fecha
	cout << day << "/" 
	<< month << "/"
	<< year << " ";
	
	// Rellenamos con ceros
	if (hour < 10) {cout << "0";}
	cout << hour << ":";
	
	if (minute < 10) cout << "0";
	cout << minute << ":";
	
	if (second < 10) cout << "0";
	cout << second;
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
			factual.escribir();
			cout << " ES ANTERIOR A ";
			fanterior.escribir();
			cout << endl;
		}
		else if (factual.es_igual(fanterior)){
			factual.escribir();
			cout << " ES IGUAL A ";
			fanterior.escribir();
			cout << endl;
		}
		else {
			factual.escribir(); 
			cout << " ES POSTERIOR A ";
			fanterior.escribir();
			cout << endl;
		}
		
		fanterior = factual;

    }

    return 0;
}