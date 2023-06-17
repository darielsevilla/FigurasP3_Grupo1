#pragma once
#include "Figura.h"
class Circulo :
    public Figura
{
private:
    int r;
public:
    Circulo();
    Circulo(int);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

