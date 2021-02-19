#include "Tablero.h"

Tablero::Tablero(){
	
	for (int i = 0 ; i < FILAS ; i++){
		
		for (int j = 0 ; j < COLUMNAS ; j++){
			
			tabla[i][j] = new Casilla();
			
		}
	}
}

void Tablero::mostrarTabla(){
	
	cout << "\n\t\t\t\t | 1 | | 2 | | 3 | | 4 | | 5 | | 6 | | 7 | \n";
	
	for (int i =  0 ; i < FILAS ; i++){
		cout <<"\t\t\t\t";
		
		for (int j = 0 ; j < COLUMNAS; j++){
			
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
	
	for (int i = FILAS-1 ; i >= 0 ; i--){
		
		if (tabla[i][columna]->getFicha() == '\0'){
			return i;
		
		}
	}
	
	return -1;
	
}

void Tablero::colocarFicha(int fila, int columna, char ficha){
	
	tabla[fila][columna]->setFicha(ficha);
	
}

bool Tablero::enRango(int fila, int columna) {
	
	if ((columna >= 0 && columna < COLUMNAS) && (fila >= 0 && fila < FILAS))
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
    for (int j = 0; j < COLUMNAS - 3 ; j++ ){
        for ( int i = 0; i < FILAS ; i++ ){
            if ( tabla[i][j]->getFicha() == equipo && tabla[i][j+1]->getFicha() == equipo && tabla[i][j+2]->getFicha() == equipo && tabla[i][j+3]->getFicha() == equipo ){
                return true;
            }           
        }
    }
    // verticalCheck
    for ( int i = 0; i < FILAS-3 ; i++ ){
        for ( int j = 0; j < COLUMNAS ; j++ ){
            if ( tabla [i][j]->getFicha() == equipo && tabla[i+1][j]->getFicha() == equipo && tabla[i+2][j]->getFicha() == equipo && tabla[i+3][j]->getFicha() == equipo ){
                return true;
            }           
        }
    }
    // ascendingDiagonalCheck 
    for ( int i = 3; i < FILAS ; i++ ){
        for ( int j = 0; j < COLUMNAS - 3; j++ ){
            if ( tabla[i][j]->getFicha() == equipo && tabla[i-1][j+1]->getFicha() == equipo && tabla[i-2][j+2]->getFicha() == equipo && tabla[i-3][j+3]->getFicha() == equipo )
                return true;
        }
    }
    // descendingDiagonalCheck
    for ( int i=3; i < FILAS ; i++ ){
        for ( int j = 3 ; j < COLUMNAS ; j++ ){
            if ( tabla [i][j]->getFicha() == equipo && tabla [i-1][j-1]->getFicha() == equipo && tabla[i-2][j-2]->getFicha() == equipo && tabla[i-3][j-3]->getFicha() == equipo)
                return true;
        }
    }
    return false;
}

bool Tablero::hacerMovimiento(int columna, char ficha){
	
	int fila = obtenerFilaDesocupada(columna);
	
	
	if (fila == -1){
		return false;
	}
	
	if (enRango(fila, columna)){
		colocarFicha(fila, columna, ficha);
		return true;
	}
	
	return false;
	
}

Tablero::~Tablero(){
	;
}
