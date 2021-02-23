#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "Global.h"
#include "Tablero.h"

using namespace std;

class Jugador{
	
	protected:
		
		char equipo;
		int fichasRestantes;
		bool ganador;
		
		
	public:
		
		// Constructores
		Jugador();
		
		// Getters
		char getEquipo();
		int getFichasRestantes();
		bool esGanador();
		
		// Setters
		void setEquipo(char equipo);
		void setFichasRestantes(int fichasRestantes);
		void setResultado(bool resultado);
		
		char getOponente();
		void mostrarFichas();
		bool sinFichas();
		void perderFicha();
		
		virtual int movimiento() = 0;
		virtual bool esComputador() = 0;
		virtual void setTableroActual (Tablero *original) = 0;
	
		// Destructor
		~Jugador();
	
};

#endif
