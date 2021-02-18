#ifndef CASILLA_H
#define CASILLA_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

/*

	Clase que representa cada casilla que puede ser ocupada.
	Una casilla puede tener uno de los siguientes valores:
		'\0', que significa que la casilla está vacía
		'X', que significa que la casilla está ocupada por una ficha del equipo A
		'O', que significa que la casilla está ocupada por una ficha del equipo B

*/

class Casilla{
	
	private:
		
		char ficha;
		
	public:
		
		Casilla();
		Casilla(char ficha);
		char getFicha();
		void setFicha(char equipo);
		~Casilla();
	
};

#endif
