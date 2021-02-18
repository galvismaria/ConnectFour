#include "Partida.h"

Partida::Partida(){
	tablero = new Tablero();
	jugadorA = new Jugador();
	jugadorB = new Jugador();
}

void Partida::mostrarDisplay(){
	
	//system("cls");
	
	/*cout << "\n\t\t\t\t | 1 | | 2 | | 3 | | 4 | | 5 | | 6 | | 7 | \n";
	
	for (int i =  0 ; i < ALTO ; i++){
		cout <<"\t\t\t\t";
		for (int j = 0 ; j < ANCHO; j++){
			cout << " |   |";
		}
	}*/
	cout<<"lol";
	tablero->hacerMovimiento(2, 'a');
	cout<<"lol";
	//tablero->hacerMovimiento(1, 'a');
	tablero->mostrarTabla();
	
	if (tablero->conectaCuatro('a'))
		cout<<"\n\n en linea";	
		cout <<"\t\t\t\t\n";
	
}

Partida::~Partida(){
	delete [] tablero;
	delete [] jugadorA;
	delete [] jugadorB;
}
