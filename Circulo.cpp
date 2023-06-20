#include "Circulo.h"
Circulo::Circulo() {

}

Circulo::Circulo(int r) {
	this->r = r;
}

int Circulo::area() {
	return (int)((double)(r * r) * 3.14);
}

int Circulo::perimetro() {
	return (int)((double) 2 * r * 3.14);

}

void Circulo::Dibujar() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "spanish");

	string pattern_peri = R"(\{2\*P\*[r]{3}\})";
	string pattern_r = R"(\{r{3}\})";
	string pattern_prod = R"(\{r{3}\^2\})";
	string pattern_area = R"(\{P\*r{3}\^2\})";

	regex regex_r(pattern_r);
	regex regex_perimetro(pattern_peri);
	regex regex_prod(pattern_prod);
	regex regex_area(pattern_area);

	//numeros
	string elemento_r = atributoEspaciado(to_string(r), r);
	string elemento_perimetro = perimetroEspaciado(" " + to_string(perimetro()) + " ", perimetro());
	string elemento_prod = perimetroEspaciado(to_string(r * r), (r * r));
	string elemento_area;
	if (area() > 9999999)
		elemento_area = perimetroEspaciado(to_string(area()) + " ", area());
	else
		elemento_area = perimetroEspaciado(" " + to_string(area()) + " ", area());

	//caracteres especiales
	string apostrophePatterns = R"(\Ã­)";
	string apostropheArea = R"(\Ã)";

	regex apostrophe_i{ apostrophePatterns };
	regex apostrophe_a{ apostropheArea };

	fstream file("Circulo.txt", ios::in);
	string line;
	if (file) {
		while (getline(file, line)) {
			line = regex_replace(line, apostrophe_i, "í");
			line = regex_replace(line, apostrophe_a, "Á");
			line = regex_replace(line, regex_perimetro, elemento_perimetro);
			line = regex_replace(line, regex_r, elemento_r);
			line = regex_replace(line, regex_prod, elemento_prod);
			line = regex_replace(line, regex_area, elemento_area);
			cout << line << endl;
		}

	}
	file.close();
}