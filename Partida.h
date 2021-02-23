#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Tablero.h"
#include "Jugador.h"
#include "Computador.h"
#include "Humano.h"
#include "Global.h"

#define FICHAS 21

using namespace std;

class Partida{
	
	private:
		
		Tablero* tablero;
		Jugador* jugador1;
		Jugador* jugador2;
		
		
	public:
		// Constructores
		Partida();
		
		// Getters
		Jugador* getJugador1();
		Jugador* getJugador2();
		Tablero* getTablero();
		
		void HumanoVsHumano();
		void HumanoVsComputador();
		void ComputadorVsComputador();
		void mostrarDisplay();
		bool empate();
		bool finPartida();
		~Partida();
	
};

#endif
