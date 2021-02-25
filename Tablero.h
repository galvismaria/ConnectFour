#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "Casilla.h"
#include "Global.h"

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
		void colocarFichaEn(int columna);
		void mostrarTabla();
		int obtenerFilaDesocupada(int columna);
		Casilla* getCasilla(int x, int y);
		void setCasilla(char ficha, int x, int y);
		void colocarFicha(int fila, int columna, char ficha);
		bool casillaOcupada(int fila, int columna);
		bool columnaLlena(int columna);
		bool enRango(int fila, int columna);
		bool conectaCuatro(char equipo);
		bool hacerMovimiento(int columna, char ficha);
		int contarArriba(int x, int y, char equipo);
		int contarDerecha(int x, int y, char equipo);
		int contarArribaDerecha(int x, int y, char equipo);
		int contarAbajoDerecha(int x, int y, char equipo);
		~Tablero();
};

#endif
