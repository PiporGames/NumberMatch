//============================================================================
// Name        : TADJuego.cpp
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : TAD Juego
//============================================================================

#include "TADJuego.h"

bool iniciarPartida(partida &p) {
	/*
	 * SECUENCIA DE ARRANQUE: CARGAR ARCHIVOS
	 */
	int filas, columnas, iniciales, replicas, ayudas, random;
	int m[MAX_FILAS][MAX_COLUMNAS];
	bool cargado;
	tablero t;
	int i, j;

	//Cargamos la configuración a las variables.
	if (entornoCargarConfiguracion(filas, columnas, iniciales, replicas, ayudas, random, m)) {
		p.replicas = replicas;
		p.ayudas = ayudas;
		p.puntuacion = 0;

		if (random != 0) {
			//Si el tablero es random...
			crearTablero(t, filas, columnas, iniciales);
			//Crear un tablero random
		} else {
			//Si el tablero NO es random...
			crearTablero(t, filas, columnas, iniciales);
			//creamos un tablero random, y reemplazamos los números a partir del archivo de configuración.
			for (i = 0; i < iniciales; i++) {
				for (j = 0; j < columnas; j++) {
					ponerNumCelda(t, i, j, m[i][j]);
				}
			}
		}

		p.t = t;

		cargado = true;
	} else {
		cout << "Se ha producido un error en la carga del archivo match.cfg (¿no se encuentra en el directorio de ejecución?)" << endl;
		cargado = false;
	}

	return cargado;
}

int tickPartida(partida p) {
	int numFilasMax, numColumnasMax;
	int utlFilas, utlColumnas;
	int curFil = 0, curCol = 0;
	TipoTecla tecla;
	bool salir = false;
	int exit;

	int x1, y1;
	bool marcado1 = false;
	bool pareja;
	bool sinReplicas = false;
	bool sinAyudas = false;

	bool tableroVacio = false;

	/*
	 * SECUENCIA DE INICIALIZACIÓN: CARGAR ENTORNO
	 */

	obtenerFilColMax(p.t, numFilasMax, numColumnasMax);
	obtenerFilCol(p.t, utlFilas, utlColumnas);

	entornoIniciar(numFilasMax, numColumnasMax);
	int i, j, k, v;
	bool ayuda;
	bool rep = true;
	mostrarTablero(p.t);
	//Copiar datos del tablero a la matriz visible del entorno.
	for (i = 0; i < utlFilas; i++) {
		for (j = 0; j < utlColumnas; j++) {
			entornoPausa(0.075);
			entornoActivarNumero(i, j, obtenerNum(p.t, i, j)); //el número aparece en color negro
		}
	}

	entornoPonerPuntuacion(p.puntuacion, 0);
	entornoMarcarPosicion(curFil, curCol);

	while (!salir) {
		tecla = entornoLeerTecla();
		switch (tecla) {
		case TEnter:
			if (!(estaBorrada(p.t, curFil, curCol) || (estaVacia(p.t, curFil, curCol)))) {
				if (!marcado1) {
					//Asignamos y marcamos primera posición
					x1 = curFil;
					y1 = curCol;
					marcado1 = true;
					entornoSeleccionarPosicion(x1, y1);
				} else {
					//Asignamos segunda posición
					if ((x1 == curFil) && (y1 == curCol)) {
						//si es igual que la primera, desmarcar posición 1.
						marcado1 = false;
						entornoDeseleccionarPosicion(x1, y1);
					} else {
						//Marcamos segunda posición
						entornoSeleccionarPosicion(curFil, curCol);
						entornoPausa(0.1);
						entornoDeseleccionarPosicion(x1, y1);
						entornoDeseleccionarPosicion(curFil, curCol);
						pareja = sonPareja(p.t, x1, y1, curFil, curCol);
						if (pareja) {
							//Si forman pareja, borrar elementos, incrementar puntuación en 1.
							p.puntuacion++;
							entornoPonerPuntuacion(p.puntuacion, 1);
							borrarCelda(p.t, x1, y1);
							borrarCelda(p.t, curFil, curCol);
							if (x1 == curFil) {
								if (esFilaBorrada(p.t, x1)) {
									borrarFila(p.t, x1);
									p.puntuacion += 10;
									entornoPonerPuntuacion(p.puntuacion, 10);
								}
							} else {
								if (x1 < curFil) {
									if (esFilaBorrada(p.t, curFil)) {
										borrarFila(p.t, curFil);
										p.puntuacion += 10;
										entornoPonerPuntuacion(p.puntuacion, 10);
										if (esFilaBorrada(p.t, x1)) {
											borrarFila(p.t, x1);
											p.puntuacion += 10;
											entornoPonerPuntuacion(p.puntuacion, 10);
										}
									} else {
										if (esFilaBorrada(p.t, x1)) {
											borrarFila(p.t, x1);
											p.puntuacion += 10;
											entornoPonerPuntuacion(p.puntuacion, 10);
										}
									}
								} else {
									if (esFilaBorrada(p.t, x1)) {
										borrarFila(p.t, x1);
										p.puntuacion += 10;
										entornoPonerPuntuacion(p.puntuacion, 10);
										if (esFilaBorrada(p.t, curFil)) {
											borrarFila(p.t, curFil);
											p.puntuacion += 10;
											entornoPonerPuntuacion(p.puntuacion, 10);
										}
									} else {
										if (esFilaBorrada(p.t, curFil)) {
											borrarFila(p.t, curFil);
											p.puntuacion += 10;
											entornoPonerPuntuacion(p.puntuacion, 10);
										}
									}
								}
							}
							//código de actualización de entorno
							obtenerFilCol(p.t, utlFilas, utlColumnas);
							for (i = 0; i < numFilasMax; i++) {
								for (j = 0; j < numColumnasMax; j++) {
									entornoPonerVacio(i, j);
									if (!estaVacia(p.t, i, j)) {
										if (estaBorrada(p.t, i, j)) {
											entornoDesactivarNumero(i, j, obtenerNum(p.t, i, j));
										} else {
											entornoActivarNumero(i, j, obtenerNum(p.t, i, j)); //el número aparece en color negro
										}
									}
								}

							}
						}
						//Desmarcamos posiciones.
						mostrarTablero(p.t);
						marcado1 = false;

					}
				}
			}
			entornoMarcarPosicion(curFil, curCol);
			break;

		case TDerecha:
			entornoDesmarcarPosicion(curFil, curCol);
			if (curCol < numColumnasMax - 1)
				curCol++;
			else
				curCol = 0;
			entornoMarcarPosicion(curFil, curCol);
			break;

		case TIzquierda:
			entornoDesmarcarPosicion(curFil, curCol);
			if (curCol > 0)
				curCol--;
			else
				curCol = numColumnasMax - 1;
			entornoMarcarPosicion(curFil, curCol);
			break;

		case TArriba:
			entornoDesmarcarPosicion(curFil, curCol);
			if (curFil > 0)
				curFil--;
			else
				curFil = numFilasMax - 1;
			entornoMarcarPosicion(curFil, curCol);
			break;

		case TAbajo:
			entornoDesmarcarPosicion(curFil, curCol);
			if (curFil < numFilasMax - 1)
				curFil++;
			else
				curFil = 0;
			entornoMarcarPosicion(curFil, curCol);
			break;

		case TF1:
			//comprobamos que todavía quedan replicas disponibles
			if (p.replicas > 0) {
				//Replicamos el tablero
				rep = replicar(p.t);
				//Actualizamos la matriz visible del entorno
				if (rep) { //Si replicar se ha podido completar...
					//Actualizamos los valores de las filas y columnas útiles
					obtenerFilCol(p.t, utlFilas, utlColumnas);
					//recorremos la matriz
					for (i = 0; i < utlFilas; i++) {
						for (j = 0; j < utlColumnas; j++) {
							//vaciamos todas las celdas
							entornoPonerVacio(i, j);
							//vamos comprobando cada celda del tablero, sus propiedades y las vamos escribiendo en la matriz visible del entorno
							if (!estaVacia(p.t, i, j)) {
								if (estaBorrada(p.t, i, j)) {
									entornoDesactivarNumero(i, j, obtenerNum(p.t, i, j));
								} else {
									entornoActivarNumero(i, j, obtenerNum(p.t, i, j)); //el número aparece en color negro
								}
							}
						}
					}
					mostrarTablero(p.t);
				} else {
					//Si replicar no se ha podido completar, enviar solicitud de cierre del juego
					salir = true;
				}
				p.replicas--;
			} else {
				//sin replicas, salir del juego
				sinReplicas = true;
				salir = true;
			}
			break;
		case TF2:
			ayuda = false;
			sinAyudas = false;
			//Se comprueba que queden ayudas
			if (p.ayudas > 0) {
				//Se recorre la matriz
				for (i = 0; (i < numFilasMax) && !ayuda; i++) {
					for (j = 0; (j < numColumnasMax) && !ayuda; j++) {
						//En cada celda nos detenemos a comprobar si forma pareja con las celdas de su misma fila y de filas inferiores
						for (k = i; (k < numFilasMax) && !ayuda; k++) {
							for (v = 0; (v < numColumnasMax) && !ayuda; v++) {
								//No se comprueba si es pareja consigo mismo
								if (!((i==k)&&(j==v))) {
									//No se comprueba si es pareja con celdas borradas o vacías
									if (!estaBorrada(p.t, i, j)&&!estaBorrada(p.t, k, v)){
										ayuda = sonPareja(p.t, i, j, k, v);
									}
								}
							}
						}
					}
				}
				//Si se ha encontrado una pareja se marcan en amarillo
				if (ayuda){
					entornoAyuda(i - 1, j - 1, k - 1, v - 1, 2);
				}
				else {
					entornoMostrarMensaje("No hay parejas", 1.5);
				}
				p.ayudas--;
			}
			//Si no quedan ayudas, se sale del juego
			else {
				salir = true;
				sinAyudas = true;
			}
			break;

		case TSalir:
			salir = true;
			break;

		case TNada:
			break;
		} //Fin de switch

		//condición de victoria - Tablero vacio
		tableroVacio = true;
		for (i = 0; i < numFilasMax; i++) {
			for (j = 0; j < numColumnasMax; j++) {
				if (!(estaVacia(p.t, i, j))) {
					tableroVacio = false;
				}
			}
		}
		if (tableroVacio) {
			salir = true;
		}

	} //Fin de while

	//Códigos de salida
	if (!rep) {
		exit = 1;
	} else if (tableroVacio) {
		exit = 0;
	} else if (sinReplicas) {
		exit = 3;
	} else if (sinAyudas) {
		exit = 4;
	} else {
		exit = 2;
	}
	return exit;
}

void terminarPartida(int exit) {

	switch (exit) {
	case 0:
		entornoMostrarMensajeFin("¡¡ VICTORIA !!");
		break;
	case 1:
		entornoMostrarMensajeFin("No se puede replicar");
		break;
	case 2:
		entornoMostrarMensajeFin("GAME OVER");
		break;
	case 3:
		entornoMostrarMensajeFin("No te quedan replicas");
		break;
	case 4:
		entornoMostrarMensajeFin("No te quedan ayudas");
		break;
	}
	entornoPausa(0.5);
	entornoTerminar();
}
