//============================================================================
// Name        : pr_celda.cpp
// Author      : Manuel Alonso González y José Manuel de Torres Domínguez
// Version     : Ampliaciones 1 y 2.
// Copyright   : JMDTDMAG (C) 2023
// Description : Conjunto de pruebas del TAD Celda
//============================================================================

#include "TADCelda.h"
#include "pr_celda.h"

void prueba_TADCelda() {
	celda c;
	celda d;
	celda s;
	celda t;
	celda v;
	celda u;
	
	cout << "prueba_TADCelda: INICIO DE PRUEBAS" << endl << endl << endl;

	cout << "prubea_obtenerNumeroCelda: INICIO DE PRUEBA" << endl << endl;
	
	cout << "Creamos una nueva celda 'c' y le asignamos el valor '3'." << endl << endl;
	
	crearCelda(c, 3);
	cout << "Si utilizamos el módulo obtenerNumeroCelda con la celda 'c' y lo mostramos por pantalla se muestra: {" << obtenerNumeroCelda(c) << "}." << endl << endl;
	
	cout << "prueba_obtenerNumeroCelda: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_esVaciaCelda: INICIO DE PRUEBA" << endl << endl;

	cout << "Ahora creamos una celda 'd' vacía." << endl << endl;
	crearCeldaVacia(d);

	cout << "Si utilizamos el módulo esVaciaCelda con la celda 'd' nos debería devolver 'true' y nos devuelve: {";
	if (esVaciaCelda(d)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "}." << endl << endl;

	cout << "Si utilizamos el módulo esVaciaCelda con la celda 'c' nos debería devolver 'false' y nos devuelve: {";
	if (esVaciaCelda(c)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "}." << endl << endl;

	cout << "prueba_esVaciaCelda: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_esBorradaCelda: INICIO DE PRUEBA" << endl << endl;

	cout << "Si utilizamos el módulo esBorradaCelda con la celda 'c' nos debería devolver 'false' y nos devuelve: {";
	if (esBorradaCelda(c)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "}." << endl << endl;

	cout << "Si utilizamos el módulo borrarNumeroCelda con la celda 'c' y utilizamos el módulo esBorradaCelda nos debería devolver 'true' y nos devuelve: {";
	borrarNumeroCelda(c);
	if (esBorradaCelda(c)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "}." << endl << endl;

	cout << "prueba_esBorradaCelda: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_sonPareja: INICIO DE PRUEBA" << endl << endl;

	cout << "Creamos una celda 's' con valor '6', una celda 't' con valor '8', una celda 'u' con valor '2' y una celda 'v' con valor '8'." << endl << endl;
	crearCelda(s, 6);
	crearCelda(t, 8);
	crearCelda(v, 8);
	crearCelda(u, 2);

	cout << "Si utilizamos el módulo sonPareja con las celdas 's' y 't' nos debería devolver 'false' y nos devuelve: {";
	if (sonParejaC(s,t)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "}." << endl << endl;

	cout << "Si utilizamos el módulo sonPareja con las celdas 't' y 'v' nos debería devolver 'true' y nos devuelve: {";
	if (sonParejaC(t,v)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "}." << endl << endl;

	cout << "Si utilizamos el módulo sonPareja con las celdas 'u' y 't' nos debería devolver 'true' y nos devuelve: {";
	if (sonParejaC(u, t)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << "}." << endl << endl;

	cout << "prueba_sonPareja: FIN DE PRUEBA" << endl << endl << endl;

	cout << "prueba_TADCelda: FIN DE PRUEBAS" << endl << endl << endl;
}

