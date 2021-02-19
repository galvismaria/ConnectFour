#include "Partida.h"

Partida::Partida(){
	tablero = new Tablero();
	jugadorA = new Jugador('a', FICHAS);
	jugadorB = new Jugador('b', FICHAS);
}

Jugador* Partida::getJugadorA(){
	return jugadorA;
}

Jugador* Partida::getJugadorB(){
	return jugadorB;
}

Tablero* Partida::getTablero(){
	return tablero;
}

void Partida::mostrarDisplay(){
	
	system("cls");
	
	tablero->mostrarTabla();
	
}

bool Partida::empate(){
	if ((jugadorA->sinFichas() & jugadorB->sinFichas()) && (!tablero->conectaCuatro(jugadorA->getEquipo()) && !tablero->conectaCuatro(jugadorB->getEquipo())))
		return true;
		
	else
		return false;
}

bool Partida::finPartida(){
	
	if (tablero->conectaCuatro(jugadorA->getEquipo())){
		cout<<"\n\t\t\t¡El ganador es el Equipo X!\n\t\t\t";
		return true;
	}
	
	if (tablero->conectaCuatro(jugadorB->getEquipo())){
		cout<<"\n\t\t\t¡El ganador es el Equipo O!\n\t\t\t";
		return true;
	}
		
	else
		return false;
}

Partida::~Partida(){
	delete [] tablero;
	delete [] jugadorA;
	delete [] jugadorB;
}
