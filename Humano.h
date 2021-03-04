#ifndef HUMANO_H
#define HUMANO_H

#include "Global.h"
#include "Jugador.h"

/*

	La clase Humano es una especialización de la clase Jugador,
	que representa a un jugador humano.


*/

class Humano : public Jugador{
	
	public:
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructor ----- */
		
		Humano(char equipo);    				// Constructor con parámetros -> Crea un Jugador Humano
												// Se llama al constructor de la clase padre para asignar el equipo,
												// la cantidad inicial de fichas y el estado de victoria
		
		/* ----- Procedimientos ----- */
		
		int movimiento();						// Función que lee el movimiento del jugador, ingresado por teclado 
		
		bool esComputador();					// Siempre retorna true, se usa para saber si el jugador es una Computadora
			
		void setTableroActual(Tablero *original){};
		
		~Humano();
};

#endif
