# Decisiones de diseño

## Fecha.cpp (003)

`fanterior = factual;` -> Esto no asigna referencia, copia los campos (que son tipos primitivos), o sea que no hay problema.

## 004.cpp (Clase Cuac)
Cambiamos `numero_a_frase` para que devuelva un string en vez de imprimirlo directamente.

Creamos otro objeto fecha, no podemos hacer directamente `es_menor(otro.getFecha())` porque el valor se pierde en la misma línea de código al no ser una variable real. (Gemini 3.0)

Al principio escribimos este código para `es_anterior`. Luego le preguntamos a Gemini si era eficiente, y nos dio una solución más eficiente y legible (Gemini 3.0).

```bool Cuac::es_anterior(Cuac &otro)
{
	Fecha otra = otro.getFecha();	// Creamos otro objeto fecha, no podemos hacer directamente es_menor(otro.getFecha()) porque el valor se pierde en la misma línea de código al no ser una variable real.
	if(fecha.es_menor(otra)){	// La fecha es anterior -> el cuac es anterior
		return true;
	}
	
	
	else if (fecha.es_igual(otra)){	// Misma fecha -> Comparar orden alfabético de menor a mayor del texto
		if(texto < otro.getTexto()){
			return true;
		} 
		else if (texto == otro.getTexto()){	// Mismo texto -> Comparar orden alfabético de menor a mayor del usuario
			if(usuario < otro.getUsuario()){
				return true;
			}
			else return false;		// Con dos mensajes idénticos ya no se hace nada
		}
		else return false;
	}

	else return false;

}
``` 

## 005.cpp (Intérprete de comandos)

`Cuac actual;`	// Lo definimos después de la clase Cuac.

Quitado un salto de línea en Cuac::escribir después del texto.
