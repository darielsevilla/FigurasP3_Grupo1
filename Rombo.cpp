#include "Rombo.h"
Rombo::Rombo() {

}

Rombo::Rombo(int a, int d, int D) {
	this->a = a; 
	this->d = d;
	this->D = D;
}

int Rombo::area() {
	return 4 * a;
}

int Rombo::perimetro() {
	return (D * d) / 2;
}

void Rombo::Dibujar() {

}
