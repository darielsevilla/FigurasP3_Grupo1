#pragma once
#include <iostream>
#include <map>
#include <string>
#include <iomanip>


#include "Figura.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Rectangulo.h"
#include "Paralelogramo.h"
#include "Circulo.h"
#include "Cometa.h"
#include "Rombo.h"
#include "Trapecio.h"
using namespace std;

void impresion_figura(string opcion_seleccionada, int variables[]) {
	Figura* figura;
	if (opcion_seleccionada == "cuadrado")
		figura = new Cuadrado(variables[0]);
	else if (opcion_seleccionada == "triangulo")
		figura = new Triangulo(variables[0], variables[1], variables[2], variables[3]);
	else if (opcion_seleccionada == "rectangulo")
		figura = new Rectangulo(variables[0], variables[1]);
	else if (opcion_seleccionada == "circulo")
		figura = new Circulo(variables[0]);
	else if (opcion_seleccionada == "rombo")
		figura = new Rombo(variables[0], variables[1], variables[2]);
	else if (opcion_seleccionada == "cometa")
		figura = new Cometa(variables[0], variables[1], variables[2], variables[3]);
	else if (opcion_seleccionada == "trapecio")
		figura = new Trapecio(variables[0], variables[1], variables[2], variables[3], variables[4]);
	else
		figura = new Paralelogramo(variables[0], variables[1], variables[2]);

	
	figura->Dibujar();
	delete figura;
}
void impresion_nula() {
	cout << "Uso: Figuras_Planas.exe ACCION [VARIABLES]" << endl
		<< setw(5) << " " << "Calculos de perímetro y área de Figuras Planas." << endl << setw(5) << " " << "Donde: " << endl
		<< setw(12) << " " << "ACCION:" << endl << setw(21) << " " << "ayuda" << setw(48) << "| Información sobre el uso del programa" << endl << endl 
		<< setw(21) << " " << "triangulo" << setw(25) << "| VARIABLES: a b c h" << endl
		<< setw(21) << " " << "paralelogramo" << setw(19) << "| VARIABLES: a b h" << endl
		<< setw(21) << " " << "rectangulo" << setw(20) << "| VARIABLES: a b" << endl
		<< setw(21) << " " << "cuadrado" << setw(20) << "| VARIABLES: a" << endl
		<< setw(21) << " " << "rombo" << setw(27) << "| VARIABLES: a d D" << endl
		<< setw(21) << " " << "cometa" << setw(28) << "| VARIABLES: a b d D" << endl
		<< setw(21) << " " << "trapecio" << setw(28) << "| VARIABLES: a b c h B" << endl
		<< setw(21) << " " << "circulo" << setw(21) << "| VARIABLES: r" << endl;
}

void accion(string opcion_seleccionada, char** variables, int numero_de_valores) {
	int variables_de_formulas[5];
	bool validacion_de_entrada = false;

	//entradas validas
	map<string, int> entradas{ {"triangulo", 4}, {"paralelogramo", 3}, {"rectangulo", 2}, {"cuadrado", 1}, {"rombo", 3}, {"cometa", 4}, {"trapecio", 5}, {"circulo", 1}};
	
	//validacion de entradas
	for (map<string, int>::iterator iterador = entradas.begin(); iterador != entradas.end(); iterador++)
		if (opcion_seleccionada == iterador->first && (numero_de_valores -2) == iterador->second) validacion_de_entrada = true;

	
	//if de opciones de figuras
	if (validacion_de_entrada) {
		for (int i = 2; i < numero_de_valores; i++) variables_de_formulas[i-2] = atoi(variables[i]);
		impresion_figura(opcion_seleccionada, variables_de_formulas);
	}
	else 
		impresion_nula();
	
}

