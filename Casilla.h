#ifndef CASILLA_H
#define CASILLA_H

#include "Global.h"

using namespace std;

/*

	Clase que representa cada casilla que puede ser ocupada.
	Una casilla puede tener uno de los siguientes valores:
		'\0', que significa que la casilla está vacía
		'X', que significa que la casilla está ocupada por una ficha del Jugador 1
		'O', que significa que la casilla está ocupada por una ficha del Jugador 2

*/

class Casilla{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		char ficha;
		bool conectado;
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Casilla(); 						// Constructor sin parámetros -> Crea una casilla que no está ocupada por ninguna ficha
		Casilla(char ficha); 			// Constructor con parámetros -> Crea una casilla ocupada por una ficha
		
		/* ----- Setter ----- */
		
		void setFicha(char ficha);
		void conectar(bool conectado);
		
		/* ----- Getter ----- */
		
		char getFicha();
		bool estaConectado();
		
		/* ----- Procedimientos ----- */
		
		
		
		/* ----- Destructor ----- */
		
		~Casilla();
	
};

#endif
