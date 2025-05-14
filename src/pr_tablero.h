//============================================================================
// Name        : pr_tablero.h
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : Cabecera del Conjunto de pruebas del TAD Tablero
//============================================================================

#ifndef PR_TABLERO_H_
#define PR_TABLERO_H_

#include <iostream>
#include "TADTablero.h"

using namespace std;

/*
prueba_conjuntosBasicos: INICIO DE PRUEBAS


prueba_crearTablero: INICIO DE PRUEBA

Pruebas supervisadas:

Se crea un tablero con 12 filas y 9 columnas, que tenga 5 filas ocupadas.

prueba_crearTablero: FIN DE PRUEBA


prueba_borrarCelda: INICIO DE PRUEBA

Pruebas supervisadas:

Se borra la celda de coordenadas (1, 0).

prueba_borrarCelda: FIN DE PRUEBA


prueba_vaciarCelda: INICIO DE PRUEBA

Pruebas supervisadas:

Se vacia la celda de coordenadas (2, 1).

prueba_vaciarCelda: FIN DE PRUEBA


prueba_obtenerNum: INICIO DE PRUEBA

Pruebas supervisadas:

Obtenemos el valor de la celda en la posición (3, 2).

prueba_obtenerNum: FIN DE PRUEBA


prueba_estaVacia: INICIO DE PRUEBA

Coordenadas				Resultado			estaVacia
-------------------------------------------------
(6, 0)					true				true
(2, 5)					false				false

prueba_estaVacia: FIN DE PRUEBA


prueba_estaBorrada: INICIO DE PRUEBA

Coordenadas			Resultado			estaBorrada
---------------------------------------------------
(1, 0)				true				true
(2, 5)				false				false

prueba_estaBorrada: FIN DE PRUEBA


prueba_conjuntosBasicos: FIN DE PRUEBAS
*/
void prueba_operacionesBasicas();

/*
prueba_borrarFila: INICIO DE PRUEBAS

Pruebas supervisadas:

Borramos la 7 fila.
Borramos la 2 y 3 filas.
Vaciamos las últimas 4 celdas y borramos la 4 fila.

prueba_borrarFila: FIN DE PRUEBAS
*/
void prueba_borrarFila();

/*
prueba_operacionesExtras: INICIO DE PRUEBAS


prueba_obtenerFilCol: INICIO DE PRUEBA

Pruebas supervisadas:

Filas, Columnas				obtenerFilCol
-----------------------------------------
9, 9						9, 9
7, 9						7, 9

prueba_obtenerFilCol: FIN DE PRUEBA


prueba_devolverCoordUltimaCeldaOcupada: INICIO DE PRUEBA

Pruebas supervisadas:

Coordenadas					devolverCoordUltimaCeldaOcupada
-----------------------------------------------------------
(7, 9)						(7, 9)
(7, 6)						(7, 6)

prueba_devolverCoordUltimaCeldaOcupada: FIN DE PRUEBA


prueba_ponerNumCelda: INICIO DE PRUEBA

Pruebas supervisadas:

Ponemos a 1 la fila 4 del tablero.

prueba_ponerNumCelda: FIN DE PRUEBA


prueba_esFilaBorrada: INICIO DE PRUEBA

Fila			Resultado			esFilaBorrada
-------------------------------------------------
6				true				true
7				true				true
8				true				true
9				true				true
10				true				true
11				true				true

prueba_esFilaBorrada: FIN DE PRUEBA


prueba_operacionesExtras: FIN DE PRUEBAS
*/
void prueba_operacionesExtras();

/*
prueba_parejas: INICIO DE PRUEBAS

La siguiente prueba es de carácter manual.
Se creará un tablero aleatorio en el que se deberá elegir manualmente un par.
Introduce, en orden, la coordenada X1, Y1, X2 e Y2 de las dos celdas respectivamente.
El programa responderá en consecuencia a las coordenadas provistas y al estado de las celdas.
Para terminar la ejecución de la prueba, escriba -1 y pulse ENTER.

prueba_parejas: FIN DE PRUEBAS
 */
void prueba_parejas();

/*
 prueba_replicar: INICIO DE PRUEBA

 Pruebas supervisadas:

 Replicamos el tablero, resultado = true.
 Eliminamos las filas 1 y 3 y replicamos el tablero, resultado = true.
 Eliminamos la primera fila y la penúltima y replicamos el tablero, resultado = true.
 Eliminamos las tres últimas celdas de la última fila y replicamos, resultado = true.
 Replicamos el tablero, resultado = false.

 prueba_replicar: FIN DE PRUEBA
 */
void prueba_replicar();

/*  INICIALIZADOR DE LAS PRUEBAS.  */
void pruebas_TADTablero();

#endif /* PR_TABLERO_H_ */



