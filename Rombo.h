#pragma once
#include "Figura.h"
class Rombo :
    public Figura
{
private:
    int a, d, D;
public:
    Rombo();
    Rombo(int, int, int);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

