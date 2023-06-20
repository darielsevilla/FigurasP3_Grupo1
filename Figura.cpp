#include "Figura.h"
Figura::Figura() {

}


string Figura::atributoEspaciado(string atributo, int valor) {
	if (valor < 10)
		atributo = "  " + atributo + "  ";
	else if (valor < 100)
		atributo = " " + atributo + "  ";
	else if (valor < 1000)
		atributo = " " + atributo + " ";
	else if (valor < 10000)
		atributo = atributo + " ";

	return atributo;
}

string Figura::areaEspaciada(string area_figura, int area) {
	if (area < 10)
		area_figura = "   " + area_figura + "   ";
	else if (area < 100)
		area_figura = "  " + area_figura + "   ";
	else if (area < 1000)
		area_figura = "  " + area_figura + "  ";
	else if (area < 10000)
		area_figura = " " +  area_figura + "  ";
	else if (area < 100000)
		area_figura = " " + area_figura + " ";
	else if (area < 100000)
		area_figura =  area_figura + " ";
	return area_figura;
}

string Figura::perimetroEspaciado(string perimetro_figura, int perimetro) {
	if (perimetro < 10)
		perimetro_figura = "   " + perimetro_figura + "   ";
	else if (perimetro < 100)
		perimetro_figura = "  " + perimetro_figura + "   ";
	else if (perimetro < 1000)
		perimetro_figura = "  " + perimetro_figura + "  ";
	else if (perimetro < 10000)
		perimetro_figura = " " + perimetro_figura + "  ";
	else if (perimetro < 100000)
		perimetro_figura = " " + perimetro_figura + " ";
	else if (perimetro < 1000000)
		perimetro_figura = perimetro_figura + " ";

	return perimetro_figura;
}