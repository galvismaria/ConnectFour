#ifndef JUEGO_H
#define JUEGO_H

#include "Partida.h"
#include "Global.h"

using namespace std;

/*
	Clase encargada del manejo del juego.
	Hay dos modalidades de juego:
		-> Modalidad clásica, donde el ganador es el primer jugador en una secuencia de cuatro en línea.
		-> Modalidad especial, donde la partida acaba cuando el tablero está lleno y el ganador es el jugador con más secuencias completadas.
		
	Hay tres opciones de configurar el juego:
		-> Humano vs Humano, donde cada jugador ingresa manualmente sus jugadas.
		-> Humano vs Computador, donde el jugador humano ingresa manualmente sus jugadas y la jugada del computador se obtiene mediante cálculos.
		-> Computador vs Computador, donde ambos jugadores son manejados por la computadora (en este caso, las jugadas se muestran de una en una cada vez que se toca una tecla en la consolta).
*/

class Juego{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Partida* partida;					 		// Instancia de la partida en curso
		
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructor ----- */
		
		Juego();									// Constructor sin parámetros
		
		/* ----- Procedimientos ----- */
		
		void menuPrincipal();						// Función que muestra el menú principal del juego, dejando ver las opciones de juego.
													// En esta pantalla principal, el usuario puede:
													// -> Ingresar (1) para seleccionar la modalidad clasica de juego
													// -> Ingresar (2) para seleccionar la modalidad especial de juego
													// -> Ingresar (3) para salir
													// Cabe destacar que cada vez que se concluya una partida, se regresa a este menú.
		
		void elegirModoJuego();						// Función que permite elegir entre los siguientes modos de juego:
													// -> Ingresar (1) para seleccionar una partida Humano vs Humano
													// -> Ingresar (2) para seleccionar una partida Humano vs Computadora
													// -> Ingresar (3) para seleccionar una partida Computadora vs Computadora
											
		void iniciarPartidaClasica();				// Función que inicia la partida de modalidad clásica y controla los turnos de los jugadores.
													// Gracias al polimorfismo, el esta función funciona para cualquier tipo de partida.
													// Se encarga de mostrar el tablero, y entrega turnos a los jugadores hasta que haya victoria o empate.
													// En esta modalidad de juego, la partida acaba cuando alguno de los jugadores hace un cuatro en línea.
												
		bool jugarTurnoDe(Jugador* jugador);		// Función que controla el turno del jugador que sea pasado como parámetro.
													// Gracias al polimrfismo, esta función funciona para un Humano o Computador.
													// En la función se llama a la función movimiento() que es sobreecrita en las clases Humano y Computador,
													// se valida que el movimientosea válido y si no lo es, se vuelve a solicitar.
													// Si el movimiento se realiza correctamente retorna true, sino retorna false
		
		void iniciarPartidaModificada(); 			// Función que inicia la partida de modalidad especial del juego y controla los turnos de los jugadres.
													// Gracias al polimorfismo, el esta función funciona para cualquier tipo de partida.
													// Se encarga de mostrar el tablero, y entrega turnos a los jugadores hasta que haya victoria o empate.
													// En esta modalidad de juego, la partida acaba cuando el tablero está lleno.
													// El ganador de la partida es el jugador con mayor cantidad de secuencias de cuatro en línea.
													
		bool jugarTurnoModificado(Jugador* jugador);// Función especial para controlar el turno del jugador que sea pasado como parámetro, en la modalidad especial de juego
													// Gracias al polimrfismo, esta función funciona para un Humano o Computador.
													// En la función se llama a la función movimiento() que es sobreecrita en las clases Humano y Computador,
													// se valida que el movimientosea válido y si no lo es, se vuelve a solicitar.
													// Si el movimiento se realiza correctamente retorna true, sino retorna false
													// En cada movimiento se actualiza el puntaje del jugador aactual.
												
		void salir();								// Función que pone fin al programa
		
		/* ----- Destructor ----- */
		
		~Juego();
	
};

#endif
