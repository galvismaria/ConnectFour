#include "Tablero.h"

Tablero::Tablero(){
	
	for (int i = 0 ; i < ALTO ; i++){
		
		for (int j = 0 ; j < ANCHO ; j++){
			
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
	
	for (int i = ALTO ; i > 0 ; i--){
		
		if (tabla[i][columna]->getFicha() == '\0')
			return i;
	}
	
	return -1;
}

void Tablero::colocarFicha(int columna, int fila, char ficha){
	
	tabla[columna][fila] = new Casilla(ficha);
	
}

bool Tablero::enRango(int columna, int fila) {
	
	if ((columna >= 0 && columna < ANCHO) && (fila >= 0 && fila < ALTO))
		return true;
	else
		return false;
	
}

bool Tablero::conectaCuatro(int fila, int columna) {
	
	bool conectados = false;
	
	int i = 0;
	
	while ( i < 4 && !conectados){
		
		if ( enLinea (fila, columna, i) > 4)
			conectados == true;
			
		else
			i++;
	}
	
	return conectados;
}

bool Tablero::casillaOcupada(int fila, int columna){
	
	if (tabla[fila][columna]->getFicha() == 'a' || tabla[fila][columna]->getFicha() == 'b')
		return true;
	else
		return false;
}

int Tablero::enLinea(int fila, int columna, int direccion) {
	
	int seguidos = 1;
	
	int i = fila + coordFilas[direccion];
	int j = columna + coordColumnas[direccion];
	
	while (enRango(i, j) && (tabla[fila][columna]->getFicha() == tabla[i][j]->getFicha())){
		
		seguidos++;
		
		i = i + coordFilas[direccion];
		j = j + coordColumnas[direccion];
	}
	
	i = fila - coordFilas[direccion];
	j = columna - coordColumnas[direccion];
	
	while (enRango(i, j) && (tabla[fila][columna]->getFicha() == tabla[i][j]->getFicha())){
		
		seguidos++;
		
		i = i - coordFilas[direccion];
		j = j - coordColumnas[direccion];
	}
	
	return seguidos;
}
