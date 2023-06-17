#include "Paralelogramo.h"
Paralelogramo::Paralelogramo() {

}

Paralelogramo::Paralelogramo(int a, int b, int h) {
	this->a = a;
	this->b = b;
	this->h = h;
}

int Paralelogramo::area() {
	return b * h;
}

int Paralelogramo::perimetro() {
	return 2 * (a + b);
}

void Paralelogramo::Dibujar() {

}