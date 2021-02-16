#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "Tablero.h"
#include "Jugador.h"

using namespace std;

class Partida{
	
	private:
		
		Tablero* tablero;
		Jugador* jugadorA;
		Jugador* jugadorB;
		
		
	public:
		
		Partida();
		void mostrarDisplay();
		~Partida();
	
};

#endif
