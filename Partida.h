#ifndef PARTIDA_H
#define PARTIDA_H

#include "Tablero.h"
#include "Jugador.h"
#include "Computador.h"
#include "Humano.h"
#include "Global.h"

/*
	Clase encargada de crear la partida.
	Hay dos modalidades de juego:
		-> Modalidad clásica, donde el ganador es el primer jugador en una secuencia de cuatro en línea.
		-> Modalidad especial, donde la partida acaba cuando el tablero está lleno y el ganador es el jugador con más secuencias completadas.
	
	Hay tres formas de las que se pueden inicializar los atributs de la partida:
		-> Humano vs Humano, donde cada jugador ingresa manualmente sus jugadas
		-> Humano vs Computador, donde el jugador humano ingresa manualmente sus jugadas y la jugada del computador se obtiene mediante cálculos
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
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructor ----- */
		
		Partida();								// Constructor sin parámetros-> Crea una partida genérica, con un tablero vacío y sin especificar a los jugadores
		
		/* ----- Getters ----- */
		
		Jugador* getJugador1();
		Jugador* getJugador2();
		Tablero* getTablero();
		
		/* ----- Procedimientos ----- */
		
		void HumanoVsHumano();					// Construye ambos jugadores como Humanos
		
		void HumanoVsComputador();				// Construye jugador1 como Humano y jugador2 como Computador
		
		void ComputadorVsComputador();			// Construye ambos jugadores como Computadores
		
		void mostrarDisplay();					// Función que solicita la impresión del tablero en pantalla
		
		bool empate();							// Función que valida si hay un empate en la partida
												// Retorna true si es así, y false en caso contrario
																				
		bool finPartida();						// Función que valida si una partida de modalidad clasica ha terminado.
												// La partida se finaliza cuando un jugador realiza un cuatro en linea.
												//El ganador es el jugador en realizar el cuatro en linea.
												// -> Si hay un empate, no le da la victoria a ningún jugador y devuelve true
												// -> Si hay un ganador, devuelve true 
												// -> Si nadie ha ganado ni hay empate, devuelve false
												
		bool finPartidaModificada();			// Función que valida si una partida de modalidad especial ha terminado.
												// La partida se finaliza cuando el tablero está lleno.
												// El ganador es el jugador con más secuencias de cuatro en linea.
												// -> Si hay un empate, no le da la victoria a ningún jugador y devuelve true
												// -> Si hay un ganador, devuelve true 
												// -> Si nadie ha ganado ni hay empate, devuelve false
		
		/* ----- Destructor ----- */
		
		~Partida();
	
};

#endif
