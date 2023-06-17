#pragma once
#include "Figura.h"
class Cuadrado : public Figura
{
private:
	int a;
public:
	Cuadrado();
	Cuadrado(int);
	virtual int area() override;
	virtual int perimetro() override;
	virtual void Dibujar() override;
};

