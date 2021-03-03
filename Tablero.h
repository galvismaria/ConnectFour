#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"
#include "Global.h"

/*

	Clase que representa el tablero del juego.
	Debido a que el tama�o del tablero es est�tico, se utiliza un arreglo bidimensional de Casillas como estructura de datos principal.

*/

using namespace std;

class Tablero{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
			
		Casilla* tabla[FILAS][COLUMNAS];
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructor ----- */
		
		Tablero();													// Constructor sin par�metros -> Crea un tablero con todas las casillas vac�as
		
		/* ----- Setter ----- */
		
		void setCasilla(char ficha, int x, int y);
		
		/* ----- Getter ----- */
		
		Casilla* getCasilla(int x, int y);
		
		/* ----- Procedimientos ----- */						
		
		void mostrarTabla();										// Funci�n que imprime el tablero
																	// Si la ficha en la casilla es '/0', significa que la casilla est� vac�a, as� que se muestra un espacio en blanco
																	// Si la casilla est� ocupada por JUGADOR_1, se imprime una 'X'
																	// Si la casilla est� ocupada por JUGADOR_2, se imprime una 'O'
																	
		int obtenerFilaDesocupada(int columna);						// Funci�n que retorna la primera fila desocupada (desde abajo hacia arriba)
		
		void colocarFicha(int fila, int columna, char ficha);		// Funci�n que coloca una ficha en unas coordenadas espec�ficas
		
		bool casillaOcupada(int fila, int columna);					// Funci�n que valida si una casilla est� ocupada o est� libre
		
		bool columnaLlena(int columna);								// Funci�n que valida si una columna ya est� llena
		
		bool enRango(int fila, int columna);						// Funci�n que valida si las coordenadas dadas est�n dentro del rango del tablero
		
		bool conectaCuatro(char equipo);							// Funci�n que valida si un jugador ha conectado cuatro piezas,
																	//ya sea de forma horizontal, vertical o diagonal
				
		void conectarFichas(char equipo);
																
		bool hacerMovimiento(int columna, char ficha);				// Funci�n para realizar un movimiento
																	// Seg�n la columna dada, busca la fila donde colocar la ficha dada
																	
		int contarArriba(int x, int y, char equipo);				// Funci�n que cuenta cuantas fichas est�n conectadas hacia arriba
		
		int contarDerecha(int x, int y, char equipo);				// Funci�n que cuenta cuantas fichas est�n conectadas hacia la derecha
		
		int contarArribaDerecha(int x, int y, char equipo);			// Funci�n que cuenta cuantas fichas est�n conectadas en la diagonal superior derecha
		
		int contarAbajoDerecha(int x, int y, char equipo);			// Funci�n que cuenta cuantas fichas est�n conectadas en la diagonal inferior derecha
		
		/* ----- Destructor ----- */
		
		~Tablero();
};

#endif
