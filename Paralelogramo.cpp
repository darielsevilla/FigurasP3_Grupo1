#include "Paralelogramo.h"
Paralelogramo::Paralelogramo() {

}

Paralelogramo::Paralelogramo(int a, int b, int h) {
	this->a = a;
	this->b = b;
	this->h = h;
}

int Paralelogramo::area() {
	return b * h;
}

int Paralelogramo::perimetro() {
	return 2 * (a + b);
}

void Paralelogramo::Dibujar() {
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
	string pattern_h = R"(\{h{3}\})";
	string pattern_area = R"(\{b\*h\})";
	string pattern_perimetro = R"(\{2\*a\+b\})";
	string pattern_suma_perimetro = R"(\{a\+b\})";

	regex regex_a{ pattern_a };
	regex regex_b{ pattern_b };
	regex regex_h{ pattern_h };
	regex regex_area{ pattern_area };
	regex regex_perimetro{ pattern_perimetro };
	regex regex_suma_perimetro{ pattern_suma_perimetro };

	//ints necesarios
	int area_paralelograma = area();
	int perimetro_paralelograma = perimetro();
	int suma_perimetro = a + b;

	//strings necesarios 
	string elemento_a = to_string(a);
	string elemento_b = to_string(b);
	string elemento_h = to_string(h);
	string elemento_area = to_string(area_paralelograma);
	string elemento_perimetro = to_string(perimetro_paralelograma);
	string elementoSumaPerimetro = to_string(suma_perimetro);
	//espacios necesarios
	elemento_a = atributoEspaciado(elemento_a, a);
	elemento_b = atributoEspaciado(elemento_b, b);
	elemento_h = atributoEspaciado(elemento_h, h);
	elemento_area = areaEspaciada(elemento_area, area_paralelograma);
	elemento_perimetro = perimetroEspaciado(elemento_perimetro, perimetro_paralelograma);

	if (suma_perimetro < 10)
		elementoSumaPerimetro = "  " + elementoSumaPerimetro + "  ";
	else if (suma_perimetro < 100)
		elementoSumaPerimetro = " " + elementoSumaPerimetro + "  ";
	else if (suma_perimetro < 1000)
		elementoSumaPerimetro = " " + elementoSumaPerimetro + " ";
	else if (suma_perimetro < 10000)
		elementoSumaPerimetro = elementoSumaPerimetro + " ";
	//impresion de files
	fstream file("Paralelogramo.txt", ios::in);
	string linea;

	if (file) {
		while (getline(file, linea)) {
			linea = regex_replace(linea, regex_a, elemento_a);
			linea = regex_replace(linea, regex_b, elemento_b);
			linea = regex_replace(linea, regex_h, elemento_h);
			linea = regex_replace(linea, regex_area, elemento_area);
			linea = regex_replace(linea, regex_perimetro, elemento_perimetro);
			linea = regex_replace(linea, regex_suma_perimetro, elementoSumaPerimetro);
			linea = regex_replace(linea, apostrophe_i, "í");
			linea = regex_replace(linea, apostrophe_a, "Á");
			cout << linea << "\n";
		}
	}

	file.close();

}