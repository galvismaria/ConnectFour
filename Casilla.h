#ifndef CASILLA_H
#define CASILLA_H

#include "Global.h"

using namespace std;

/*

	Clase que representa cada casilla que puede ser ocupada.
	Una casilla puede tener uno de los siguientes valores:
		'\0', que significa que la casilla est� vac�a
		'X', que significa que la casilla est� ocupada por una ficha del Jugador 1
		'O', que significa que la casilla est� ocupada por una ficha del Jugador 2

*/

class Casilla{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		char ficha;
		bool conectado;
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
		
		Casilla(); 						// Constructor sin par�metros -> Crea una casilla que no est� ocupada por ninguna ficha
		Casilla(char ficha); 			// Constructor con par�metros -> Crea una casilla ocupada por una ficha
		
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
