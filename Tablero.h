#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "Casilla.h"

#define COLUMNAS 7
#define FILAS 6

/*

	Clase que representa el tablero del juego.
	Debido a que el tamaño del tablero es estático, se utiliza un arreglo bidimensional de Casillas como estructura de datos principal.

*/

using namespace std;

class Tablero{
	
	private:
		
		Casilla* tabla[FILAS][COLUMNAS];
		
	public:
		
		Tablero();
		colocarFichaEn(int columna);
		void mostrarTabla();
		int obtenerFilaDesocupada(int columna);
		void colocarFicha(int fila, int columna, char ficha);
		bool casillaOcupada(int fila, int columna);
		bool enRango(int fila, int columna);
		bool conectaCuatro(char equipo);
		void hacerMovimiento(int columna, char ficha);
		~Tablero();
};

#endif
