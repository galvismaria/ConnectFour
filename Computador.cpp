#define FILAS 6
#define COLUMNAS 7
#define TAMANIO_MATRIZ sizeof(char)*FILAS*COLUMNAS
#define JUGADOR_1 'o'
#define JUGADOR_2 'x'
#define JUGADOR_CPU_1 JUGADOR_1
#define JUGADOR_CPU_2 JUGADOR_2
#define ESPACIO_VACIO ' '
#define FILA_NO_ENCONTRADA -1
#define ERROR_COLUMNA_LLENA 2
#define ERROR_FILA_INVALIDA 4
#define ERROR_NINGUNO 3
#define CONECTA 4
#define CONECTA_ARRIBA 1
#define CONECTA_DERECHA 2
#define CONECTA_ABAJO_DERECHA 3
#define CONECTA_ARRIBA_DERECHA 4
#define NO_CONECTA 0
#define COLUMNA_GANADORA_NO_ENCONTRADA -1
#define MODO_HUMANO_CONTRA_HUMANO 1
#define MODO_HUMANO_CONTRA_CPU 2
#define MODO_CPU_CONTRA_CPU 3

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
 
 
void Computador::getMejorColumna(char equipo){
	
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
	
	this->conteo = contMayor;
	this->indice = iColumnaMayor;
	
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
	
	if( copiaTablero->hacerMovimiento(posibleResultado, equipo) ){
		
		printf("*elijo ganar*\n");
		return posibleResultado;
		
	}
	
	int posibleResultadoOponente = obtenerColumnaGanadora(oponente);
	
	if ( copiaTablero->hacerMovimiento(posibleResultadoOponente, oponente ))
	
	
	
}

int elegirColumnaCpu(char jugador, char tablero[FILAS][COLUMNAS]) {
    // Voy a comprobar si puedo ganar...
    int posibleColumnaGanadora = obtenerColumnaGanadora(jugador, tablero);
    if (posibleColumnaGanadora != COLUMNA_GANADORA_NO_ENCONTRADA) {
        printf("*elijo ganar*\n");
        return posibleColumnaGanadora;
    }
    // Si no, voy a comprobar si mi oponente gana con el siguiente movimiento, para evitarlo
    char oponente = obtenerOponente(jugador);
    int posibleColumnaGanadoraDeOponente = obtenerColumnaGanadora(oponente, tablero);
    if (posibleColumnaGanadoraDeOponente != COLUMNA_GANADORA_NO_ENCONTRADA) {
        printf("*elijo evitar que mi oponente gane*\n");
        return posibleColumnaGanadoraDeOponente;
    }
    // En caso de que nadie pueda ganar en el siguiente movimiento, buscaré en dónde se obtiene el mayor
    // puntaje al colocar la pieza
    int conteoCpu, columnaCpu;
    obtenerColumnaEnLaQueSeObtieneMayorPuntaje(jugador, tablero, &conteoCpu, &columnaCpu);
    int conteoOponente, columnaOponente;
    obtenerColumnaEnLaQueSeObtieneMayorPuntaje(oponente, tablero, &conteoOponente, &columnaOponente);
    if (conteoOponente > conteoCpu) {
        printf("*elijo quitarle el puntaje a mi oponente*\n");
        return columnaOponente;
    } else if (conteoCpu > 1) {
        printf("*elijo colocarla en donde obtengo un mayor puntaje*\n");
        return columnaCpu;
    }
    // Si no, regresar la central por si está desocupada

    int columnaCentral = obtenerColumnaCentral(jugador, tablero);
    if (columnaCentral != COLUMNA_GANADORA_NO_ENCONTRADA) {
        printf("*elijo ponerla en el centro*\n");
        return columnaCentral;
    }
    // Finalmente, devolver la primera disponible de manera aleatoria
    int columna = obtenerColumnaAleatoria(jugador, tablero);
    if (columna != FILA_NO_ENCONTRADA) {
        printf("*elijo la primera vacía aleatoria*\n");
        return columna;
    }
    printf("Esto no debería suceder\n");
    return 0;
}
