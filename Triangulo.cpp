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
	string apostrophePatterns = R"(\í)";
	string apostropheArea = R"(\�)";
	string apostropheFigura = R"(��)";

	regex apostrophe_i{ apostrophePatterns };
	regex apostrophe_a{ apostropheArea };
	regex apostrophe_figura{ apostropheFigura };
	//string patrones y regexes
	string pattern_a = R"(\{a{3}\})";
	string pattern_b = R"(\{b{3}\})";
	string pattern_c = R"(\{c{3}\})";
	string pattern_h = R"(\{h{3}\})";
	string pattern_multiplicacion_area = R"(\[\{b\*h\}\])";
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
	
	elemento_a = atributoEspaciado(elemento_a, a);
	elemento_b = atributoEspaciado(elemento_b, b);
	elemento_c = atributoEspaciado(elemento_c, c);
	elemento_h = atributoEspaciado(elemento_h, h);
	
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
		elemento_multiplicacion_area = "   " + elemento_multiplicacion_area + "   ";
	else if (multiplicacion_area < 100)
		elemento_multiplicacion_area = "  " + elemento_multiplicacion_area + "   ";
	else if (multiplicacion_area < 1000)
		elemento_multiplicacion_area = "  " + elemento_multiplicacion_area + "  ";
	else if (multiplicacion_area < 10000)
		elemento_multiplicacion_area = "  " + elemento_multiplicacion_area + " ";
	else if (multiplicacion_area < 100000)
		elemento_multiplicacion_area = " " + elemento_multiplicacion_area + " ";
	else if (multiplicacion_area < 1000000)
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
		linea = regex_replace(linea, apostrophe_i, "�");
		linea = regex_replace(linea, apostrophe_a, "�");
		linea = regex_replace(linea, apostrophe_figura, "�");

		cout << linea << "\n";

	}
	file.close();
}