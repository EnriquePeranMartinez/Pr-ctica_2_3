#include<iostream>

#define NUMERO_FRASES 30

using namespace std;

const string frases[NUMERO_FRASES] = { 
    "Afirmativo.",
    "Negativo.",
    "Estoy de viaje en el extranjero.",
    "Muchas gracias a todos mis seguidores por vuestro apoyo.",
    "Enhorabuena, campeones!",
    "Ver las novedades en mi pagina web.",
    "Estad atentos a la gran exclusiva del siglo.",
    "La inteligencia me persigue pero yo soy mas rapido.",
	"Si no puedes convencerlos, confundelos.",
	"La politica es el arte de crear problemas.",
	"Donde estan las llaves, matarile, rile, rile...",
	"Si no te gustan mis principios, puedo cambiarlos por otros.",
	"Un dia lei que fumar era malo y deje de fumar.",
	"Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.",
	"Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.",
	"Mi vida no es tan glamurosa como mi pagina web aparenta.",
	"Todo tiempo pasado fue anterior.",
	"El azucar no engorda... engorda el que se la toma.",
	"Solo los genios somos modestos.",
	"Nadie sabe escribir tambien como yo.",
	"Si le molesta el mas alla, pongase mas aca.",
	"Me gustaria ser valiente. Mi dentista asegura que no lo soy.",
	"Si el dinero pudiera hablar, me diria adios.",
	"Hoy me ha pasado una cosa tan increible que es mentira.",
	"Si no tienes nada que hacer, por favor no lo hagas en clase.",
    "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.",
	"Me despido hasta la proxima. Buen viaje!",
	"Cualquiera se puede equivocar, inclusivo yo.",
    "Estoy en Egipto. Nunca habia visto las piramides tan solas.",
	"El que quiera saber mas, que se vaya a Salamanca."
};

string numero_a_frase(int num){
    return frases[num - 1];
}


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
	
    void leer_mcuac();
    void leer_pcuac();
    void escribir();
    bool es_anterior(Cuac &otro);
};

Cuac::Cuac() {  }		// constructor

Fecha Cuac::getFecha() { return fecha; }
string Cuac::getUsuario() { return usuario;}
string Cuac::getTexto() { return texto; }

void Cuac::leer_mcuac()
{
    cin >> usuario;
    fecha.leer();
	cin.ignore();		// Ignoramos el \n
    getline(cin, texto);
}

void Cuac::leer_pcuac()
{
	int n_mensaje;
	cin >> usuario;
    fecha.leer();
	cin.ignore();		// Ignoramos el \n
	cin >> n_mensaje;	// Guardamos el número del mensaje
	texto = numero_a_frase(n_mensaje);	// Lo convertimos y lo asignamos al texto
}

void Cuac::escribir()
{
	cout << usuario << " ";
	fecha.escribir();
	cout << endl << "   " << texto << endl;
}

bool Cuac::es_anterior(Cuac &otro)  // Que sea anterior quiere decir que es más reciente, porque se muestra antes
{	
	//  Vamos a asumir que las mayúsculas son menores que las minúsculas porque así es como se compara por defecto 

	Fecha otra = otro.getFecha();	// Creamos otro objeto fecha, no podemos hacer directamente es_menor(otro.getFecha()) porque el valor se pierde en la misma línea de código al no ser una variable real.
	
	if(otra.es_menor(fecha)) return true; 	// La otra es menor -> el cuac es posterior (más reciente)

	if (!fecha.es_igual(otra)) return false;	// Entonces la otra es mayor -> el otro cuac es posterior 

	string otroTexto = otro.getTexto(); // Nos ahorramos llamar una vez a getTexto()

	if (texto < otroTexto) return true;		// Comparamos texto, si es menor el del cuac actual, asumimos que es más reciente
    if (texto > otroTexto) return false;

	return usuario < otro.getUsuario();		// Si era igual, comparamos usuario

}


int main(){
	
    string comando;
    int num = 0;

    while (cin >> comando) {
        Cuac cuac;
        if (comando == "mcuac") cuac.leer_mcuac();
        else if (comando == "pcuac") cuac.leer_pcuac();
        cout << ++num << " cuac" << endl;
        cuac.escribir();
    }
    return 0;
}