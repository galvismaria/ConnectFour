#include "Tablero.h"

Tablero::Tablero(){
	
	for (int i = 0 ; i < ANCHO ; i++){
		
		for (int j = 0 ; j < ALTO ; j++){
			
			tabla[i][j] = new Casilla();
			
		}
	}
}
