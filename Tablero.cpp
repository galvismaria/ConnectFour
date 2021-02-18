#include "Tablero.h"

Tablero::Tablero(){
	
	for (int i = 0 ; i < ANCHO ; i++){
		
		for (int j = 0 ; j < ALTO ; j++){
			
			tabla[i][j] = new Casilla();
			
		}
	}
}

void Tablero::mostrarTabla(){
	
	cout << "\n\t\t\t\t | 1 | | 2 | | 3 | | 4 | | 5 | | 6 | | 7 | \n";
	
	for (int i =  0 ; i < ALTO ; i++){
		cout <<"\t\t\t\t";
		for (int j = 0 ; j < ANCHO; j++){
			
			if (tabla[i][j]->getFicha() == '\0')
			
				cout << " |   |";
				
			if (tabla[i][j]->getFicha() == 'a')
			
				cout << " | X |";
				
			if (tabla[i][j]->getFicha() == 'b')
			
				cout << " | O |";
		}
		
		cout <<"\t\t\t\t\n";
	}
	
}

int Tablero::obtenerFilaDesocupada(int columna){
	
	cout << "tt";
	
	for (int i = ALTO-1 ; i >= 0 ; i--){
		
		if (tabla[i][columna]->getFicha() == '\0'){
			return i;
		
		}
	}
	
	return -1;
	
}

void Tablero::colocarFicha(int fila, int columna, char ficha){
	
	tabla[fila][columna] = new Casilla(ficha);
	
}

bool Tablero::enRango(int fila, int columna) {
	
	if ((columna >= 0 && columna < ANCHO) && (fila >= 0 && fila < ALTO))
		return true;
	else
		return false;
	
}

bool Tablero::casillaOcupada(int fila, int columna){
	
	if (tabla[fila][columna]->getFicha() == 'a' || tabla[fila][columna]->getFicha() == 'b')
		return true;
	else
		return false;
}

bool Tablero::conectaCuatro(char equipo){

    // horizontal Check 
    for (int j = 0; j < ALTO - 3 ; j++ ){
        for ( int i = 0; i < ANCHO ; i++ ){
            if ( tabla[i][j]->getFicha() == equipo && tabla[i][j+1]->getFicha() == equipo && tabla[i][j+2]->getFicha() == equipo && tabla[i][j+3]->getFicha() == equipo ){
                return true;
            }           
        }
    }
    // verticalCheck
    for ( int i = 0; i < ANCHO-3 ; i++ ){
        for ( int j = 0; j < ALTO ; j++ ){
            if ( tabla [i][j]->getFicha() == equipo && tabla[i+1][j]->getFicha() == equipo && tabla[i+2][j]->getFicha() == equipo && tabla[i+3][j]->getFicha() == equipo ){
                return true;
            }           
        }
    }
    // ascendingDiagonalCheck 
    for ( int i = 3; i < ANCHO ; i++ ){
        for ( int j = 0; j < ALTO - 3; j++ ){
            if ( tabla[i][j]->getFicha() == equipo && tabla[i-1][j+1]->getFicha() == equipo && tabla[i-2][j+2]->getFicha() == equipo && tabla[i-3][j+3]->getFicha() == equipo )
                return true;
        }
    }
    // descendingDiagonalCheck
    for ( int i=3; i < ANCHO ; i++ ){
        for ( int j = 3 ; j < ALTO ; j++ ){
            if ( tabla [i][j]->getFicha() == equipo && tabla [i-1][j-1]->getFicha() == equipo && tabla[i-2][j-2]->getFicha() == equipo && tabla[i-3][j-3]->getFicha() == equipo)
                return true;
        }
    }
    return false;
}

void Tablero::hacerMovimiento(int columna, char ficha){
	
	columna--;
	int fila = obtenerFilaDesocupada(columna);
	
	if (fila == -1){
		cout << "Error";
		return;
	}
	
	if (!casillaOcupada(fila, columna) && enRango(fila, columna)){
		colocarFicha(fila, columna, ficha);
	}
	
	return;
	
}

Tablero::~Tablero(){
	;
}
