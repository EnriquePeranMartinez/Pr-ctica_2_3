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




## 006.cpp (Diccionario + ahora con módulos)

De momento, Fecha.h es padre de todas a nivel de módulos

Vamos a declarar el `DiccionarioCuacs dic;` como una variable global para no tener que pasarlo como parámetro a todas las funciones

¿Por qué es const el array de frases? -> Porque sabemos que no van a cambiar
Ahora lo ponemos como `extern`, pues no puede estar redefinido en Cuac.cpp, con el extern le decimos que está definido en otro sitio.


Hemos decidido que DiccionarioCuacs tendrá un atributo privado Iterador, para no crearlo cada vez al insertar.

### En insertar	
`while (itLista != lista.end() && insertado == false)`, en principio no puede ocurrir el error de intentar acceder al valor de lista.end(), porque después de avanzar lo primero que se hace es comprobar si es el final.

### En last
i++ va primero. Si se pone al final, siempre añadirá un cuac de más al total, porque lo suma antes de verificar la condición

### En date
Creo que el segundo while vuelve a hacer los mismos 
	```cuac = *itLista;
	fecha = cuac.getFecha();```
que el while anterior, pero bueno creo que funciona bien.



## 200 (TablaHash)

La función de dispersión devolverá un `long long int` para evitar desbordamiento.
Los métodos `funcionDispersion()` y `reestructurar()` son privados, solo los utilizará la tabla.

De momento, reestructurar se llamará cuando el número de elementos sea el doble que el cubetas de la lista (2*M)

Creo que la mejor forma de almacenar los cuacs es almacenando en cada elemento del array
el nombre de usuario y un puntero a una lista con sus Cuacs. De esta manera, cuando se busquen los Cuacs de un usuario en
concreto, solo tiene que buscar el nombre mediante la función de dispersión, y luego buscar en la lista.
**¿Esto tiene problemas?** -> Si tengo pocos usuarios se me van a llenar mucho las cubetas. PASA LO MISMO DE LA OTRA MANERA

Vamos a crear la clase Par que contiene el nombre de usuario y la lista con los cuacs del usuario.
¿Hacer que Par esté dentro de TablaHash? ¿Cómo declarar sus atributos, privados, públicos, hacer getters? -> De momento fuera + getters.

He dividido insertar en insertar en el Par e insertar el Cuac en la lista de Cuacs del Par. PUEDE QUE LUEGO LO CAMBIE

Sobre la memoria dinámica:
Creo que solo hace falta reservar memoria para el array de listas de pares, porque lo demás (list<>) ya reservan automáticamente