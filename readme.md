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

¿Por qué es const el array de frases? $\to$ Porque sabemos que no van a cambiar
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


## 200 (TablaHash)	¿DEBERÍAMOS PASAR CASI TODO POR REFERENCIA?

De momento, reestructurar se llamará cuando el número de elementos sea el doble que el de las cubetas de la lista (2*M)

Creo que la mejor forma de almacenar los cuacs es almacenando en cada elemento del array
el nombre de usuario y un puntero a una lista con sus Cuacs. De esta manera, cuando se busquen los Cuacs de un usuario en
concreto, solo tiene que buscar el nombre mediante la función de dispersión, y luego buscar en la lista.
**¿Esto tiene problemas?** -> Si tengo pocos usuarios se me van a llenar mucho las cubetas. PASA LO MISMO DE LA OTRA MANERA
NO VA A HABER POCOS USUARIOS

Vamos a crear la clase Par que contiene el nombre de usuario y la lista con los cuacs del usuario.
¿Hacer que Par esté dentro de TablaHash? ¿Cómo declarar sus atributos, privados, públicos, hacer getters? -> De momento fuera + getters. Además, la lista de cuacs será por referencia para poder modificarla

He dividido insertar en insertar en el Par e insertar el Cuac en la lista de Cuacs del Par. PUEDE QUE LUEGO LO CAMBIE

Sobre la memoria dinámica:
Creo que solo hace falta reservar memoria para el array de listas de pares, porque lo demás (list<>) ya reservan automáticamente

El constructor para `DiccionarioCuacs` **no hace falta** porque no inicializa nada, usa la TablaHash.

Creamos la tabla con tamaño inicial 50000 de forma un poco intuitiva, ya que el archivo de entrada grande tiene unas 100000 líneas, y lo podemos tomar como una cota inferior.

### insertar tabla hash

Un iterador para los pares y otro para los cuacs de cada par
Para poder modificar la lista de pares de la tabla, se pasa por referencia, al igual que su lista de cuacs.
Haremos un bucle para encontrar un par que sea el mismo usuario (o si no, añadirlo al final), y otro dentro para insertar el cuac.
La inserción es similar a la del ejercicio anterior.

### reestructurar
Como los datos de Par gestionan automáticamente su memoria dinámica, solo tenemos que hacer delete[] vieja para borrar la tabla antigua y asignar la nueva a T 


### Función de dispersión

La función de dispersión devolverá un `long long int` para evitar desbordamiento.
Los métodos `funcionDispersion()` y `reestructurar()` son privados, solo los utilizará la tabla.

Probaremos primero con la suma posicional -> De momento no parece que saque valores muy repartidos

### consultar

Muy similar a insertar

!! TODO: Cambiar variable i para "Total: i cuacs" por contador en ejercicios anteriores !!
aunque igual no hace falta, solo cuenta realmente el proyecto final

## Pruebas tamaño tabla y funciones de dispersión
Tamaño fijo




## 300 (Árbol)

Al final de insertar() de TablaHash.cpp, devolvemos la referencia del cuac insertado 
 !!! ¿Hay que disminuir el it como en las diapositivas?







 # Sesiones de trabajo

 2/1/2026 -- 11~13