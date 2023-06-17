#include "Rectangulo.h"
Rectangulo::Rectangulo() {

}

Rectangulo::Rectangulo(int a, int b) {
	this->a = a;
	this->b = b;
}

int Rectangulo::area() {
	return a * b;
}

int Rectangulo::perimetro() {
	return (a + b) * 2;
}

void Rectangulo::Dibujar() {

}