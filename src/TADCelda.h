//============================================================================
// Name        : TADCelda.h
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : Cabecera de TAD Celda
//============================================================================

#ifndef TADCELDA_H_
#define TADCELDA_H_

#include <iostream>

using namespace std;

struct celda {
	int num; //le dicho número.
	bool vacio; //no hay número.
	bool borrado; //hay número, pero está borrado.
};

// PRE = {}
// POST = { Inicializa una celda y le asigna el número n }
// COMPLEJIDAD = O(1)
void crearCelda(celda &c, int n);

// PRE = {}
// POST = { Inicializa la celda dada con los valores vacios }
// COMPLEJIDAD = O(1)
void crearCeldaVacia(celda &c);

// PRE = { Celda correctamente inicializada y no vacía }
// POST = { Devuelve la celda con el campo 'borrado' a 'true' }
// COMPLEJIDAD = O(1)
void borrarNumeroCelda(celda &c);

// PRE = { Celda correctamente inicializada y no vacía }
// POST = { Devuelve el número contenido en la celda. }
// COMPLEJIDAD = O(1)
int obtenerNumeroCelda(celda c);

// PRE = { Celda correctamente inicializada }
// POST = { Devuelve 'true' en caso de que la celda está vacía, 'false' en caso contrario }
// COMPLEJIDAD = O(1)
bool esVaciaCelda(celda c);

// PRE = { Celda correctamente inicializada y no vacía }
// POST = { Devuelve 'true' en caso de que la celda está borrada, 'false' en caso contrario }
// COMPLEJIDAD = O(1)
bool esBorradaCelda(celda c);

// PRE = { Celda correctamente inicializada y no vacía ni borrada }
// POST = { Devuelve 'true' en caso de que los números sean iguales, 'false' en caso contrario }
// COMPLEJIDAD = O(1)
bool sonParejaC(celda c, celda d);

#endif /* TADCELDA_H_ */
