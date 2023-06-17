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
#include "Trapezio.h"
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
	else if (opcion_seleccionada == "trapezio")
		figura = new Trapezio(variables[0], variables[1], variables[2], variables[3], variables[4]);
	else
		figura = new Paralelogramo(variables[0], variables[1], variables[2]);

	
	figura->Dibujar();
	delete figura;
}
void impresion_nula() {
	
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

