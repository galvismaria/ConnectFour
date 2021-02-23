#include "Partida.h"

Partida::Partida(){
	tablero = new Tablero();
	jugador1 = NULL;
	jugador2 = NULL;
	
}

void Partida::HumanoVsHumano(){
	
	jugador1 = new Humano(JUGADOR_1);
	jugador2 = new Humano(JUGADOR_2);
}

void Partida::HumanoVsComputador(){
	jugador1 = new Humano(JUGADOR_1);
	jugador2 = new Computador(tablero, JUGADOR_2);
}

void Partida::ComputadorVsComputador(){
	jugador1 = new Computador(tablero, JUGADOR_1);
	jugador2 = new Computador(tablero, JUGADOR_2);
}

Jugador* Partida::getJugador1(){
	return jugador1;
}

Jugador* Partida::getJugador2(){
	return jugador2;
}

Tablero* Partida::getTablero(){
	return tablero;
}

void Partida::mostrarDisplay(){
	
	system("cls");
	tablero->mostrarTabla();
	
}

bool Partida::empate(){
	if ((jugador1->sinFichas() && jugador2->sinFichas()) && (!jugador1->esGanador() && !jugador2->esGanador()))
		return true;
		
	else
		return false;
}

bool Partida::finPartida(){
	
	if (empate()){
		jugador1->setResultado(false);
		jugador2->setResultado(false);
		return true;
	}
	
	jugador1->setResultado(tablero->conectaCuatro(jugador1->getEquipo()));
	jugador2->setResultado(tablero->conectaCuatro(jugador2->getEquipo()));
	
	if (jugador1->esGanador() || jugador2->esGanador())
		return true;
	
	else
		return false;
}

Partida::~Partida(){
	delete [] tablero;
	delete [] jugador1;
	delete [] jugador2;
}
