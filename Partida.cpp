#include "Partida.h"

Partida::Partida(){
	tablero = new Tablero();
	jugadorA = new Jugador();
	jugadorB = new Jugador();
}

void Partida::mostrarDisplay(){
	
	system("cls");
	tablero->mostrarTabla();
	tablero->colocarFicha(0, 0, 'a');
	tablero->colocarFicha(0, 1, 'a');
	tablero->colocarFicha(0, 2, 'a');
	tablero->colocarFicha(0, 3, 'a');
	tablero->colocarFicha(0, 4, 'a');

	system("cls");
	tablero->mostrarTabla();
	
		if (tablero->conectaCuatro(0, 0))
		cout<<"\n\n en linea";
		
		else
		cout<<"\n\n no linea";
}
