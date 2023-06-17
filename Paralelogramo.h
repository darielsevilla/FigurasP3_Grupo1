#pragma once
#include "Figura.h"
class Paralelogramo :
    public Figura
{
private:
    int a, b, h;
public:
    Paralelogramo();
    Paralelogramo(int, int, int);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

