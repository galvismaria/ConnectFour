#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "Partida.h"

using namespace std;

class Juego{
	
	private:
		
		Partida* partida;
		
		
	public:
		
		Juego();
		void menuPrincipal();
		void iniciarPartida();
		void salir();
		~Juego();
	
};

#endif
