#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Jugador{
	
	private:
		
		char equipo;
		int fichasRestantes;
		
		
	public:
		
		Jugador();
		void mostrarFichas();
		~Jugador();
	
};

#endif
