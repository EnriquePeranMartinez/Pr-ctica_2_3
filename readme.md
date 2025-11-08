# Decisiones de diseño



## Fecha.cpp

- ``` fanterior = factual; ``` -> Esto no asigna referencia, copia los campos (que son tipos primitivos), o sea que no hay problema.

- Los métodos de leer y escribir quizá deberían ser bool en vez de void.