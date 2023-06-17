#pragma once
#include "Figura.h"
class Trapezio :
    public Figura
{
private:
    int a, b, c, h, B;
public:
    Trapezio();
    Trapezio(int, int, int, int, int);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

