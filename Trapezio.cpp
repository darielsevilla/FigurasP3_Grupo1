#include "Trapezio.h"
Trapezio::Trapezio() {

}

Trapezio::Trapezio(int a, int b, int c, int h, int B) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->h = h;
	this->B = B;
}

int Trapezio::area() {
	return ((B + b) * h) / 2;
}

int Trapezio::perimetro() {
	return B + b + a + c;
}

void Trapezio::Dibujar() {

}