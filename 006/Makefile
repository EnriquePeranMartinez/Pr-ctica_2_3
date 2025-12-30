a.out: DiccionarioCuacs.o Fecha.o Cuac.o interprete.o
	g++ DiccionarioCuacs.o Fecha.o Cuac.o interprete.o

interprete.o: interprete.cpp DiccionarioCuacs.h TablaHash.h Cuac.h Fecha.h Par.h
	g++ -c interprete.cpp

DiccionarioCuacs.o: DiccionarioCuacs.cpp DiccionarioCuacs.h TablaHash.h Cuac.h Fecha.h Par.h
	g++ -c DiccionarioCuacs.cpp

Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp

Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp