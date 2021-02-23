void Computador::clonarMatriz(Tablero* original) {
	
    for (int i = 0 ; i < FILAS ; i++){
		
		for (int j = 0 ; j < COLUMNAS ; j++){
			
			copiaTablero->setCasilla(original->getCasilla(i, j), i, j);
			
		}
	}
}

int Computador::getColumnaGanadora(char equipo){
	
	for (int i = 0 ; i < COLUMNAS ; i++){
		if (copiaTablero->hacerMovimiento(i, char equipo))
			if (copiaTabero->conectaCuatro(char equipo))
				return i;
	}
	
	return -1;
}

int Computador::getUltimaFila(int columna){
	
	for (int i = 0 ; i < FILAS ; i++){
		
		if (copiaTablero->casillaOcupada(i, columna))
			return i;
	}
	
	return -1;
}

/*
 * Los dos últimos apuntadores son porque no podemos regresar dos variables
 * */
 
 
void Computador::getMejorColumna(char equipo, int *conteo, int *indice){
	
	int contMayor = 0;
	int iColumnaMayor = -1;
	
	for (int i = 0 ; i < COLUMNAS ; i++){
		
		if (copiaTablero->hacerMovimiento(i, equipo)){
			
			int filaReciente = getUltimaFila(i);
			
			if (filaReciente != -1){
				
				int c = copiaTablero->contarArriba(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
				
				c = copiaTablero->contarArribaDerecha(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
				
				c = copiaTablero->contarDerecha(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
				
				c = copiaTablero->contarAbajoDerecha(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
			}
		}
		
	}
	
	conteo = contMayor;
	indice = iColumnaMayor;
	
}
 

int Computador::randomEnRango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Computador::getColumnaRandom(char equipo){
	
	bool flag = false;
	
	while (!flag){
		
		int columna = randomEnRango(0, COLUMNAS - 1);
		if (copiaTablero->hacerMovimiento(columna, equipo)){
			flag = true;
			return columna;	
		}
		
	}
	
	return -1;
	
}

int Computador::getColumnaCentral(char equipo){
	
	if (copiaTablero->hacerMovimiento( (COLUMNAS -1 ) / 2, equipo)){
		return (COLUMNAS -1 ) / 2;
	}
	
	return -1;
}


int Computador::elegirColumna(char equipo, char oponente){
	
	int posibleResultado = getColumnaGanadora(equipo);
	
	if ( posibleResultado != -1 ){
		
		printf("*elijo ganar*\n");
		return posibleResultado;
		
	}
	
	int posibleResultadoOponente = getColumnaGanadora(oponente);
	
	if ( posibleResultadoOponente != -1 ){
		
		 printf("*elijo evitar que mi oponente gane*\n");
		return posibleResultadoOponente;
		
	}
	
	
	int conteoCpu, columnaCpu;
	
	getMejorColumna(equipo, &conteoCpu, &columnaCpu);
	
	int conteoOponente, columnaOponente;
	
	getMejorColumna(ponente, &conteoOponente, &columnaOponente);
	
	if (conteoOponente > conteoCpu){
		
		printf("*elijo quitarle el puntaje a mi oponente*\n");
        return columnaOponente;
        
    }
	
	else if (conteoCpu > 1) {
        printf("*elijo colocarla en donde obtengo un mayor puntaje*\n");
        return columnaCpu;
    }
    
    int columnaCentral = getColumnaCentral(equipo);
    
    if (columnaCentral != -1){
    	printf("*elijo ponerla en el centro*\n");
        return columnaCentral;
	}
	
	int columna = getColumnaRandom(equipo);
	
	if (columna != -1){
		printf("*elijo la primera vacía aleatoria*\n");
        return columna;
	}
	
	printf("Esto no debería suceder\n");
    return 0;
	
}
