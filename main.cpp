#include "Juego.h"

using namespace std;

int main(){
	
	Juego *juego = new Juego();
	juego->menuPrincipal();
	juego->~Juego();
	return 0;

}
