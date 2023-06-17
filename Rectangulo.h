#pragma once
#include "Figura.h"
class Rectangulo :
    public Figura
{
private:
    int a, b;
public:
    Rectangulo();
    Rectangulo(int a, int b);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

