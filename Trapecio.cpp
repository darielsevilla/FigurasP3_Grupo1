#include "Trapecio.h"
Trapecio::Trapecio() {}

Trapecio::Trapecio(int a, int b, int c, int h, int B) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->h = h;
	this->B = B;
}

int Trapecio::area() {
	return ((B + b) * h) / 2;
}

int Trapecio::perimetro() {
	return B + b + a + c;
}

void Trapecio::Dibujar() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "spanish");
	string apostrophePatterns = R"(\Ã­)";
	string apostropheArea = R"(\Ã)";

	regex apostrophe_i{ apostrophePatterns };
	regex apostrophe_a{ apostropheArea };

	//VARIABLES: a b c h B
	string pattern_a = R"(\{a{3}\})";
	string pattern_b = R"(\{b{3}\})";
	string pattern_c = R"(\{c{3}\})";
	string pattern_h = R"(\{h{3}\})";
	string pattern_B = R"(\{B{3}\})";
	string pattern_perimetro = R"(\{B\+b\+a\+c\})";
	string pattern_prod = R"(\{B\+b\*h\})";
	string pattern_area = R"(\{B\+b\*h\/2\})";

	regex regex_a(pattern_a);
	regex regex_b(pattern_b);
	regex regex_c(pattern_c);
	regex regex_h(pattern_h);
	regex regex_B(pattern_B);
	regex regex_perimetro(pattern_perimetro);
	regex regex_prod(pattern_prod);
	regex regex_area(pattern_area);

	string elemento_a = atributoEspaciado(to_string(a), a);
	string elemento_b = atributoEspaciado(to_string(b), b);
	string elemento_c = atributoEspaciado(to_string(c), c);
	string elemento_h = atributoEspaciado(to_string(h), h);
	string elemento_B = atributoEspaciado(to_string(B), B);

	string elemento_perimetro = perimetroEspaciado(" " + to_string(perimetro()) + " ", perimetro());
	int prod = ((B + b) * h);
	string elemento_prod = perimetroEspaciado(to_string(prod), prod);
	string elemento_area = areaEspaciada("   " + to_string(area()) + " ", area());
	if (area() > 999999) 
		elemento_area = areaEspaciada(" " + to_string(area()) + " ", area());

	fstream file("Trapecio.txt", ios::in);
	string line;
	if (file) {
		while (getline(file, line)) {
			line = regex_replace(line, regex_a, elemento_a);
			line = regex_replace(line, regex_b, elemento_b);
			line = regex_replace(line, regex_c, elemento_c);
			line = regex_replace(line, regex_h, elemento_h);
			line = regex_replace(line, regex_B, elemento_B);
			line = regex_replace(line, regex_perimetro, elemento_perimetro);
			line = regex_replace(line, regex_prod, elemento_prod);
			line = regex_replace(line, regex_area, elemento_area);
			line = regex_replace(line, apostrophe_i, "í");
			line = regex_replace(line, apostrophe_a, "Á");
			cout << line << "\n";
		}
	}
}