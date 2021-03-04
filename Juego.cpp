#include "Juego.h"

Juego::Juego(){
	partida = NULL;
}

void Juego::menuPrincipal(){
	
	while (true){
		
	int opcion = 0;
	bool conf =  false;
	
	
	cout << "\n\n\n\n" <<
			"\t..######...#######..##....##.##....##.########..######..########....##.......\n"<<
			"\t.##....##.##.....##.###...##.###...##.##.......##....##....##.......##....##.\n"<<
			"\t.##.......##.....##.####..##.####..##.##.......##..........##.......##....##.\n"<<
			"\t.##.......##.....##.##.##.##.##.##.##.######...##..........##.......##....##.\n"<<
			"\t.##.......##.....##.##..####.##..####.##.......##..........##.......#########\n"<<
			"\t.##....##.##.....##.##...###.##...###.##.......##....##....##.............##.\n"<<
			"\t..######...#######..##....##.##....##.########..######.....##.............##.\n";
	
	cout << "\n\n\n\n\t\t\t\tElije el tipo de partida:";
	
	cout << "\n\n\t\t1. MODALIDAD CLASICA"<<
			"\n\t\t~El ganador de la partida sera\n\t\tel primer jugador que complete una secuencia de cuatro fichas~"<<
			"\n\n\n\t\t2. MODALIDAD ESPECIAL"<<
			"\n\t\t~El ganador de la partida sera\n\t\tel jugador que complete mas secuencias de cuatro fichas~"<<
			"\n\n\t\t3. SALIR DEL JUEGO\n\n";
	
	while ( conf == false ) {
			
			cin >> opcion;
			
			if ( (opcion >= 1) && (opcion <= 3) ) 
				conf = true;
				
			else{
				cout << "Error, intente de nuevo.\n";
				cin.clear();
				cin.ignore(200, '\n');	
			}
		}
		
		switch (opcion) {
			
			case(1):
				
				elegirModoJuego();
				iniciarPartidaClasica();						
				break;
				
			case(2):
				
				elegirModoJuego();
				iniciarPartidaModificada();
				break;	
				
			case(3):
				salir();			
				
			default:
				break;
		}
		
	}
		
}

void Juego::elegirModoJuego(){
	
	system("cls");
	
	int opcion = 0;
	bool conf =  false;
	
	cout << "\n\n\n\n" <<
			"\t..######...#######..##....##.##....##.########..######..########....##.......\n"<<
			"\t.##....##.##.....##.###...##.###...##.##.......##....##....##.......##....##.\n"<<
			"\t.##.......##.....##.####..##.####..##.##.......##..........##.......##....##.\n"<<
			"\t.##.......##.....##.##.##.##.##.##.##.######...##..........##.......##....##.\n"<<
			"\t.##.......##.....##.##..####.##..####.##.......##..........##.......#########\n"<<
			"\t.##....##.##.....##.##...###.##...###.##.......##....##....##.............##.\n"<<
			"\t..######...#######..##....##.##....##.########..######.....##.............##.\n";
			
	cout << "\n\n\n\n\t\t\t\tElije el modo de juego:";
	
	cout << "\n\n\t\t1. Humano vs Humano\n\n\t\t2. Humano vs Computadora   \n\n\t\t3. Computadora vs Computadora\n\n\t\t4. Salir del juego\n\n";
	
	while ( conf == false ) {
			
		cin >> opcion;
			
		if ( (opcion >= 1) && (opcion <= 4) ) 
			conf = true;
				
		else{
			cout << "Error, intente de nuevo.\n";
			cin.clear();
			cin.ignore(200, '\n');	
		}
	}
		
	switch (opcion) {
			
		case(1):
				
			partida = new Partida();
			partida->HumanoVsHumano();						
			return;
				
		case(2):
				
			partida = new Partida();
			partida->HumanoVsComputador();
			return;	
									
		case(3):
				
			partida = new Partida();
			partida->ComputadorVsComputador();					
			return;
				
		case(4):
			salir();
			return;			
				
		default:
			break;
		}
	
}
		


void Juego::iniciarPartidaClasica(){
	
	partida->mostrarDisplay();
	
	do{
		do{
		}while ( !jugarTurnoDe(partida->getJugador1()) );
		
		do{
		}while ( !jugarTurnoDe(partida->getJugador2()) );
		
	}while(!partida->finPartida());
	
	
	if ( partida->getJugador1()->esGanador() ){
		cout<<"\n\t\t\t¡El ganador es el Jugador 1!\n\t\t\t";	
	}
	
	if ( partida->getJugador2()->esGanador() ){
		cout<<"\n\t\t\t¡El ganador es el Jugador 2!\n\t\t\t";	
	}
	
	if ( partida->empate() ){
		cout << "\n\t\t\t¡Es un empate!";
	}
	
	
	cout << "\n\n\t\t\tFin del Juego\n\n\t\t\t";
	system("pause");
	system("cls");
	return;
}

bool Juego::jugarTurnoDe(Jugador* jugador){
	
	partida->mostrarDisplay();
	
	if ( jugador->esComputador() ){
		jugador->setTableroActual(partida->getTablero());	
	}
	
	partida->getJugador1()->mostrarFichas();
	partida->getJugador2()->mostrarFichas();
	
	int columna;
	bool flag = false;
	
	while( !partida->finPartida() ){
		
		cout << "\n\t\t\tTurno de ";
		
		if ( jugador->getEquipo() == JUGADOR_1 ){
			cout << "Jugador 1";
		}
		
		if ( jugador->getEquipo() == JUGADOR_2 ){
			cout << "Jugador 2";
		}
		
		cout << "\n\n\t\t\tColocar ficha en columna: ";
		
		columna = jugador->movimiento();
		
		if ( columna >= 0 && columna < 7 ){
			
			if ( partida->getTablero()->hacerMovimiento(columna, jugador->getEquipo()) ){
				
				partida->mostrarDisplay();
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

bool Juego::jugarTurnoModificado(Jugador* jugador){
	
	partida->mostrarDisplay();
	
	if ( jugador->esComputador() ){
		jugador->setTableroActual(partida->getTablero());	
	}
	
	partida->getJugador1()->mostrarFichas();
	partida->getJugador1()->mostrarPuntos();
	partida->getJugador2()->mostrarFichas();
	partida->getJugador2()->mostrarPuntos();
	
	int columna;
	bool flag = false;
	
	while( !partida->finPartidaModificada() ){
		
		cout << "\n\t\t\tTurno de ";
		
		if ( jugador->getEquipo() == JUGADOR_1 ){
			cout << "Jugador 1";
		}
		
		if ( jugador->getEquipo() == JUGADOR_2 ){
			cout << "Jugador 2";
		}
		
		cout << "\n\n\t\t\tColocar ficha en columna: ";
		
		columna = jugador->movimiento();
		
		if ( columna >= 0 && columna < 7 ){
			
			if ( partida->getTablero()->hacerMovimiento(columna, jugador->getEquipo()) ){
				
				partida->mostrarDisplay();
				jugador->perderFicha();
				
				if ( partida->getTablero()->conectaCuatro(jugador->getEquipo()) ){
					
					jugador->setPuntos( partida->getTablero()-> contarSecuencias(jugador->getEquipo() ) );
					
				}
				
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


void Juego::iniciarPartidaModificada(){
	
	partida->mostrarDisplay();
	
	do{
		do{
		}while ( !jugarTurnoModificado(partida->getJugador1()) );
		
		do{
		}while ( !jugarTurnoModificado(partida->getJugador2()) );
		
	}while(!partida->finPartidaModificada());
	
	
	if ( partida->getJugador1()->esGanador() ){
		cout<<"\n\t\t\t¡El ganador es el Jugador 1!\n\t\t\t";	
	}
	
	if ( partida->getJugador2()->esGanador() ){
		cout<<"\n\t\t\t¡El ganador es el Jugador 2!\n\t\t\t";	
	}
	
	if ( partida->empate() ){
		cout << "\n\t\t\t¡Es un empate!";
	}
	
	
	cout << "\n\n\t\t\tFin del Juego\n\n\t\t\t";
	
	system("pause");
	system("cls");
	
	return;
}
		
void Juego::salir(){
	exit(0);
}
	
Juego::~Juego(){
	delete [] partida;
}
