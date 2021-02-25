#include "Computador.h"

Computador::Computador(char equipo){
	
	estadoActual = new Tablero();
	this->equipo = equipo;
}

void Computador::setTableroActual(Tablero *actual){
	
	estadoActual = new Tablero();
	
	for (int i = 0 ; i < FILAS ; i++){
		
		for (int j = 0 ; j < COLUMNAS ; j++){
			
			estadoActual->setCasilla(actual->getCasilla(i, j)->getFicha(), i, j);
			
		}
	}
	
}

void Computador::copiarTablero(Tablero *origen, Tablero *destino) {
	
	for (int i = 0 ; i < FILAS ; i++){
		
		for (int j = 0 ; j < COLUMNAS ; j++){
			
			destino->setCasilla(origen->getCasilla(i, j)->getFicha(), i, j);
			
		}
	}
}

int Computador::getColumnaGanadora(char equipo){
	
	Tablero *temp = new Tablero();
	
	for (int i = 0 ; i < COLUMNAS ; i++){
		
		copiarTablero(estadoActual, temp);
		
		if (temp->hacerMovimiento(i, equipo))
		
			if (temp->conectaCuatro(equipo))
			{
				delete temp;
				return i;
			}
	}
	
	return -1;
}

int Computador::getUltimaFila(int columna){
	
	for (int i = 0 ; i < FILAS ; i++){
		
		if (estadoActual->casillaOcupada(i, columna))
			return i;
	}
	
	return -1;
}
 
void Computador::getMejorColumna(char equipo, int *conteo, int *indice){
	
	int contMayor = 0;
	int iColumnaMayor = -1;
	Tablero *temp = new Tablero();
	
	for (int i = 0 ; i < COLUMNAS ; i++){
		
		copiarTablero(estadoActual, temp);
		
		if (temp->hacerMovimiento(i, equipo)){
			
			int filaReciente = getUltimaFila(i);
			
			if (filaReciente != -1){
				
				int c = temp->contarArriba(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
				
				c = temp->contarArribaDerecha(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
				
				c = temp->contarDerecha(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
				
				c = temp->contarAbajoDerecha(i, filaReciente, equipo);
				
				if (c > contMayor){
					contMayor = c;
					iColumnaMayor = i;
				}
			}
		}
		
	}
	
	*conteo = contMayor;
	*indice = iColumnaMayor;
	delete temp;
	
}

int Computador::randomEnRango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Computador::getColumnaRandom(char equipo){
	
	bool flag = false;
	Tablero *temp = new Tablero();
	
	while (!flag){
		
		copiarTablero(estadoActual, temp);
		int columna = randomEnRango(0, COLUMNAS - 1);
		
		if (temp->hacerMovimiento(columna, equipo)){
			flag = true;
			delete temp;
			return columna;	
		}
		
	}
	
}

int Computador::getColumnaCentral(char equipo){
	
	Tablero *temp = new Tablero();
	copiarTablero(estadoActual, temp);
	
	if (temp->hacerMovimiento( (COLUMNAS -1 ) / 2, equipo)){
		delete temp;
		return (COLUMNAS -1 ) / 2;
	}
	
	return (COLUMNAS-1) / 2;
	
	return -1;
}

int Computador::elegirColumna(char equipo, char oponente){
	
	int posibleResultado = getColumnaGanadora(equipo);
	
	if ( posibleResultado != -1 && !estadoActual->columnaLlena(posibleResultado)){
		
		cout <<"~Elijo ganar~";
		return posibleResultado;
		
	}
	
	int posibleResultadoOponente = getColumnaGanadora(oponente);
	
	if ( posibleResultadoOponente != -1 && !estadoActual->columnaLlena(posibleResultadoOponente)){
		
		cout <<"~Elijo evitar que mi oponente gane~";
		return posibleResultadoOponente;
		
	}
	
	
	int conteoCpu, columnaCpu;
	
	getMejorColumna(equipo, &conteoCpu, &columnaCpu);
	
	int conteoOponente, columnaOponente;
	
	getMejorColumna(oponente, &conteoOponente, &columnaOponente);
	
	if (conteoOponente > conteoCpu && !estadoActual->columnaLlena(columnaOponente)){
		
		cout <<"~Elijo quitarle puntaje a mi oponente~";
        return columnaOponente;
        
    }
	
	else if (conteoCpu > 1 && !estadoActual->columnaLlena(columnaCpu)) {
        cout <<"~Elijo colocarla donde obtengo un mayor puntaje~";
        return columnaCpu;
    }
    
    int columnaCentral = getColumnaCentral(equipo);
    
    if (columnaCentral != -1 && !estadoActual->columnaLlena(columnaCentral)){
    	cout <<"~Elijo ponerla en el centro~";
        return columnaCentral;
	}
	
	int columna = getColumnaRandom(equipo);
	
	if (columna != -1 && !estadoActual->columnaLlena(columna)){
		cout <<"~Elijo una columna aleatoria~";
        return columna;
	}
	
	cout <<"~Ups, esto no debería pasar~";
    return 0;
	
}

int Computador::movimiento(){
	
	int columna;
	columna = elegirColumna(equipo, getOponente());
	cout <<" "<< columna;
	system("pause");
	return columna;
	
}

bool Computador::esComputador(){
	return true;
}
