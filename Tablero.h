#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"
#include "Global.h"

/*

	Clase que representa el tablero del juego.
	Debido a que el tamaño del tablero es estático, se utiliza un arreglo bidimensional de Casillas como estructura de datos principal.

*/

using namespace std;

class Tablero{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
			
		Casilla* tabla[FILAS][COLUMNAS];
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructor ----- */
		
		Tablero();													// Constructor sin parámetros -> Crea un tablero con todas las casillas vacías
		
		/* ----- Setter ----- */
		
		void setCasilla(char ficha, int x, int y);
		
		/* ----- Getter ----- */
		
		Casilla* getCasilla(int x, int y);
		
		/* ----- Procedimientos ----- */						
		
		void mostrarTabla();										// Función que imprime el tablero
																	// Si la ficha en la casilla es '/0', significa que la casilla está vacía, así que se muestra un espacio en blanco
																	// Si la casilla está ocupada por JUGADOR_1, se imprime una 'X'
																	// Si la casilla está ocupada por JUGADOR_2, se imprime una 'O'
																	
		int obtenerFilaDesocupada(int columna);						// Función que retorna la primera fila desocupada (desde abajo hacia arriba)
		
		void colocarFicha(int fila, int columna, char ficha);		// Función que coloca una ficha en unas coordenadas específicas
		
		bool casillaOcupada(int fila, int columna);					// Función que valida si una casilla está ocupada o está libre
		
		bool columnaLlena(int columna);								// Función que valida si una columna ya está llena
		
		bool enRango(int fila, int columna);						// Función que valida si las coordenadas dadas están dentro del rango del tablero
		
		bool conectaCuatro(char equipo);							// Función que valida si un jugador ha conectado cuatro piezas,
																	//ya sea de forma horizontal, vertical o diagonal
				
		void conectarFichas(char equipo);
																
		bool hacerMovimiento(int columna, char ficha);				// Función para realizar un movimiento
																	// Según la columna dada, busca la fila donde colocar la ficha dada
																	
		int contarArriba(int x, int y, char equipo);				// Función que cuenta cuantas fichas están conectadas hacia arriba
		
		int contarDerecha(int x, int y, char equipo);				// Función que cuenta cuantas fichas están conectadas hacia la derecha
		
		int contarArribaDerecha(int x, int y, char equipo);			// Función que cuenta cuantas fichas están conectadas en la diagonal superior derecha
		
		int contarAbajoDerecha(int x, int y, char equipo);			// Función que cuenta cuantas fichas están conectadas en la diagonal inferior derecha
		
		/* ----- Destructor ----- */
		
		~Tablero();
};

#endif
