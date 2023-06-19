#include "Trapecio.h"
Trapecio::Trapecio() {

}

Trapecio::Trapecio(int a, int b, int c, int h, int B) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->h = h;
	this->B = B;
}

int Trapecio::area() {
	return ((B + b) * h) / 2;
}

int Trapecio::perimetro() {
	return B + b + a + c;
}

void Trapecio::Dibujar() {

}