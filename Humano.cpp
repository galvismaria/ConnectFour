#include "Humano.h"

Humano::Humano(char equipo) : Jugador (equipo){
	
}

int Humano::movimiento(){
	
	int columna;
	cin >> columna;
	columna = columna-1;
	return columna;
	
}

bool Humano::esComputador(){
	return false;
}

Humano::~Humano() {
	;
}
