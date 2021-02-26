#ifndef JUEGO_H
#define JUEGO_H

#include "Partida.h"
#include "Global.h"

using namespace std;

/*
	Clase encargada del manejo del juego.
	Hay tres opciones de juego:
		-> Humano vs Humano, donde cada jugador ingresa manualmente sus jugadas.
		-> Humano vs Computador, donde el jugador humano ingresa manualmente sus jugadas y la jugada del computador se obtiene mediante c�lculos.
		-> Computador vs Computador, donde ambos jugadores son manejados por la computadora (en este caso, las jugadas se muestran de una en una cada vez que se toca una tecla en la consolta).
*/

class Juego{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Partida* partida;					 		// Instancia de la partida en curso
		
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructor ----- */
		
		Juego();									// Constructor sin par�metros
		
		/* ----- Procedimientos ----- */
		
		void menuPrincipal();						// Funci�n que muestra el men� principal del juego, dejando ver las opciones de juego.
													// En esta pantalla principal, el usuario puede:
													// -> Ingresar (1) para seleccionar la modalidad Humano vs Humano
													// -> Ingresar (2) para seleccionar la modalidad Humano vs Computadora
													// -> Ingresar (3) para seleccionar la modalidad Computadora vs Computadora
													// -> Ingresar (4) para salir
													// Cabe destacar que cada vez que se concluya una partida, se regresa a este men�.
													
		void iniciarPartida();						// Funci�n que inicia la partida y controla los turnos de los jugadores.
													// Gracias al polimorfismo, el esta funci�n funciona para cualquier tipo de partida.
													// Se encarga de mostrar el tablero, y entrega turnos a los jugadores hasta que haya victoria o empate.
													
		bool jugarTurnoDe(Jugador* jugador);		// Funci�n que controla el turno del jugador que sea pasado como par�metro.
													// Gracias al polimrfismo, esta funci�n funciona para un Humano o Computador.
													// En la funci�n se llama a la funci�n movimiento() que es sobreecrita en las clases Humano y Computador,
													// se valida que el movimientosea v�lido y si no lo es, se vuelve a solicitar.
													// Si el movimiento se realiza correctamente retorna true, sino retorna false
													
		void salir();								// Funci�n que pone fin al programa
		
		/* ----- Destructor ----- */
		
		~Juego();
	
};

#endif
