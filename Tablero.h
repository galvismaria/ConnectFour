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

const int coordFilas[]    = { 1, 1, 0, -1 };
const int coordColumnas[] = { 0, 1, 1, 1 };

/*

	* * * * * * * * * * * * * * * * * * * * *
	*            *             *            *
	* (x-1, y-1) *  ( x, y-1 ) * (x+1, y-1) *
	*            *             *            *
	* * * * * * * * * * * * * * * * * * * * *
	*            *             *            *
	* ( x-1, y ) *  (  x, y  ) * ( x+1, y ) *
	*            *             *            *
	* * * * * * * * * * * * * * * * * * * * *
	*            *             *            *
	* (x-1, y+1) *  ( x, y+1 ) * (x+1, y+1) *
	*            *             *            *
	* * * * * * * * * * * * * * * * * * * * *
	
	[x+1][y]     ->  Derecha
	[x+1][y+1]   ->  Abajo-derecha
	[x][y+1]     ->  Abajo
	[x-1][y+1]   ->  Abajo-izquierda
	[x-1][y]     ->  Izquierda
	[x-1][y-1]   ->  Arriba-izquierda
	[x][y-1]     ->  Arriba
	[x+1][y-1]   ->  Arriba-derecha

*/

class Tablero{
	
	private:
		
		Casilla* tabla[ANCHO][ALTO];
		
	public:
		
		Tablero();
		void mostrarTabla();
		int obtenerFilaDesocupada(int columna);
		void colocarFicha(int columna, int fila, char ficha);
		bool casillaOcupada(int fila, int columna);
		bool enRango(int columna, int fila);
		bool conectaCuatro(int fila, int columna);
		int enLinea(int fila, int columna, int direccion);
		~Tablero();
};

#endif
