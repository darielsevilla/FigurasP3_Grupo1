#include "Triangulo.h"
Triangulo::Triangulo() {

}

Triangulo::Triangulo(int a, int b, int c, int h) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->h = h;
}

int Triangulo::area() {
	return (b * h / 2);
}

int Triangulo::perimetro() {
	return a + b + c;
}

void Triangulo::Dibujar() {
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

	//string patrones y regexes
	string pattern_a = R"(\{a{3}\})";
	string pattern_b = R"(\{b{3}\})";
	string pattern_c = R"(\{c{3}\})";
	string pattern_h = R"(\{h{3}\})";
	string pattern_multiplicacion_area = R"(\{b\*h\})";
	string pattern_area = R"(\{b\*h\/2\})";
	string pattern_perimeter = R"(\{a\+b\+c\})";

	regex regex_a{ pattern_a };
	regex regex_b{ pattern_b };
	regex regex_c{ pattern_c };
	regex regex_h{ pattern_h };
	regex regex_multiplicacion_area{ pattern_multiplicacion_area };
	regex regex_area{ pattern_area };
	regex regex_perimeter{ pattern_perimeter };

	//valores necesarios
	int multiplicacion_area = b * h;
	int area_triangulo = area();
	int perimetro_triangulo = perimetro();

	//strings de elementos
	string elemento_a = to_string(a);
	string elemento_b = to_string(b);
	string elemento_c = to_string(c);
	string elemento_h = to_string(h);
	string elemento_multiplicacion_area = to_string(multiplicacion_area);
	string elemento_area = to_string(area_triangulo);
	string elemento_perimetro = to_string(perimetro_triangulo);
	
	//conteo de espacios
	//a
	if (a < 10)
		elemento_a = "  " + elemento_a + "  ";
	else if (a < 100)
		elemento_a = " " + elemento_a + "  ";
	else if (a < 1000)
		elemento_a = " " + elemento_a + " ";
	else if (a < 10000)
		elemento_a = elemento_a + " ";

	//b
	if (b < 10)
		elemento_b = "  " + elemento_b + "  ";
	else if (b < 100)
		elemento_b = " " + elemento_b + "  ";
	else if (b < 1000)
		elemento_b = " " + elemento_b + " ";
	else if (b < 10000)
		elemento_b = elemento_b + " ";


	//c
	if (c < 10)
		elemento_c = "  " + elemento_c + "  ";
	else if (c < 100)
		elemento_c = " " + elemento_c + "  ";
	else if (c < 1000)
		elemento_c = " " + elemento_c + " ";
	else if (c < 10000)
		elemento_c= elemento_c + " ";
	

	//h
	if (h < 10)
		elemento_h = "  " + elemento_h + "  ";
	else if (h < 100)
		elemento_h = " " + elemento_h + "  ";
	else if (h < 1000)
		elemento_h = " " + elemento_h + " ";
	else if (h < 10000)
		elemento_h = elemento_h + " ";

	//area
	if (area_triangulo < 10)
		elemento_area = "   " + elemento_area + "   ";
	else if (area_triangulo < 100)
		elemento_area = "  " + elemento_area + "   ";
	else if (area_triangulo < 1000)
		elemento_area = "  " + elemento_area + "  ";
	else if (area_triangulo < 10000)
		elemento_area = " " + elemento_area + "  ";
	else if (area_triangulo < 100000)
		elemento_area = " " + elemento_area + " ";
	else if (area_triangulo < 1000000)
		elemento_area = elemento_area + " ";

	//perimetro
	if (perimetro_triangulo < 10)
		elemento_perimetro = "   " + elemento_perimetro + "   ";
	else if (perimetro_triangulo < 100)
		elemento_perimetro = "  " + elemento_perimetro + "   ";
	else if (perimetro_triangulo < 1000)
		elemento_perimetro = "  " + elemento_perimetro + "  ";
	else if (perimetro_triangulo < 10000)
		elemento_perimetro = " " + elemento_perimetro + "  ";
	else if (perimetro_triangulo < 100000)
		elemento_perimetro = " " + elemento_perimetro + " ";
	else if (perimetro_triangulo < 1000000)
		elemento_perimetro = elemento_perimetro + " ";

	//b*h
	if (multiplicacion_area < 10)
		elemento_multiplicacion_area = "  " + elemento_multiplicacion_area + "  ";
	else if (multiplicacion_area < 100)
		elemento_multiplicacion_area = " " + elemento_multiplicacion_area + "  ";
	else if (multiplicacion_area < 1000)
		elemento_multiplicacion_area = " " + elemento_multiplicacion_area + " ";
	else if (multiplicacion_area < 10000)
		elemento_multiplicacion_area = elemento_multiplicacion_area + " ";

	//impresion de archivo
	fstream file("Triangulo.txt", ios::in);
	string linea;
	while (getline(file, linea)) {
		linea = regex_replace(linea, regex_a, elemento_a);
		linea = regex_replace(linea, regex_b, elemento_b);
		linea = regex_replace(linea, regex_c, elemento_c);
		linea = regex_replace(linea, regex_h, elemento_h);
		linea = regex_replace(linea, regex_area, elemento_area);
		linea = regex_replace(linea, regex_perimeter, elemento_perimetro);
		linea = regex_replace(linea, regex_multiplicacion_area, elemento_multiplicacion_area);
		linea = regex_replace(linea, apostrophe_i, "í");
		linea = regex_replace(linea, apostrophe_a, "Á");
		cout << linea << "\n";

	}
	file.close();
}