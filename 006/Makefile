a.out: DiccionarioCuacs.o Fecha.o Cuac.o interprete.o
	g++ DiccionarioCuacs.o Fecha.o Cuac.o interprete.o

interprete.o: interprete.cpp DiccionarioCuacs.h
	g++ -c interprete.cpp

DiccionarioCuacs.o: DiccionarioCuacs.cpp DiccionarioCuacs.h Cuac.h
	g++ -c DiccionarioCuacs.cpp

Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp

Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp
