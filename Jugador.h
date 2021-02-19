#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <stdio.h>
#include <string>

#define FICHAS 21

using namespace std;

class Jugador{
	
	private:
		
		char equipo;
		int fichasRestantes;
		
		
	public:
		
		// Constructores
		Jugador(char equipo, int fichasRestantes);
		
		// Getters
		char getEquipo();
		int getFichasRestantes();
		
		// Setters
		void setEquipo(char equipo);
		void setFichasRestantes(int fichasRestantes);
		
		void mostrarFichas();
		bool sinFichas();
		void perderFicha();
	
		// Destructor
		~Jugador();
	
};

#endif
