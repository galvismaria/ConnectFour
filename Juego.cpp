#include "Juego.h"

Juego::Juego(){
	partida = NULL;
}

void Juego::menuPrincipal(){
	
	int opcion;
	bool conf =  false;
	
	cout << "\n\t\t\t\tC O N N E C T  4 \n\n\t\t\t 1. Humano vs Humano\n\n\t\t\t 2. Humano vs Computadora   \n\n\t\t\t 3. Computadora vs Computadora\n\n\t\t\t 4. Salir\n\n";
	
		while ( conf == false ) 
		{
			
			cin >> opcion;
			
			if ((opcion >= 1) && (opcion <= 4)) 
				conf = true;
				
			else
			{
				cout << "Error, intente de nuevo.\n";
				cin.clear();
				cin.ignore(200, '\n');	
			}
		}
		
		switch (opcion) 
		{
			case(1):
				partida = new Partida();
				partida->HumanoVsHumano();
				iniciarPartida(); 						
				break;
			case(2):
				partida = new Partida();
				partida->HumanoVsComputador();

				iniciarPartida(); 
				break;						
			case(3):
				partida = new Partida();
				partida->ComputadorVsComputador();
				iniciarPartida(); 					
				break;
			case(4):
				salir();					
				break;
			default:
				break;
		}
		
}

void Juego::iniciarPartida(){
	
	partida->mostrarDisplay();
	
	while(!partida->finPartida()){
		while (!jugarTurnoDe(partida->getJugador1()));
		while (!jugarTurnoDe(partida->getJugador2()));
	}
	
	
	if (partida->getJugador1()->esGanador()){
		cout<<"\n\t\t\t¡El ganador es el Jugador 1!\n\t\t\t";	
	}
	
	if (partida->getJugador2()->esGanador()){
		cout<<"\n\t\t\t¡El ganador es el Jugador 2!\n\t\t\t";	
	}
	
	if (partida->empate()){
		cout << "\n\t\t\t¡Es un empate!";
	}
	
	
	cout << "\n\n\t\t\tFin del Juego\n\n\t\t\t";
	system("pause");
	system("cls");
	menuPrincipal();
}

bool Juego::jugarTurnoDe(Jugador* jugador){
	
	partida->mostrarDisplay();
	
	if (jugador->esComputador()){
		jugador->setTableroActual(partida->getTablero());	
	}
	
	cout << endl;
	
	partida->getJugador1()->mostrarFichas();
	partida->getJugador2()->mostrarFichas();
	
	int columna;
	bool flag = false;
	
	while(!partida->finPartida()){
		
		cout << "\n\t\t\tTurno de ";
		if (jugador->getEquipo() == JUGADOR_1){
			cout << "Jugador 1";
		}
		
		if (jugador->getEquipo() == JUGADOR_2){
			cout << "Jugador 2";
		}
		
		
		cout << "\n\n\t\t\tColocar ficha en columna: ";
		columna = jugador->movimiento();
		
		if (columna >= 0 && columna < 7){
			
			if (partida->getTablero()->hacerMovimiento(columna, jugador->getEquipo())){
				jugador->perderFicha();
				return true;
			}
			
			else {
				cout << "\n\t\t\tMovimiento invalido\n\n";
				system("pause");
				return false;
			}
		} 
		
		else {
			cout << "\n\t\t\tError, intente de nuevo.\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	
	return true;
	
}
		
void Juego::salir() 
	{
		exit(0);
	}
	
Juego::~Juego(){
	delete [] partida;
}
