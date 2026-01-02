#include "Fecha.h"


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