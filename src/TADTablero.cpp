//============================================================================
// Name        : TADTablero.cpp
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : TAD Tablero
//============================================================================

#include "TADTablero.h"

void crearTablero(tablero &t, int filas, int columnas, int iniciales) {
	int i;
	int j;

	if (filas == 0) {
		filas = MAX_FILAS;
	}
	if (columnas == 0) {
		columnas = MAX_COLUMNAS;
	}

	t.max_fil = filas;
	t.max_col = columnas;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (i < iniciales) {
				crearCelda(t.matriz[i][j], rand() % 9 + 1);
			} else {
				crearCeldaVacia(t.matriz[i][j]);
			}
		}
	}
	t.ultFil = iniciales;
	t.ultCol = t.max_col;
	t.celUtl = (iniciales * t.max_col);
}

void vaciarCelda(tablero &t, int fil, int col) {
	crearCeldaVacia(t.matriz[fil][col]);
	t.celUtl--;
	if ((fil == (t.ultFil - 1)) && (col == (t.ultCol - 1))) {
		if (col != 1) {
			t.ultFil = fil + 1;
			t.ultCol = col;
		} else {
			t.ultFil = fil;
			t.ultCol = t.max_col;
		}
	}
}

void borrarCelda(tablero &t, int fil, int col) {
	borrarNumeroCelda(t.matriz[fil][col]);
	t.celUtl--;
	if ((fil == t.ultFil) && (col == t.ultCol)) {
		if (col != 1) {
			t.ultFil = fil;
			t.ultCol = col - 1;
		} else {
			t.ultFil = fil - 1;
			t.ultCol = t.max_col;
		}
	}
}

int obtenerNum(tablero t, int fil, int col) {
	return obtenerNumeroCelda(t.matriz[fil][col]);
}

bool estaVacia(tablero t, int fil, int col) {
	return esVaciaCelda(t.matriz[fil][col]);
}

bool estaBorrada(tablero t, int fil, int col) {
	return esBorradaCelda(t.matriz[fil][col]);
}

void borrarFila(tablero &t, int fil) {
	int i, j;
	for (i = fil; i < t.ultFil - 1; i++) {
		for (j = t.max_col - 1; j >= 0; j--) {
			t.matriz[i][j] = t.matriz[i + 1][j];
		}
	}
	for (j = t.max_col - 1; j >= 0; j--) {
		vaciarCelda(t, i, j);
	}
	if (fil == t.ultFil - 1) {
		t.ultCol = t.max_col;
	}
	t.ultFil--;
	t.celUtl += t.max_col;
}

void mostrarTablero(tablero t) {
	int i, j;
	celda c;
	for (i = 0; i < t.max_fil; i++) {
		for (j = 0; j < t.max_col; j++) {

			c = t.matriz[i][j];

			if (!esVaciaCelda(c)) {
				if (!esBorradaCelda(c)) {
					cout << " " << obtenerNumeroCelda(c) << "  ";
				} else {
					cout << "(" << obtenerNumeroCelda(c) << ") ";
				}
			} else {
				cout << " V  ";
			}
		}
		cout << endl << endl;
	}
	cout << endl << "[" << t.celUtl << "]" << "  |  " << "ULT{X: " << t.ultCol << "  Y:" << t.ultFil << "}" << endl << endl;
}

void obtenerFilCol(tablero t, int &filaS, int &colS) {
	if (t.ultFil == 1) {
		filaS = t.ultFil;
		colS = t.ultCol;
	} else {
		filaS = t.ultFil;
		colS = t.max_col;
	}
}

void obtenerFilColMax(tablero t, int &filaM, int &colM) {
	filaM = t.max_fil;
	colM = t.max_col;
}

void devolverCoordUltimaCeldaOcupada(tablero t, int &coordFila, int &coordCol) {
	coordFila = t.ultFil;
	coordCol = t.ultCol;
}

void ponerNumCelda(tablero &t, int fil, int col, int num) {
	crearCelda(t.matriz[fil][col], num);
}

bool sonPareja(tablero t, int fil1, int col1, int fil2, int col2) {
	bool res, parej;
	int menor;
	int dist;
	int colAux;
	int filAux;
	int i;
	int distanciaFil, distanciaCol;
	parej = false;
	res = false;


	//COMPROBACIÓN DE PAREJA SIMPLE

	distanciaFil = (abs(fil1 - fil2));
	//Se comprueba la posición relativa de las filas de ambas celdas
	if (fil1 > fil2) {
		distanciaCol = col2 - col1;
		//Si la distancia entre las filas es 1 Y la distancia entre las columnas es el máximo O la distancia entre las columnas está entre 1 y -1 se comprobará si son pareja
		if ((distanciaFil == 1) && ((distanciaCol == (t.max_col - 1)) || ((distanciaCol <= 1) && (distanciaCol >= -1)))) {
			res = true;
		}
	} else {
		if (fil2 > fil1) {
			distanciaCol = col1 - col2;
			//mismo caso que arriba, pero corrigiendo el valor absoluto como se muestra arriba.
			if ((distanciaFil == 1) && ((distanciaCol == (t.max_col - 1)) || ((distanciaCol <= 1) && (distanciaCol >= -1)))) {
				res = true;
			}
		} else {
			distanciaCol = abs(col1 - col2);
			//Si la distancia entre columnas es 1 o 0 entonces se comprobará si son pareja
			if (distanciaCol <= 1) {
				res = true;
			}
		}
	}

	//COMPROBACIÓN DE PAREJA COMPLEJA (AMPLIACIÓN)
	//Si todavía no forman pareja, intentar con esta colección de reglas...
	if (!(res)) {
		res = true;
		if (fil1 == fil2) {
			//Si las filas son iguales, se comprueban si estan en posiciones contiguas
			if ( col1 < col2 ) {
				//declaramos la distancia y cual de ellas es la menor
				menor = col1;
				dist = (col2 - col1) - 1;
			}
			else {
				//declaramos la distancia y cual de ellas es la menor
				menor = col2;
				dist = (col1 - col2) - 1;
			}

			//comprobamos si alguna de las celdas entre medias no está borrada, hasta que se complete un número n de celdas igual a la distancia.
			while (dist > 0) {
				if (!(estaBorrada(t, fil1, menor + dist))) {
					res = false;
				}
				dist--;
			}
		}
		else {
			//Se comprueba la posición relativa de las filas en las que están las celdas
			if ( fil1 > fil2 ) {
				//Comprobamos si están en la misma columna para formar pareja vertical
				if (col1 == col2) {
					menor = fil2;
					dist = (fil1 - fil2) - 1;

					//Comprobamos si alguna de las celdas entre medias no está borrada, hasta que se complete un número n de celdas igual a la distancia
					while (dist > 0) {
						if (!(estaBorrada(t, menor + dist, col1))) {
							res = false;
						}
						dist--;
					}
				}
				else {
					//Comprobamos si las celdas pueden formar una pareja diagonal
					if (((fil1-fil2)/(abs(col1-col2)))==1) {
						filAux = fil2;
						colAux = col2;
						if ( col1 < col2 ) {
							//Si la columna mayor es la segunda, se va restando la variable auxiliar de columnas
							dist = abs(col1-col2) - 1;

							while (dist > 0){
								//Ajustamos la siguiente coordenada a comprobar
								filAux++;
								colAux--;
								//Vamos comprobando hasta que se acaben n celdas igual a la distancia
								if (!(estaBorrada(t, filAux, colAux))) {
									res = false;
								}

								dist--;
							}
						}
						else {
							//Si la columna mayor es la primera, se va sumando la variable auxiliar de columnas
							dist = abs(col1-col2) - 1;

							while (dist > 0){
								//Ajustamos la siguiente coordenada a comprobar
								filAux++;
								colAux++;
								//Vamos comprobando hasta que se acaben n celdas igual a la distancia
								if (!(estaBorrada(t, filAux, colAux))) {
									res = false;
								}

								dist--;
							}
						}


					}
					else {
						//Comprobamos si están en filas contiguas para saber si son la última de la fila y la primera de la siguiente
						if ( abs(fil1-fil2) == 1 ) {
							dist = (abs(col2 - t.max_col - 1)) - 2;

							while (dist > 0) {
								//Vamos comprobando hasta que se llegue al final de la fila
								if (!(estaBorrada(t, fil2, col2 + dist))){
									res = false;
								}
								dist--;
							}
							i = 1;
							while (i <= col1) {
								//Vamos comprobando desde el principio de la otra fila hasta que se llegue a la otra celda
								if (!(estaBorrada(t, fil1, col1 - i))){
									res = false;
								}
								i++;
							}
						}
						//Si no se cumple que la posición de las celdas es ninguna válida, no se comprueba si son pareja
						else
							res = false;
					}
				}
			}
			else {
				//Comprobamos si están en la misma columna para formar pareja vertical
				if (col1 == col2) {
					menor = fil1;
					dist = (fil2 - fil1) - 1;

					//Comprobamos si alguna de las celdas entre medias no está borrada, hasta que se complete un número n de celdas igual a la distancia.
					while (dist > 0) {
						if (!(estaBorrada(t, menor + dist, col1))) {
							res = false;
						}
						dist--;
					}
				}
				else {
					//Comprobamos si las celdas pueden formar una pareja diagonal
					if (((fil2-fil1)/(abs(col1-col2)))==1) {
						filAux = fil1;
						colAux = col1;
						if ( col1 < col2 ) {

							dist = abs(col1-col2) - 1;

							//Si la columna mayor es la segunda, se va sumando la variable auxiliar de columnas
							while (dist > 0){
								//Ajustamos la siguiente coordenada a comprobar
								filAux++;
								colAux++;
								//Vamos comprobando hasta que se acaben n celdas igual a la distancia
								if (!(estaBorrada(t, filAux, colAux))) {
									res = false;
								}

								dist--;
							}
						}
						else {

							dist = abs(col1-col2) - 1;

							//Si la columna mayor es la segunda, se va restando la variable auxiliar de columnas
							while (dist > 0){
								//Ajustamos la siguiente coordenada a comprobar
								filAux++;
								colAux--;
								//Vamos comprobando hasta que se acaben n celdas igual a la distancia
								if (!(estaBorrada(t, filAux, colAux))) {
									res = false;
								}

								dist--;
							}
						}


					}
					else {
						//Comprobamos si están en filas contiguas para saber si son la última de la fila y la primera de la siguiente
						if ( abs(fil1-fil2) == 1 ) {
							dist = (abs(col1 - t.max_col - 1)) - 2;

							while (dist > 0) {
								//Vamos comprobando hasta que se llegue al final de la fila
								if (!(estaBorrada(t, fil1, col1 + dist))){
									res = false;
								}
								dist--;
							}
							i = 1;
							while (i <= col2) {
								//Vamos comprobando desde el principio de la otra fila hasta que se llegue a la otra celda
								if (!(estaBorrada(t, fil2, col2 - i))){
									res = false;
								}
								i++;
							}
						}
						//Si no se cumple que la posición de las celdas es ninguna válida, no se comprueba si son pareja
						else
							res = false;
					}
				}
			}
		}
	}

	if (res){
		//Si se ha llegado a la conclusión de que las celdas están en una determinada posición correcta, entonces se comprobará que cumplen la condición numérica para formar pareja (tienen números iguales o la suma de sus números da como resultado 10)
		parej = sonParejaC(t.matriz[fil1][col1], t.matriz[fil2][col2]);
	}
	return parej;
}

bool esFilaBorrada(tablero t, int fil) {
	int i;
	bool bor;
	bor = true;
	for (i = 0; (i < t.max_col) && bor; i++) {
		if (!estaBorrada(t, fil, i) && (!estaVacia(t, fil, i)))
			bor = false;
	}
	return bor;
}

bool replicar(tablero &t) {
	bool rep;
	int i, j, v, f, c;
	f = t.ultFil - 1;
	c = t.ultCol - 1;
	rep = true;
	v = t.celUtl;
	//Recorre la matriz
	for (i = 0; i < t.ultFil; i++) {
		for (j = 0; j < t.max_col; j++) {
			//Si la celda no está vacia, ni borrada, ni hemos llegado al doble de celdas útiles (después del replicar)
			if (!estaVacia(t, i, j) && !estaBorrada(t, i, j) && (v != (t.celUtl * 2))) {
				//Si llega a la última fila (nótese que es t.max_fil, la siguiente de la última fila visible en el tablero)
				if (f != t.max_fil) {
					if (c == t.max_col - 1) {
						//Estamos en la columna máxima, saltamos a la primera y aumentamos en 1 el contador de filas.
						f++;
						c = 0;
					} else {
						c++;
					}
					//Escribimos el nuevo número replicado.
					ponerNumCelda(t, f, c, obtenerNumeroCelda(t.matriz[i][j]));
				} else {
					rep = false;
				}
				//Aumentamos en 1 las celdas útiles
				v++;
			}
		}
	}
	//Actualizamos los valores de la coordenada de la última celda y de las celdas útiles
	t.ultFil = f + 1;
	t.ultCol = c + 1;
	t.celUtl *= 2;
	return rep;
}

