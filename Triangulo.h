#pragma once
#include "Figura.h"
class Triangulo :
    public Figura
{
private:
    int a,b ,c, h;
    
public:
    Triangulo();
    Triangulo(int, int, int, int);
    virtual int area() override;
    virtual int perimetro() override;
    virtual void Dibujar() override;
};

