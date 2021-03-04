#ifndef HUMANO_H
#define HUMANO_H

#include "Global.h"
#include "Jugador.h"

/*

	La clase Humano es una especializaci�n de la clase Jugador,
	que representa a un jugador humano.


*/

class Humano : public Jugador{
	
	public:
		/* ----- M�TODOS ----- */
		
		/* ----- Constructor ----- */
		
		Humano(char equipo);    				// Constructor con par�metros -> Crea un Jugador Humano
												// Se llama al constructor de la clase padre para asignar el equipo,
												// la cantidad inicial de fichas y el estado de victoria
		
		/* ----- Procedimientos ----- */
		
		int movimiento();						// Funci�n que lee el movimiento del jugador, ingresado por teclado 
		
		bool esComputador();					// Siempre retorna true, se usa para saber si el jugador es una Computadora
			
		void setTableroActual(Tablero *original){};
		
		~Humano();
};

#endif
