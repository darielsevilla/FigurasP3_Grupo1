#include "Triangulo.h"
Triangulo::Triangulo() {

}

Triangulo::Triangulo(int a, int b, int c, int h) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->h = h;
}

int Triangulo::area() {
	return (b * h / 2);
}

int Triangulo::perimetro() {
	return a + b + c;
}

void Triangulo::Dibujar() {

}