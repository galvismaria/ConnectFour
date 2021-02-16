#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "Casilla.h"

#define ANCHO 7
#define ALTO 6

/*

	Clase que representa el tablero del juego.
	Debido a que el tamaño del tablero es estático, se utiliza un arreglo bidimensional de Casillas como estructura de datos principal.

*/

using namespace std;

class Tablero{
	
	private:
		
		Casilla* tabla[ANCHO][ALTO];
		
	public:
		
		Tablero();
		obtenerFilaDesocupada();
		colocarFichaEn(int columna);
		~Tablero();
};

#endif
