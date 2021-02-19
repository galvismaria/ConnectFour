#include "Jugador.h"

Jugador::Jugador(char equipo, int fichasRestantes){
	this->equipo = equipo;
	this->fichasRestantes = FICHAS;
}

char Jugador::getEquipo(){
	return equipo;
}

int Jugador::getFichasRestantes(){
	return fichasRestantes;
}

void Jugador::setEquipo(char equipo){
	this->equipo = equipo;
}

void Jugador::setFichasRestantes(int fichasRestantes){
	this->fichasRestantes = fichasRestantes;
}


void Jugador::mostrarFichas(){
	
	if(equipo == 'a'){
		cout << "\n\t\t\t(Equipo X) ";
	}
	
	if(equipo == 'b'){
		cout << "\n\t\t\t(Equipo O) ";
	}
	
	cout <<"Piezas restantes: "<< fichasRestantes;
	cout <<"\n\t";
}

bool Jugador::sinFichas(){
	if (fichasRestantes >= 0)
		return true;
	else
		return false;
}

void Jugador::perderFicha(){
	fichasRestantes--;
}

Jugador::~Jugador(){
	;
}
