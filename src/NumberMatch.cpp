//============================================================================
// Name        : NumberMatch.cpp
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : Juego NumberMatch
//============================================================================

#include "entorno.h"
#include "TADJuego.h"
#include "pr_tablero.h"

using namespace std;

int main() {
	int exit;
	partida p;

	//pruebas_TADTablero();

	srand(time(NULL));
	if (iniciarPartida(p)) {
		exit = tickPartida(p);
		terminarPartida(exit);
	}

	return 0;
}
