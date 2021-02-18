#include "Partida.h"

Partida::Partida(){
	tablero = new Tablero();
	jugadorA = new Jugador();
	jugadorB = new Jugador();
}

void Partida::mostrarDisplay(){
	
	system("cls");
	
	cout << "\n\t\t\t\t | 1 | | 2 | | 3 | | 4 | | 5 | | 6 | | 7 | \n";
	
	for (int i =  0 ; i < ALTO ; i++){
		cout <<"\t\t\t\t";
		for (int j = 0 ; j < ANCHO; j++){
			cout << " |   |";
		}
	tablero->mostrarTabla();
	tablero->colocarFicha(0, 0, 'a');
	tablero->colocarFicha(1, 1, 'a');
	tablero->colocarFicha(2, 2, 'a');
	tablero->colocarFicha(3, 3, 'a');
	tablero->colocarFicha(4, 4, 'a');

	system("cls");
	tablero->mostrarTabla();
	
		if (tablero->conectaCuatro('a'))
		cout<<"\n\n en linea";	
		cout <<"\t\t\t\t\n";
	}
	
}
