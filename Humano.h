#ifndef HUMANO_H
#define HUMANO_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "Global.h"
#include "Jugador.h"

class Humano : public Jugador{
	
	public:
		Humano(char equipo);
		int movimiento();
};

#endif
