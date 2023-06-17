#include "Circulo.h"
Circulo::Circulo() {

}

Circulo::Circulo(int r) {
	this->r = r;
}

int Circulo::area() {
	return (int)((double)r*3.14);
}

int Circulo::perimetro() {
	return (int)((double)(r*r) * 3.14);
}

void Circulo::Dibujar() {

}