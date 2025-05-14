//============================================================================
// Name        : pr_tablero.cpp
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : Conjunto de pruebas del TAD Tablero
//============================================================================

#include "TADCelda.h"
#include "TADTablero.h"
#include "pr_tablero.h"

void prueba_operacionesBasicas() {
	tablero t;

	cout << "prueba_operacionesBasicas: INICIO DE PRUEBAS" << endl << endl << endl;

	cout << "prueba_crearTablero: INICIO DE PRUEBA" << endl << endl;
	cout << "Creamos un tablero 't' e incializamos el tablero 't' con valores aleatorios en las 5 primeras filas con crearTableroAleatorio(t)." << endl << endl;
	crearTablero(t, 0, 0, 5);
	cout << "Los valores del tablero deberían ser todos vacios (V) excepto las 5 primeras lineas (números aleatorios entre 1 y 9):" << endl << endl;
	mostrarTablero(t);
	cout << endl << "prueba_crearTablero: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_borrarCelda: INICIO DE PRUEBA" << endl << endl;
	cout << "Borramos la celda con las coordenadas (1,0). La posición de dicha celda debería mostrarse como '(valor)'. El tablero queda ahora así:" << endl << endl;
	borrarCelda(t, 1, 0);
	mostrarTablero(t);
	cout << endl << "prueba_borrarCelda: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_vaciarCelda: INICIO DE PRUEBA" << endl << endl;
	cout << "Vaciamos la celda con las coordenadas (2,1). La posición de dicha celda debería mostrarse como 'V'. El tablero queda ahora así:" << endl << endl;
	vaciarCelda(t, 2, 1);
	mostrarTablero(t);
	cout << endl << "prueba_vaciarCelda: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_obtenerNum: INICIO DE PRUEBA" << endl << endl;
	cout << "Obtenemos el número contenido en la celda (3,2), que nos devuelve '" << obtenerNum(t, 3, 2) << "'." << endl << endl;
	cout << "pueba_obtenerNum: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_estaVacia: INICIO DE PRUEBA" << endl << endl;
	cout << "Comprobamos si la celda (6,0) está vacía, en cuyo caso debería devolver 'true', y devuelve: '";
	if (estaVacia(t, 6, 0)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "'." << endl << endl;
	cout << "Comprobamos si la celda (2,5) está vacía, en cuyo caso debería devolver 'false', y devuelve: '";
	if (estaVacia(t, 2, 5)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "'." << endl << endl;
	cout << "prueba_estaVacia: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_estaBorrada: INICIO DE PRUEBA" << endl << endl;
	cout << "Comprobamos si la celda (1,0) está borrada, en cuyo caso debería devolver 'true', y devuelve: '";
	if (estaBorrada(t, 1, 0)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "'." << endl << endl;
	cout << "Comprobamos si la celda (2,5) está borrada, en cuyo caso debería devolver 'false', y devuelve: '";
	if (estaBorrada(t, 2, 5)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "'." << endl << endl;
	cout << "prueba_estaBorrada: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_operacionesBasicas: FIN DE PRUEBAS" << endl << endl << endl;
}

void prueba_borrarFila(){
	int i;
	tablero t;
	cout << "prueba_borrarFila: INICIO DE PRUEBAS" << endl << endl;
	cout << "Creamos un tablero con 9 filas iniciales" << endl << endl;
	crearTablero(t, 0, 0, 9);
	mostrarTablero(t);
	cout << endl << endl << "Borramos todas las celdas de la 7ª fila:" << endl << endl;
	borrarFila(t, 6);
	mostrarTablero(t);
	cout << endl << endl << "Borramos las celdas de las filas 2 y 3:" << endl << endl;
	borrarFila(t, 1);
	borrarFila(t, 1);
	mostrarTablero(t);
	cout << endl << endl << "Ahora vaciamos las últimas 4 celdas de la última fila y borramos todas las celdas de la 4ª fila:" << endl << endl;
	for (i = t.max_col-4; i < t.max_col; i++){
		vaciarCelda(t, t.ultFil-1, i);
	}
	borrarFila(t, 3);
	mostrarTablero(t);
	cout << endl << endl << "prueba_borrarFila FIN DE PRUEBAS" << endl << endl << endl;

}

void prueba_operacionesExtras(){
	tablero t;
	int a, b, i;

	cout << "prueba_operacionesExtras: INICIO DE PRUEBAS" << endl << endl << endl;

	cout << "prueba_obtenerFilCol: INICIO DE PRUEBA" << endl << endl;
	cout << "Creamos un tablero con 9 filas ocupadas" << endl << endl;
	crearTablero(t, 0, 0, 9);
	mostrarTablero(t);
	cout << endl;
	obtenerFilCol(t, a, b);
	cout << "Tal y como tenemos el tablero, utilizando el módulo de obtenerFilCol, obtenemos que el número de filas útiles es: ";
	cout << a << " y el número de columnas útiles es: " << b << "." << endl << endl;
	borrarFila(t, 8);
	borrarFila(t, 7);
	obtenerFilCol(t, a, b);
	cout << "Ahora probamos a borrar las últimas dos filas." << endl << endl;
	mostrarTablero(t);
	cout << endl << "Nos da que hay " << a << " filas útiles y " << b << " columnas útiles." << endl << endl;
	cout << "prueba_obtenerFilCol: INICIO DE PRUEBA" << endl << endl << endl;

	cout << "prueba_devolverCoordUltimaCeldaOcupada: INICIO DE PRUEBA" << endl << endl;
	cout << "Manteniendo el tablero como lo tenemos anteriormente, utilizamos el módulo devolverCoordUltimaCeldaOcupada." << endl;
	devolverCoordUltimaCeldaOcupada(t, a, b);
	cout << "Nos devuelve que las coordenadas de la última celda ocupada son (" << a << "," << b <<")." << endl;
	cout << "Si borramos las tres últimas celdas." << endl << endl;
	for (i=t.max_col-1;i>t.max_col-4;i--){
		vaciarCelda(t, 6, i);
	}
	mostrarTablero(t);
	devolverCoordUltimaCeldaOcupada(t, a, b);
	cout << endl << "Nos da que la última celda ocupada está en la posición (" << a << "," << b <<")." << endl << endl;
	cout << "prueba_devolverCoordUltimaCeldaOcupada: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_ponerNumCelda: INICIO DE PRUEBA" << endl << endl;
	cout << "Ahora, con el módulo ponerNumCelda, asignaremos el valor 1 a toda la 4 fila." << endl << endl;
	for (i=0;i<t.max_col;i++){
		ponerNumCelda(t, 3, i, 1);
	}
	mostrarTablero(t);
	cout << endl << "prueba_ponerNumCelda: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_esFilaBorrada: INICIO DE PRUEBA" << endl << endl;
	for ( i = t.max_fil-5; i < t.max_fil; i++ ) {
		if (!esFilaBorrada(t, i))
			cout << "Error con la fila " << i << "." << endl;
	}
	cout << "prueba_esFilaBorrada: FIN DE PRUEBA" <<endl << endl << endl;

	cout << endl << "prueba_operacionesExtras: FIN DE PRUEBAS" << endl << endl << endl;

}

void prueba_parejas() {
	cout << "prueba_parejas: INICIO DE PRUEBAS" << endl << endl;
    cout << R"(La siguiente prueba es de carácter manual.
Se creará un tablero aleatorio en el que se deberá elegir manualmente un par.
Introduce, en orden, la coordenada X1, Y1, X2 e Y2 de las dos celdas respectivamente.
El programa responderá en consecuencia a las coordenadas provistas y al estado de las celdas.
Para terminar la ejecución de la prueba, escriba -1 y pulse ENTER.)" << endl;
	bool exit = false;
	tablero t;
	crearTablero(t, 0, 0, 9);
    while (exit == false) {
    	int x1, y1, x2, y2;
		mostrarTablero(t);
		for (int i = 0; i < 4; i++) {
			if (!exit) {
				switch (i) {
				case 0:
					cout << "X1: ";
					cin >> x1;
					if (x1 == -1){
						exit = true;
					}
					break;
				case 1:
					cout << "Y1: ";
					cin >> y1;
					if (y1 == -1){
						exit = true;
					}
					break;
				case 2:
					cout << "X2: ";
					cin >> x2;
					if (x2 == -1){
						exit = true;
					}
					break;
				case 3:
					cout << "Y2: ";
					cin >> y2;
					if (y2 == -1){
						exit = true;
					}
					break;
				}
			}
	    }
		if (exit == false) {
			if (sonPareja(t, x1, y1, x2, y2)) {
				cout << "Este conjunto SI forma pareja." << endl;
			} else {
				cout << "Este conjunto NO forma pareja." << endl;
			}
		} else {
			cout << "Ejecución de prueba terminada por instrucción del usuario." << endl;
		}
    }
    cout << "prueba_parejas: FIN DE PRUEBAS" << endl << endl << endl;
}

void prueba_replicar(){
	tablero t;
	int i;
	cout << "prueba_replicar: INICIO DE LA PRUEBA" << endl << endl;
	cout << "La siguiente prueba es de carácter manual." << endl << "Se creará un tablero aleatorio que se modificará a lo largo de la prueba." << endl << "Supervise que las operaciones del tablero son las correctas." << endl << endl;
	crearTablero(t, 0, 0, 3);
	mostrarTablero(t);
	cout << endl << "Replicamos el tablero." << endl << endl;
	replicar(t);
	mostrarTablero(t);
	cout << endl << "Eliminamos la primera y tercera fila y replicamos." << endl << endl;
	borrarFila(t,2);
	borrarFila(t,0);
	replicar(t);
	mostrarTablero(t);
	cout << endl << "Eliminamos la primera y penúltima fila y borramos las tres últimas celdas de la última fila y replicamos." << endl << endl;
	borrarFila(t,t.ultFil-2);
	borrarFila(t,0);
	for (i = t.max_col-1; i > t.max_col-4; i--){
		vaciarCelda(t, t.ultFil-1, i);
	}
	replicar(t);
	mostrarTablero(t);
	cout << endl << "Replicamos el tablero. Debería devolver 'false'." << endl << endl;
	if (replicar(t)){
		cout << "Error." << endl;
	} else {
		cout << "Correcto. Devuelve 'false'." << endl << endl;
	}
	mostrarTablero(t);
	cout << endl << "prueba_replicar: FIN DE PRUEBAS" << endl << endl << endl;
}

void pruebas_TADTablero(){
	prueba_operacionesBasicas();
	prueba_borrarFila();
	prueba_operacionesExtras();
	prueba_parejas();
	prueba_replicar();
}
