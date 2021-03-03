#ifndef JUGADOR_H
#define JUGADOR_H


#include "Global.h"
#include "Tablero.h"

using namespace std;

/*
	Clase abstracta que sirve como base para crear al jugador, así que no se crean instancias de esta clase.
	A partir de esta clase se crean las especializaciones Computador y Humano.
	Gracias a esta clase, es posible aplicar polimorfismo para escribir funciones que funcionen para un Humano o un Computador,
	como por ejemplo las funciones en la clase Juego que controlan los turnos de los jugadores y el progreso de la partida.
*/

class Jugador{
	
	protected:
		
		/* ----- ATRIBUTOS ----- */
		
		char equipo;
		int fichasRestantes;
		bool ganador;
		int puntaje;
		
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructor ----- */
		
		Jugador(char equipo);
		
		/* ----- Setters ----- */
		
		void setEquipo(char equipo);
		void setFichasRestantes(int fichasRestantes);
		void setResultado(bool resultado);
		void setPuntaje(int puntaje);
		
		/* ----- Getters ----- */
		
		char getEquipo();
		int getFichasRestantes();
		int getPuntaje();
		bool esGanador();
		
		/* ----- Procedimientos ----- */
		
		char getOponente();											// Función que permite obtener el equipo del oponente
																	// Ya que en el juego existen dos jugadores, se sobreentiende
																	// que si un jugador tiene asignado el equipo (X), su oponente tiene asignado el equipo (O)
																	// y viceversa.
																	
		void mostrarFichas();										// Función que muestra la cantidad de fichas restantes del jugador
		
		void mostrarPuntaje();
		
		bool sinFichas();											// Función que retorna true si el jugador se ha quedado sin fichas
																	// y false si todavía hay fichas que puede utilizar
																	
		void perderFicha();											// Función que le quita una ficha al jugador
		
		void sumarPunto();
		
		virtual int movimiento() = 0;								// Función virtual pura, que se sobreescribe en las clases Humano y Computador
																	// de la forma en que sea necesario en cada caso
																	
		virtual bool esComputador() = 0;							// Función virtual pura, se sobreescribe en las clases hijas para saber si el jugador es Computador o no
	
		virtual void setTableroActual (Tablero *original) = 0;		// Función virtual pura, se sobreescribe en la clase Computador para fijar el estado actual del tablero
	
		/* ----- Destructor ----- */
		
		~Jugador();
	
};

#endif
