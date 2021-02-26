#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include "Global.h"
#include "Tablero.h"
#include "Jugador.h"

using namespace std;

/*

	La clase Computador es una especialización de la clase Jugador,
	que representa a un posible jugador manejado por la computadora.
	
	Computador tiene en sus atributos una copia del Tablero que se actualiza en cada turno.
	En esta clase se implementan métodos que ayudan a la computadora a elegir su movimiento
	(es decir, seleccionar una columna donde depositar su ficha).
	
	Cabe destacar que el Computador al ser una especialización de Jugador, tiene asignado un equipo ('X' u 'O'),
	una cantidad de fichas y un indicador para saber si es el ganador de la partida.
	

*/

class Computador : public Jugador{

	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Tablero *estadoActual; 											// Tablero que copia el estado actual de la partida
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructor ----- */
		
		Computador(char equipo); 										// Constructor con parámetros -> Crea un jugador Computador
																		// Se inicializa el tablero y se llama al constructor de la clase padre
																		// para asignar el equipo, la cantidad inicial de fichas y el estado de victoria
		
		/* ----- Setter ----- */
			
		void setTableroActual(Tablero *actual);
		
		/* ----- Procedimientos ----- */
		
		void copiarTablero(Tablero *origen, Tablero *destino); 			// Función para crear una copia del tablero,
															  			// de modo que no se modifique el estado actual de la partida
															  			// cuando el Computador "piense" qué jugada realizar
															   
		int buscarColumnaGanadora(char equipo);				  		    // Función que analiza si en el estado actual del tablero
															  		    // puede realizarse un movimiento que le de la victoria inmediata.
															   			// Si ese es el caso, retorna el índice de la columna;
															   			// en caso contrario, retorna -1
															   
		int buscarUltimaFila(int columna);					   			// Función para obtener la última ficha colocada en una columna.
															  			// Retorna el índice de la fila.
		
		void buscarMejorColumna(char equipo, int *conteo, int *indice); // Función que busca en qué columna se puede obtener la mayor cantidad
																		// de fichas conectadas.
																		// En la variable "conteo" se guarda la cantidad de fichas que se conectan
																		// y en la ficha "índice" se guarda el ínidice de la columna
																		
		int randomEnRango(int minimo, int maximo);						// Función que obtiene un número aleatorio, en el rango de las columnas del tablero
		
		int buscarColumnaRandom(char equipo);							// Función que obtiene una columna aleatoria donde se pueda realizar un movimiento
		
		int buscarColumnaCentral(char equipo);							// Función que obtiene la columna central del tablero
		
		int elegirColumna(char equipo, char oponente); 					// Función que elige la mejor columna para jugar. Estas son las evaluaciones que realiza,
																		// en orden de prioridad:
																		 
																		// -> Busca una columna que pueda proporcionar la victoria inmediata.
																		// -> Busca una columna donde el oponente pueda ganar en el siguiente turno, y lo bloquea
																		// -> Busca una columna donde el oponente tenga una gran cantidad de fichas conectadas y lo bloquea
																		// -> Busca una columna donde el mismo pueda obtener una mayor cantidad de fichas acumuladas
																		// -> Busca la columna central del tablero
																		// -> Busca una columna aleatoria
																		
		int movimiento(); 												// Función que sobreescribe la función abstracta pura definida en la clase Jugador.
																		// En esta función se realiza la llamada a la función elegirColumna()
																		
		bool esComputador(); 											// Siempre retorna true, se usa para saber si el jugador es una Computadora
		
		/* ----- Destructor ----- */
		
		~Computador();
		
};

#endif
