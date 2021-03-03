#include "Casilla.h"

Casilla::Casilla(){
	ficha = '\0';
	conectado = false;
}

void Casilla::setFicha(char ficha){
	this->ficha = ficha;
}

void Casilla::conectar(bool conectado){
	this->conectado = conectado;
} 

Casilla::Casilla(char ficha){
	this->ficha = ficha;
}

char Casilla::getFicha(){
	return ficha;
}

bool Casilla::estaConectado(){
	return conectado;
}

Casilla::~Casilla(){
	;
}
