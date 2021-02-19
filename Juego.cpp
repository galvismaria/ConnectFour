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
				iniciarPartida(); 						
				break;
			case(2):
				break;						
			case(3):					
				break;
			case(4):
				salir();					
				break;
			default:
				break;
		}
		
}

void Juego::iniciarPartida(){
	partida = new Partida();
	
	partida->mostrarDisplay();
	
	while (true) 
			{
				while (!jugarTurnoDe(partida->getJugadorA()));
				while (!jugarTurnoDe(partida->getJugadorB()));
			}
			cout << "\n\n\tEL JUEGO HA TERMINADO\n";
			system("pause");
			system("cls");
			menuPrincipal();
}
	
bool Juego::jugarTurnoDe(Jugador* jugador){
	
	partida->mostrarDisplay();
	
	cout << endl;
	
	partida->getJugadorA()->mostrarFichas();
	partida->getJugadorB()->mostrarFichas();
	
	int columna;
	
	while(true){

		if (partida->finPartida()){
			system("pause");
			salir();
		}
		
		cout << "\n\t\t\tTurno de ";
		if (jugador->getEquipo() == 'a'){
			cout << "Equipo X";
		}
		
		if (jugador->getEquipo() == 'b'){
			cout << "Equipo O";
		}
		
		cout << "\n\n\t\t\tColocar ficha en columna: ";
		cin >> columna;
		columna = columna-1;
		
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
	
}
		
void Juego::salir() 
	{
		exit(0);
	}
	
Juego::~Juego(){
	delete [] partida;
}
