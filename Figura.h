#pragma once
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;
class Figura
{
protected:
	Figura();
public:
	virtual int area() = 0;
	virtual int perimetro() = 0;
	virtual void Dibujar() = 0;
	string atributoEspaciado(string, int);
	string areaEspaciada(string, int);
	string perimetroEspaciado(string, int);
};

