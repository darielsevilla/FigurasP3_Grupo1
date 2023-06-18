#include "Rectangulo.h"
Rectangulo::Rectangulo() {

}

Rectangulo::Rectangulo(int a, int b) {
	this->a = a;
	this->b = b;
}

int Rectangulo::area() {
	return a * b;
}

int Rectangulo::perimetro() {
	return (a + b) * 2;
}

void Rectangulo::Dibujar() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "spanish");
	//apostrophes
	string apostrophePatterns = R"(\Ã­)";
	string apostropheArea = R"(\Ã)";

	regex apostrophe_i{ apostrophePatterns };
	regex apostrophe_a{ apostropheArea };


	//regexes de variables
	string pattern_a = R"(\{a{3}\})";
	string pattern_b = R"(\{b{3}\})";
	string pattern_area = R"(\{a\*b\})";
	string pattern_perimetro = R"(\{2\*a\+b\})";
	string pattern_suma_perimetro = R"(\{a\+b\})";

	regex regex_a{ pattern_a };
	regex regex_b{ pattern_b };
	regex regex_area{ pattern_area };
	regex regex_perimetro{ pattern_perimetro };
	regex regex_suma_perimetro{ pattern_suma_perimetro };
	//valores faltantes
	int area_rect = area();
	int perimetro_rect = perimetro();
	int suma_perimetro = a + b;

	//strings de variables
	string elemento_a = to_string(a);
	string elemento_b = to_string(b);
	string elemento_area = to_string(area_rect);
	string elemento_perimetro = to_string(perimetro_rect);
	string elementoSumaPerimetro = to_string(suma_perimetro);
	//Conteo de espacios
	elemento_a = atributoEspaciado(elemento_a, a);
	elemento_b = atributoEspaciado(elemento_b, b);
	elemento_area = areaParalelogramoEspaciada(elemento_area, area_rect);
	elemento_perimetro = perimetroParalelogramoEspaciado(elemento_perimetro, perimetro_rect);
	

	//a+b
	if (suma_perimetro < 10)
		elementoSumaPerimetro = "  " + elementoSumaPerimetro + "  ";
	else if (suma_perimetro < 100)
		elementoSumaPerimetro = " " + elementoSumaPerimetro + "  ";
	else if (suma_perimetro < 1000)
		elementoSumaPerimetro = " " + elementoSumaPerimetro + " ";
	else if (suma_perimetro < 10000)
		elementoSumaPerimetro = elementoSumaPerimetro + " ";

	//impresion de archivo
	fstream file("Rectangulo.txt", ios::in);
	string linea;
	while (getline(file,linea)) {
		
		linea = regex_replace(linea, regex_a, elemento_a);
		linea = regex_replace(linea, regex_b, elemento_b);
		linea = regex_replace(linea, regex_area, elemento_area);
		linea = regex_replace(linea, regex_perimetro, elemento_perimetro);
		linea = regex_replace(linea, regex_suma_perimetro, elementoSumaPerimetro);
		linea = regex_replace(linea, apostrophe_i, "í");
		linea = regex_replace(linea, apostrophe_a, "Á");
		cout << linea << "\n";
	}
	file.close();
}