#include "Cuac.h"

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

Cuac::Cuac() {  }		// constructor

Fecha Cuac::getFecha() { return fecha; }
string Cuac::getUsuario() { return usuario;}
string Cuac::getTexto() { return texto; }

bool Cuac::leer_mcuac()
{
    cin >> usuario;
    fecha.leer();
	cin.ignore();		// Ignoramos el \n
    getline(cin, texto);
    if (texto.size() > 140) return false;
	else return true;
}

bool Cuac::leer_pcuac()
{
	int n_mensaje;
	cin >> usuario;
    fecha.leer();
	cin.ignore();		// Ignoramos el \n
	cin >> n_mensaje;	// Guardamos el número del mensaje
	texto = numero_a_frase(n_mensaje);	// Lo convertimos y lo asignamos al texto

	return true;
}

void Cuac::escribir()
{
	cout << usuario << " ";
	fecha.escribir();
	cout << endl << "   " << texto;
}

bool Cuac::es_anterior(Cuac &otro)
{	
	//  Vamos a asumir que las mayúsculas son menores que las minúsculas porque así es como se compara por defecto 

	Fecha otra = otro.getFecha();	// Creamos otro objeto fecha, no podemos hacer directamente es_menor(otro.getFecha()) porque el valor se pierde en la misma línea de código al no ser una variable real.
	
	if(fecha.es_menor(otra)) return true; 	// La fecha es anterior -> el cuac es anterior

	if (!fecha.es_igual(otra)) return false;	// Entonces la fecha es mayor -> el cuac es posterior

	string otroTexto = otro.getTexto(); // Nos ahorramos llamar una vez a getTexto()

	if (texto < otroTexto) return true;		// Comparamos texto
    if (texto > otroTexto) return false;

	return usuario < otro.getUsuario();		// Si era igual, comparamos usuario

}