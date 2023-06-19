#pragma once
#include "Figura.h"
class Trapecio :
    public Figura
{
private:
    int a, b, c, h, B;
public:
    Trapecio();
    Trapecio(int, int, int, int, int);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

