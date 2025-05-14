//============================================================================
// Name        : TADTablero.h
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : Cabecera del TAD Tablero
//============================================================================

#ifndef TADTABLERO_H_
#define TADTABLERO_H_

#include <iostream>
#include <cstdlib>
#include "TADCelda.h"
#include "entorno.h"

using namespace std;

typedef celda tmatriz[MAX_FILAS][MAX_COLUMNAS];

struct tablero {
	tmatriz matriz;
	int ultFil;
	int ultCol;
	int max_col;
	int max_fil;
	int celUtl;
};

// PRE = { MAX_FILAS < filas < 0; MAX_COLUMNAS < columnas < 0 }
// POST = { Inicializa el tablero dado, con dimensiones 'filas' x 'columnas', rellenando con números aleatorios ( valores entre 1 y 9) la cantidad de filas indicada por 'iniciales'.
//          Si filas es 0, se utilizarán las dimensiones por defecto del entorno.
//			Si columnas es 0, se utilizarán las dimensiones por defecto del entorno.
//			Si iniciales es 0, se devolverá un tablero vacío. }
// COMPLEJIDAD = O(n²)
void crearTablero(tablero &t, int filas, int columnas, int iniciales);

// PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
// POST = { Devuelve el tablero con la celda seleccionada vacía. }
// COMPLEJIDAD = O(1)
void vaciarCelda(tablero &t, int fil, int col);

// PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
// POST = { Devuelve el tablero con la celda seleccionada borrada. }
// COMPLEJIDAD = O(1)
void borrarCelda(tablero &t, int fil, int col);

// PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
// POST = { Devuelve el número de la celda seleccionada. }
// COMPLEJIDAD = O(1)
int obtenerNum(tablero t, int fil, int col);

// PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
// POST = { Devuelve 'true' si la celda seleccionada esta vacía, 'false' en caso contrario. }
// COMPLEJIDAD = O(1)
bool estaVacia(tablero t, int fil, int col );

// PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
// POST = { Devuelve 'true' si la celda seleccionada esta borrada, 'false' en caso contrario. }
// COMPLEJIDAD = O(1)
bool estaBorrada(tablero t, int fil, int col);

//PRE={ Tablero correctamente iniciañizado }
//POST={ Borra la fila 'fil' del tablero y mueve las que tenga por debajo una posición hacia arriba }
//COMPLEJIDAD = O(n²)
void borrarFila(tablero &t, int fil);

//PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
//DESC = Muestra el tablero 't' en el terminal, si una celda está borrada mostrará el número entre paréntesis () y si está vacía mostrará una 'V'.
//COMPLEJIDAD = O(n)
void mostrarTablero(tablero t);

//PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
//POST = { Devuelve el número de filas y columnas útiles. }
//COMPLEJIDAD = O(1)
void obtenerFilCol(tablero t, int &filaS, int &colS);

//PRE = { Tablero correctamente inicializado }
//POST = { Devuelve el número de filas y columnas máximas del tablero 't' }
//COMPLEJIDAD = O(1)
void obtenerFilColMax(tablero t, int &filaM, int &colM);

//PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
//POST = { Devuelve las coordenadas de la última celda ocupada en el tablero. }
//COMPLEJIDAD = O(1)
void devolverCoordUltimaCeldaOcupada(tablero t, int &coordFila, int &coordCol);

//PRE = { Tablero correctamente inicializado, fila < MAX_FIL, columnas < MAX_COL }
//DESC = Ajusta un número concreto a una celda de una fila y una columna especificadas.
//COMPLEJIDAD = O(n)
void ponerNumCelda(tablero &t, int fil, int col, int num);

//PRE = { Tablero correctamente inicializado, filX < MAX_FIL, colX < MAX_COL }
//POST = { Devuelve 'true' si las celdas especificadas forman una pareja. En caso contrario, devuelve 'false' }
//COMPLEJIDAD = O(1)
bool sonPareja(tablero t, int fil1, int col1, int fil2, int col2);

//PRE = { Tablero correctamente inicializado, fila < MAX_FIL }
//POST = { Devuelve 'true' si &toda las celdas de la fila especificada están borradas. De lo contrario, devuelve 'false' }
//COMPLEJIDAD = O(n)
bool esFilaBorrada(tablero t, int fil);

//PRE = { Tablero correctamente inicializado }
//POST = { Copia en serie a partir de la ultima celda ocupada todas las celdas ocupadas restantes en el tablero (incluida ella misma).
//		   Devuelve 'true' si se ha completado la operación correctamente, y 'false' en caso contrario.}
//COMPLEJIDAD = O(n)
bool replicar(tablero &t);

#endif /* "TADTABLERO_H_" */

