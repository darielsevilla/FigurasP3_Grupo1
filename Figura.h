#pragma once
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Figura
{
protected:
	Figura();
public:
	virtual int area() = 0;
	virtual int perimetro() = 0;
	virtual void Dibujar() = 0;
};

