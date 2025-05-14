//============================================================================
// Name        : TADCelda.cpp
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : TAD Celda
//============================================================================

#include "TADCelda.h"

void crearCelda(celda &c, int n) {
	c.num = n;
	c.borrado = false;
	c.vacio = false;
}

void crearCeldaVacia(celda &c) {
	c.vacio = true;
}

void borrarNumeroCelda(celda &c) {
	c.borrado = true;
}

int obtenerNumeroCelda(celda c) {
	return c.num;
}

bool esVaciaCelda(celda c) {
	return c.vacio;
}

bool esBorradaCelda(celda c) {
	return c.borrado;
}

bool sonParejaC(celda c, celda d) {
	return ((c.num == d.num) || (c.num + d.num)==10);
}
