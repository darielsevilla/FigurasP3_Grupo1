#include "Cuadrado.h"
Cuadrado::Cuadrado() {

}

Cuadrado::Cuadrado(int a) {
	this->a = a;
}

int Cuadrado::area() {
	return a * a;
}

int Cuadrado::perimetro() {
	return 4 * a;
}

void Cuadrado::Dibujar() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "spanish");
	string pattern = R"(\{a{3}\})";
	string patternArea = R"(\{a{3}\*a{3}\})";
	string patternPerimetro = R"(\{4\*a{3}\})";
	string apostrophePatters = R"(\Ã­)";
	string apostropheArea = R"(\Ã)";
	//{4*aaa}
	regex rule(pattern);
	regex ruleArea(patternArea); 
	regex rulePerimetro(patternPerimetro);
	regex apostrophe(apostrophePatters);
	regex apostrophe2(apostropheArea);
	string elemento_a = to_string(a);
	string elemento_area = " " + to_string(area()) + " ";
	string elemento_perimetro = "  " + to_string(perimetro()) + "  ";
	//agregar espacios a A
	elemento_a = atributoEspaciado(elemento_a, a);

	//agregar espacios a area
	if (area() < 9)
		elemento_area = "   " + elemento_area + "   ";
	else if (area() > 9 && area() < 99)
		elemento_area = "  " + elemento_area + "   ";
	else if (area() > 99 && area() < 999)
		elemento_area = "  " + elemento_area + "  ";
	else if (area() >= 1000 && area() < 9999)
		elemento_area = " " + elemento_area + "  ";
	else if (area() > 9999 && area() < 99999)
		elemento_area = " " + elemento_area + " ";
	else if (area() > 99999 && area() < 999999)
		elemento_area += " ";

	//agregar espacios a perimetro
	if (perimetro() > 9 && perimetro() < 100)
		elemento_perimetro += " ";
	else if (perimetro() < 9)
		elemento_perimetro = " " + elemento_perimetro + " ";
	else if (perimetro() > 999)
		elemento_perimetro = " " + to_string(perimetro()) + "  ";

	fstream file("Cuadrado.txt", ios::in);
	string line;
	if (file) {
		while (getline(file, line)){
			line = regex_replace(line, rule, elemento_a);
			line = regex_replace(line, ruleArea, elemento_area);
			line = regex_replace(line, rulePerimetro, elemento_perimetro);
			line = regex_replace(line, apostrophe, "í");
			line = regex_replace(line, apostrophe2, "Á");
			cout << line << endl;
		}

	}
    file.close();
}
