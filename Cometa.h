#pragma once
#include "Figura.h"
class Cometa :
    public Figura
{
private:
    int a, b, d, D;
public:
    Cometa();
    Cometa(int, int, int, int);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

