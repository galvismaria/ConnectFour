#include "Computador.h"

Computador::Computador(Tablero *original, char equipo){
	
	copiaTablero = new Tablero();
	this->original = original;	
	this->equipo = equipo;
}

void Computador::clonarMatriz() {
	
    for (int i = 0 ; i < FILAS ; i++){
		
		for (int j = 0 ; j < COLUMNAS ; j++){
			
			copiaTablero->setCasilla(original->getCasilla(i, j), i, j);
			
		}
	}
}

void Computador::vaciarMatriz(){
	copiaTablero = new Tablero();
}

void Computador::setTableroActual(Tablero *original){
	this->original = original;
}

int Computador::getColumnaGanadora(char equipo){
	
	for (int i = 0 ; i < COLUMNAS ; i++){
		clonarMatriz();
		if (copiaTablero->hacerMovimiento(i, equipo))
			if (copiaTablero->conectaCuatro(equipo))
			{
				vaciarMatriz();
				return i;
			}
	}
	
	vaciarMatriz();
	
	return -1;
}

int Computador::getUltimaFila(int columna){
	
	for (int i = 0 ; i < FILAS ; i++){
		
		if (copiaTablero->casillaOcupada(i, columna))
			return i;
	}
	
	return -1;
}
 
void Computador::getMejorColumna(char equipo, int *conteo, int *indice){
	
	int contMayor = 0;
	int iColumnaMayor = -1;
	
	for (int i = 0 ; i < COLUMNAS ; i++){
		
		clonarMatriz();
		
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
	
	*conteo = contMayor;
	*indice = iColumnaMayor;
	
	vaciarMatriz();
	
}

int Computador::randomEnRango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Computador::getColumnaRandom(char equipo){
	
	bool flag = false;
	
	while (!flag){
		
		clonarMatriz();
		int columna = randomEnRango(0, COLUMNAS - 1);
		
		if (copiaTablero->hacerMovimiento(columna, equipo)){
			flag = true;
			vaciarMatriz();
			return columna;	
		}
		
	}
	
	vaciarMatriz();
	return -1;
	
}

int Computador::getColumnaCentral(char equipo){
	
	clonarMatriz();
	
	if (copiaTablero->hacerMovimiento( (COLUMNAS -1 ) / 2, equipo)){
		vaciarMatriz();
		return (COLUMNAS -1 ) / 2;
	}
	
	vaciarMatriz();
	return -1;
}

int Computador::elegirColumna(char equipo, char oponente){
	
	int posibleResultado = getColumnaGanadora(equipo);
	
	if ( posibleResultado != -1 ){
		
		cout <<"~Elijo ganar~";
		return posibleResultado;
		
	}
	
	int posibleResultadoOponente = getColumnaGanadora(oponente);
	
	if ( posibleResultadoOponente != -1 ){
		
		cout <<"~Elijo evitar que mi oponente gane~";
		return posibleResultadoOponente;
		
	}
	
	
	int conteoCpu, columnaCpu;
	
	getMejorColumna(equipo, &conteoCpu, &columnaCpu);
	
	int conteoOponente, columnaOponente;
	
	getMejorColumna(oponente, &conteoOponente, &columnaOponente);
	
	if (conteoOponente > conteoCpu){
		
		cout <<"~Elijo quitarle puntaje a mi oponente~";
        return columnaOponente;
        
    }
	
	else if (conteoCpu > 1) {
        cout <<"~Elijo colocarla donde obtengo un mayor puntaje~";
        return columnaCpu;
    }
    
    int columnaCentral = getColumnaCentral(equipo);
    
    if (columnaCentral != -1){
    	cout <<"~Elijo ponerla en el centro~";
        return columnaCentral;
	}
	
	int columna = getColumnaRandom(equipo);
	
	if (columna != -1){
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
	return columna;
	
}

bool Computador::esComputador(){
	return true;
}
