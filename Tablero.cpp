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
	
	for ( int i =  0 ; i < FILAS ; i++ ){
		cout <<"\t\t\t\t";
		
		for ( int j = 0 ; j < COLUMNAS; j++ ){
			
		if ( tabla[i][j]->getFicha() == '\0' )
				cout << " |   |";
				
			if ( tabla[i][j]->getFicha() == JUGADOR_1 )
				cout << " | X |";
				
			if ( tabla[i][j]->getFicha() == JUGADOR_2 )
				cout << " | O |";
		
		}
		
		cout <<"\t\t\t\t\n";
	}
}

int Tablero::obtenerFilaDesocupada(int columna){
	
	for ( int i = FILAS-1 ; i >= 0 ; i-- ){
		
		if ( tabla[i][columna]->getFicha() == '\0' ){
			return i;
		
		}
	}
	
	return -1;
	
}

Casilla* Tablero::getCasilla( int x, int y ){
	return tabla[x][y];
}

void Tablero::setCasilla( char ficha, int x, int y ){
	tabla[x][y] = new Casilla(ficha);
}

void Tablero::colocarFicha( int fila, int columna, char ficha ){
	
	tabla[fila][columna]->setFicha(ficha);
	
}

bool Tablero::enRango( int fila, int columna ) {
	
	if ( ( columna >= 0 && columna < COLUMNAS ) && ( fila >= 0 && fila < FILAS ) )
		return true;
		
	else
		return false;
	
}

bool Tablero::casillaOcupada( int fila, int columna ){
	
	if ( tabla[fila][columna]->getFicha() == JUGADOR_1 || tabla[fila][columna]->getFicha() == JUGADOR_2 )
		return true;
	else
		return false;
}

bool Tablero::columnaLlena( int columna ){
	if (casillaOcupada( 0, columna) )
		return true;
		
	else
		return false;
}

bool Tablero::tableroLleno(){
	
	bool flag;
	
	for ( int i = 0 ; i < COLUMNAS ; i++ ){
		flag = columnaLlena(i);
	
	}
	
	return flag;
	
}

bool Tablero::conectaCuatro(char equipo){
    
    for (int y = 0; y < FILAS; y++) {
        
        for (int x = 0; x < COLUMNAS; x++) {
        	
            int conteoArriba = contarArriba(x, y, equipo);
            
            if (conteoArriba == CONECTA) {
                return true;
            }
            if (contarDerecha(x, y, equipo) == CONECTA) {
                return true;
            }
            if (contarArribaDerecha(x, y, equipo) == CONECTA) {
                return true;
            }
            if (contarAbajoDerecha(x, y, equipo) == CONECTA) {
			    return true;
			}
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

int Tablero::contarArriba(int x, int y, char equipo) {
	
    int yInicio = (y - CONECTA >= 0) ? y - CONECTA + 1 : 0;
    
    int contador = 0;
    
    for (; yInicio <= y; yInicio++) {
    	
        if (tabla[yInicio][x]->getFicha() == equipo) {
        	
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
    	
        if (tabla[y][x]->getFicha() == equipo) {
        	
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
    	
        if (tabla[y][x]->getFicha() == equipo) {
        	
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
    	
        if (tabla[y][x]->getFicha() == equipo) {
        	
            contador++;
            
        } else {
        	
            contador = 0;
            
        }
        x++;
        y++;
    }
    return contador;
}

int Tablero::contarSecuencias(char equipo){
	
	Casilla *copia[FILAS][COLUMNAS];
	
	int cont = 0 ;
	
	for ( int i = 0 ; i < FILAS ; i++ ){
		
		for ( int j = 0 ; j < COLUMNAS ; j++ ){
			
			copia[i][j] = new Casilla();
			copia[i][j]->setFicha( tabla[i][j]->getFicha() );
			
		}
	}
	
	// check horizontal
	for (int j = 0; j < COLUMNAS - 3 ; j++ ){
        for ( int i = 0; i < FILAS ; i++ ){
            if ( copia[i][j]->getFicha() == equipo &&
				 copia[i][j+1]->getFicha() == equipo &&
				 copia[i][j+2]->getFicha() == equipo &&
				 copia[i][j+3]->getFicha() == equipo ){
                	
                copia[i][j]->setFicha('\0');
				copia[i][j+1]->setFicha('\0');
				copia[i][j+2]->setFicha('\0');
				copia[i][j+3]->setFicha('\0');
				
				cont++;
					
            }           
        }
    }

	// check vertical
	for ( int i = 0; i < FILAS-3 ; i++ ){
	    for ( int j = 0; j < COLUMNAS ; j++ ){
	        if ( copia [i][j]->getFicha() == equipo &&
				 copia[i+1][j]->getFicha() == equipo &&
				 copia[i+2][j]->getFicha() == equipo &&
				 copia[i+3][j]->getFicha() == equipo ){
	                
				copia[i][j]->setFicha('\0');
				copia[i+1][j]->setFicha('\0');
				copia[i+2][j]->setFicha('\0');
				copia[i+3][j]->setFicha('\0');
					
				cont++;
	        }           
	    }
	}
	    
	// check diagonal ascendente
	for ( int i = 3; i < FILAS ; i++ ){
	    for ( int j = 0; j < COLUMNAS - 3; j++ ){
	        if ( copia[i][j]->getFicha() == equipo &&
				 copia[i-1][j+1]->getFicha() == equipo &&
				 copia[i-2][j+2]->getFicha() == equipo &&
				 copia[i-3][j+3]->getFicha() == equipo ){
		     
	            copia[i][j]->setFicha('\0');
				copia[i-1][j+1]->setFicha('\0');
				copia[i-2][j+2]->setFicha('\0');
				copia[i-3][j+3]->setFicha('\0');
					
				cont++;
	        }
	    }
	}
	    
	// check diagonal descendente
	for ( int i=3; i < FILAS ; i++ ){
	    for ( int j = 3 ; j < COLUMNAS ; j++ ){
	        if ( copia [i][j]->getFicha() == equipo &&
				 copia [i-1][j-1]->getFicha() == equipo &&
				 copia[i-2][j-2]->getFicha() == equipo &&
				 copia[i-3][j-3]->getFicha() == equipo){
			 
	            copia[i][j]->setFicha('\0');
				copia[i-1][j-1]->setFicha('\0');
				copia[i-2][j-2]->setFicha('\0');
				copia[i-3][j-3]->setFicha('\0');
					
				cont++;
	        }
	    }
	}
	    
	return cont;
			
}

Tablero::~Tablero(){
	delete &tabla;
}
