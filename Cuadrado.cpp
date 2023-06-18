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
	string pattern = R"(\{a{3}\})";
	string patternArea = R"(\{a{3}\*a{3}\})";
	string patternPerimetro = R"(\{4\*a{3}\})";
	//{4*aaa}
	regex rule(pattern);
	regex ruleArea(patternArea); 
	regex rulePerimetro(patternPerimetro);

	string elemento_a = " " + to_string(a) + " ";
	string elemento_area = "   " + to_string(area()) + "   ";
	string elemento_perimetro = "  " + to_string(perimetro()) + "  ";
	//agregas espacios a A
	if (a > 9 && a < 100)
		elemento_a += " ";
	else if (a < 9)
		elemento_a = " " + elemento_a + " ";

	//agregar espacios a area
	if (area() > 9 && area() < 100)
		elemento_area += " ";
	else if (area() < 9)
		elemento_area += " ";

	//agregar espacios a perimetro
	if (perimetro() > 9 && perimetro() < 100)
		elemento_perimetro += " ";
	else if (perimetro() < 9)
		elemento_perimetro += " ";


	fstream file("Cuadrado.txt", ios::in);
	string line;
	if (file) {
		while (getline(file, line)){
			line = regex_replace(line, rule, elemento_a);
			line = regex_replace(line, ruleArea, elemento_area);
			line = regex_replace(line, rulePerimetro, elemento_perimetro);
			cout << line << endl;
		}

	}
    file.close();
}
