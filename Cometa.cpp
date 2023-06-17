#include "Cometa.h"
Cometa::Cometa() {

}

Cometa::Cometa(int a, int b, int d, int D) {
	this->a = a;
	this->b = b;
	this->d = d;
	this->D = D;
}

int Cometa::area() {
	return (D * d) / 2;
}

int Cometa::perimetro() {
	return 2 * (b + a);
}

void Cometa::Dibujar(){
}