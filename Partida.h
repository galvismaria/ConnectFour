#ifndef PARTIDA_H
#define PARTIDA_H

#include "Tablero.h"
#include "Jugador.h"
#include "Computador.h"
#include "Humano.h"
#include "Global.h"

/*
	Clase encargada de crear la partida.
	Hay tres opciones de juego:
		-> Humano vs Humano, donde cada jugador ingresa manualmente sus jugadas
		-> Humano vs Computador, donde el jugador humano ingresa manualmente sus jugadas y la jugada del computador se obtiene mediante c�lculos
		-> Computador vs Computador, donde ambos jugadores son manejados por la computadora
		   (en este caso, las jugadas se muestran de una en una cada vez que se toca una tecla en la consolta)
*/

using namespace std;

class Partida{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Tablero* tablero;
		Jugador* jugador1;
		Jugador* jugador2;
		
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructor ----- */
		
		Partida();								// Constructor sin par�metros-> Crea una partida gen�rica, con un tablero vac�o y sin especificar a los jugadores
		
		/* ----- Getters ----- */
		
		Jugador* getJugador1();
		Jugador* getJugador2();
		Tablero* getTablero();
		
		/* ----- Procedimientos ----- */
		
		void HumanoVsHumano();					// Construye ambos jugadores como Humanos
		
		void HumanoVsComputador();				// Construye jugador1 como Humano y jugador2 como Computador
		
		void ComputadorVsComputador();			// Construye ambos jugadores como Computadores
		
		void mostrarDisplay();					// Funci�n que solicita la impresi�n del tablero en pantalla
		
		bool empate();							// Funci�n que valida si hay un empate en la partida
												// Retorna true si es as�, y false en caso contrario
												
		bool finPartida();						// Funci�n que valida si la partida ha terminado.
												// -> Si hay un empate, no le da la victoria a ning�n jugador y devuelve true
												// -> Si hay un ganador, devuelve true 
												// -> Si nadie ha ganado ni hay empate, devuelve false
		
		/* ----- Destructor ----- */
		
		~Partida();
	
};

#endif
