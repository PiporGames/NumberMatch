//============================================================================
// Name        : TADJuego.h
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : Cabecera de TAD Juego
//============================================================================

#ifndef SRC_TADJUEGO_H_
#define SRC_TADJUEGO_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include "TADTablero.h"
#include "entorno.h"

using namespace std;

struct partida {
	tablero t;
	int puntuacion;
	int replicas;	// réplicas que nos quedan.
	int ayudas;		// ayudas que nos quedan.
};

// PRE = {}
// POST = { Inicializa el tablero dado, ajusta la matriz del tablero y sus propiedades y ajusta la puntuación a 0. }
// COMPLEJIDAD = O(n²)
bool iniciarPartida(partida &p);

// PRE = {}
// POST = { Gestiona la entrada de las teclas del jugador, ejecuta la lógica y actualiza en tiempo real el entorno gráfico.}
// COMPLEJIDAD = O(n⁴)
int tickPartida(partida p);

// PRE = {}
// POST = { Finaliza la partida y cierra el entorno gráfico }
// COMPLEJIDAD = O(1)
void terminarPartida(int exit);

#endif
