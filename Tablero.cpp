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
				
			if (tabla[i][j]->getFicha() == JUGADOR_1)
				cout << " | X |";
				
			if (tabla[i][j]->getFicha() == JUGADOR_2)
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

Casilla* Tablero::getCasilla(int x, int y){
	return tabla[x][y];
}

void Tablero::setCasilla(char ficha, int x, int y){
	tabla[x][y] = new Casilla(ficha);
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
	
	if (tabla[fila][columna]->getFicha() == JUGADOR_1 || tabla[fila][columna]->getFicha() == JUGADOR_2)
		return true;
	else
		return false;
}

bool Tablero::columnaLlena(int columna){
	if (casillaOcupada(0, columna))
		return true;
		
	else
		return false;
}

bool Tablero::conectaCuatro(char equipo){
    
    for (int i = 0 ; i < FILAS; i++) {
        
        for (int j = 0 ; j < COLUMNAS; j++) {
        	
            int conteo = contarArriba(i, j, equipo);
            
            if (conteo == CONECTA) {
            	return true;
            }
            
            conteo = contarDerecha(i, j, equipo);
            
            if (conteo == CONECTA) {
                return true;
            }
            
            conteo = contarArribaDerecha(i, j, equipo);
            
            if (conteo == CONECTA) {
                return true;
            }
            
            conteo = contarAbajoDerecha(i, j, equipo);
            
            if (conteo == CONECTA) {
                return true;
            }
        }
    }
    return false;
}

void Tablero::conectarFichas(char equipo){

    // check horizontal
    for (int j = 0; j < COLUMNAS - 3 ; j++ ){
        for ( int i = 0; i < FILAS ; i++ ){
            if ( tabla[i][j]->getFicha() == equipo && tabla[i][j+1]->getFicha() == equipo && tabla[i][j+2]->getFicha() == equipo && tabla[i][j+3]->getFicha() == equipo ){
                tabla[i][j]->conectar(true);
                tabla[i][j+1]->conectar(true);
                tabla[i][j+2]->conectar(true);
                tabla[i][j+3]->conectar(true);
            }           
        }
    }
    // check vertical
    for ( int i = 0; i < FILAS-3 ; i++ ){
        for ( int j = 0; j < COLUMNAS ; j++ ){
            if ( tabla[i][j]->getFicha() == equipo && tabla[i+1][j]->getFicha() == equipo && tabla[i+2][j]->getFicha() == equipo && tabla[i+3][j]->getFicha() == equipo ){
                tabla[i][j]->conectar(true);
                tabla[i+1][j]->conectar(true);
                tabla[i+2][j]->conectar(true);
                tabla[i+3][j]->conectar(true);
            }           
        }
    }
    // check diagonal ascendente
    for ( int i = 3; i < FILAS ; i++ ){
        for ( int j = 0; j < COLUMNAS - 3; j++ ){
            if ( tabla[i][j]->getFicha() == equipo && tabla[i-1][j+1]->getFicha() == equipo && tabla[i-2][j+2]->getFicha() == equipo && tabla[i-3][j+3]->getFicha() == equipo )
                tabla[i][j]->conectar(true);
                tabla[i-1][j+1]->conectar(true);
                tabla[i-2][j+2]->conectar(true);
                tabla[i-3][j+3]->conectar(true);
        }
    }
    // check diagonal descendente
    for ( int i=3; i < FILAS ; i++ ){
        for ( int j = 3 ; j < COLUMNAS ; j++ ){
            if ( tabla [i][j]->getFicha() == equipo && tabla [i-1][j-1]->getFicha() == equipo && tabla[i-2][j-2]->getFicha() == equipo && tabla[i-3][j-3]->getFicha() == equipo)
                tabla [i][j]->conectar(true);
                tabla [i-1][j-1]->conectar(true);
                tabla[i-2][j-2]->conectar(true);
                tabla[i-3][j-3]->conectar(true);
        }
    }
}


bool Tablero::hacerMovimiento(int columna, char ficha){
	
	int fila = obtenerFilaDesocupada(columna);
	
	if (fila == -1){
		return false;
	}
	
	if (enRango(fila, columna)){
		colocarFicha(fila, columna, ficha);
		
		/*if (conectaCuatro(ficha)){
			conectarFichas(ficha);
		}*/
		
	}
	
	return false;
	
}

int Tablero::contarArriba(int x, int y, char equipo) {
	
    int yInicio = (y - CONECTA >= 0) ? y - CONECTA + 1 : 0;
    
    int contador = 0;
    
    for (; yInicio <= y; yInicio++) {
    	
        if (tabla[yInicio][x]->getFicha() == equipo && !tabla[yInicio][x]->estaConectado() ) {
            contador++;
            
        } else {
        	
            contador = 0;
        }
    }
    
    return contador;
}

int Tablero::contarDerecha(int x, int y, char equipo) {
	
    int xFin = (x + CONECTA < COLUMNAS) ? x + CONECTA - 1 : COLUMNAS - 1;
    
    int contador = 0;
    
    for (; x <= xFin; x++) {
    	
        if (tabla[y][x]->getFicha() == equipo && !tabla[y][x]->estaConectado()) {
            contador++;
            
        } else {
        	
            contador = 0;
        }
    }
    return contador;
}

int Tablero::contarArribaDerecha(int x, int y, char equipo) {
	
    int xFin = (x + CONECTA < COLUMNAS) ? x + CONECTA - 1 : COLUMNAS - 1;
    
    int yInicio = (y - CONECTA >= 0) ? y - CONECTA + 1 : 0;
    
    int contador = 0;
    
    while (x <= xFin && yInicio <= y) {
    	
        if (tabla[y][x]->getFicha() == equipo && !tabla[y][x]->estaConectado()) {
            contador++;
            
        } else {
            contador = 0;
        }
        
        x++;
        y--;
    }
    
    return contador;
}

int Tablero::contarAbajoDerecha(int x, int y, char equipo) {
	
    int xFin = (x + CONECTA < COLUMNAS) ? x + CONECTA - 1 : COLUMNAS - 1;
    
    int yFin = (y + CONECTA < FILAS) ? y + CONECTA - 1 : FILAS - 1;
    
    int contador = 0;
    
    while (x <= xFin && y <= yFin) {
    	
        if (tabla[y][x]->getFicha() == equipo && !tabla[y][x]->estaConectado()) {
            contador++;
            
        } else {
            contador = 0;
        }
        x++;
        y++;
    }
    return contador;
}

Tablero::~Tablero(){
	;
}
