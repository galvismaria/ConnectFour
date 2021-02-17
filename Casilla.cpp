#include "Casilla.h"

Casilla::Casilla(){
	ficha = '\0';
}

Casilla::Casilla(char ficha){
	this->ficha = ficha;
}

char Casilla::getFicha(){
	return ficha;
}

void Casilla::setFicha(char equipo){
	ficha = equipo;
}
