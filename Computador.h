#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "Global.h"
#include "Tablero.h"
#include "Jugador.h"

class Computador : public Jugador{

	
	private:
		Tablero *estadoActual;
		
	public:
		Computador(char equipo);
		void setTableroActual(Tablero *actual);
		void copiarTablero(Tablero *origen, Tablero *destino);
		int getColumnaGanadora(char equipo);
		int getUltimaFila(int columna);
		void getMejorColumna(char equipo, int *conteo, int *indice);
		int randomEnRango(int minimo, int maximo);
		int getColumnaRandom(char equipo);
		int getColumnaCentral(char equipo);
		int elegirColumna(char equipo, char oponente);
		int movimiento();
		bool esComputador();
		

};

#endif
