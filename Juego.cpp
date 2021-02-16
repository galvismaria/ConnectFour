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
		}
		
}

void Juego::iniciarPartida(){
	partida = new Partida();
	
	partida->mostrarDisplay();
}
	
	
		
void Juego::salir() 
	{
		exit(0);
	}
