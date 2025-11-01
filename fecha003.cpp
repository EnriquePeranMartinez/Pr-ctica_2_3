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

void numero_a_frase(int num){
    cout << frases[num - 1] << endl;
}

void frase_a_numero(string frase){
    int i = 0;
    while((i < NUMERO_FRASES) && frase.compare(frases[i]) != 0){

        i++;
    }
    
    if (i >= NUMERO_FRASES){
        cout << "ERROR. Cadena no encontrada: [" << frase << "]" << endl;
    } else{
        cout << i + 1 << endl;
    }
}

int dias_meses[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


class Fecha {
	private:
		int day, month, year;
		int hour, minute, second;
	public:
		Fecha();
		Fecha leer();
		void escribir();
		bool es_menor(Fecha &otra);
		bool es_igual(Fecha &otra);
};


Fecha::Fecha (){ }	// Constructor

Fecha Fecha::leer()
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
		month = atoi(m);		// Como es un char*, podemos usar atoi
		cin.ignore(); // Ignoramos la barra
	}
	else
	{
		month = m[0] - '0'; // Restamos 48 al código ascii del carácter para que nos dé el número entero 
	}

	// Leer año
	cin >> year; // Leemos hasta el espacio en blanco

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
	cin.ignore();

}
void Fecha::escribir()
{ /*...*/ }
bool Fecha::es_menor(Fecha &otra)
{ return false; }
bool Fecha::es_igual(Fecha &otra)
{ /*...*/ }

int main(){
    int N;
    Fecha factual, fanterior;

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {   
		factual.leer();
        
    }

    return 0;
    
}