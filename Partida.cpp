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
	jugador2 = new Computador(JUGADOR_2);
}

void Partida::ComputadorVsComputador(){
	jugador1 = new Computador(JUGADOR_1);
	jugador2 = new Computador(JUGADOR_2);
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
	if ((jugador1->sinFichas() && jugador2->sinFichas()) && (jugador1->getPuntaje() == jugador2->getPuntaje()))
		return true;
		
	else
		return false;
}

bool Partida::finPartida(){
	
	bool flag;
	
	for ( int i = 0 ; i < COLUMNAS ; i++ )
		if (tablero->columnaLlena(i))
			flag = true;
		else 
			flag = false;
	
	if (flag){
		
		if (empate()){
			jugador1->setResultado(false);
			jugador2->setResultado(false);
			return true;
		}
		
		if (jugador1->getPuntaje() > jugador2->getPuntaje()){
			jugador1->setResultado(true);
			return true;
		}
		
		if (jugador2->getPuntaje() > jugador1->getPuntaje()){
			jugador2->setResultado(true);
			return true;
		}
	
		else
			return false;
		
	}

}

Partida::~Partida(){
	delete [] tablero;
	delete [] jugador1;
	delete [] jugador2;
}
