#include "Jugador.h"

Jugador::Jugador(char equipo){
	
	this->equipo = equipo;
	fichasRestantes = FICHAS;
	puntos = 0;
	ganador = false;
}

char Jugador::getEquipo(){
	return equipo;
}

int Jugador::getFichasRestantes(){
	return fichasRestantes;
}

bool Jugador::esGanador(){
	return ganador;
}

void Jugador::setEquipo(char equipo){
	this->equipo = equipo;
}

void Jugador::setFichasRestantes(int fichasRestantes){
	this->fichasRestantes = fichasRestantes;
}

void Jugador::setResultado(bool resultado){
	ganador = resultado;
}

void Jugador::setPuntos(int puntos){
	this->puntos = puntos;
}

char Jugador::getOponente(){
	
	if (this->equipo == JUGADOR_1)
		return JUGADOR_2;
	
	if (this->equipo == JUGADOR_2)
		return JUGADOR_1;
	else
		return '\0';
}

int Jugador::getPuntos(){
	return puntos;
}

void Jugador::mostrarFichas(){
	
	if(equipo == JUGADOR_1){
		cout << "\n\t\t\t(Jugador 1) ";
	}
	
	if(equipo == JUGADOR_2){
		cout << "\n\t\t\t(Jugador 2) ";
	}
	
	cout <<"Piezas restantes: "<< fichasRestantes;
	cout <<"\n\t";
}

void Jugador::mostrarPuntos(){
	
	if(equipo == JUGADOR_1){
		cout << "\n\t\t\t(Jugador 1) ";
	}
	
	if(equipo == JUGADOR_2){
		cout << "\n\t\t\t(Jugador 2) ";
	}
	
	cout <<"Puntos: "<< puntos;
	cout <<"\n\t";
}

bool Jugador::sinFichas(){
	
	if (fichasRestantes <= 0)
		return true;
		
	else
		return false;
}

void Jugador::perderFicha(){
	fichasRestantes--;
}

Jugador::~Jugador(){
	delete &equipo;
	delete &fichasRestantes;
	delete &ganador;
	delete &puntos;
}
