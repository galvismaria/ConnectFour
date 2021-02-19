#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "Tablero.h"
#include "Jugador.h"

#define FICHAS 21

using namespace std;

class Partida{
	
	private:
		
		Tablero* tablero;
		Jugador* jugadorA;
		Jugador* jugadorB;
		
		
	public:
		// Constructores
		Partida();
		
		// Getters
		Jugador* getJugadorA();
		Jugador* getJugadorB();
		Tablero* getTablero();
		
		void mostrarDisplay();
		bool empate();
		bool finPartida();
		~Partida();
	
};

#endif
