a.out: DiccionarioCuacs.o Fecha.o Cuac.o interprete.o TablaHash.o Par.o
	g++ -Wall DiccionarioCuacs.o Fecha.o Cuac.o interprete.o TablaHash.o Par.o 

interprete.o: interprete.cpp DiccionarioCuacs.h
	g++ -c interprete.cpp

DiccionarioCuacs.o: DiccionarioCuacs.cpp DiccionarioCuacs.h TablaHash.h
	g++ -c DiccionarioCuacs.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Cuac.h
	g++ -c TablaHash.cpp

Par.o: Par.cpp Par.h Cuac.h
	g++ -c Par.cpp

Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp

Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp
