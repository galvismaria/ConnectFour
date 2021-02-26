#include "Casilla.h"

Casilla::Casilla(){
	ficha = '\0';
}

void Casilla::setFicha(char ficha){
	this->ficha = ficha;
}

Casilla::Casilla(char ficha){
	this->ficha = ficha;
}

char Casilla::getFicha(){
	return ficha;
}

Casilla::~Casilla(){
	;
}
