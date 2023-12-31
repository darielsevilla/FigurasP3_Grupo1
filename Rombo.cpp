#include "Rombo.h"
Rombo::Rombo() {

}

Rombo::Rombo(int a, int d, int D) {
	this->a = a; 
	this->d = d;
	this->D = D;
}

int Rombo::area() {
	return (D * d) / 2;
}

int Rombo::perimetro() {
	return 4 * a;
}

void Rombo::Dibujar() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "spanish");

	//regex
	string pattern_a = R"(\{a{3}\})";
	string pattern_d = R"(\{d{3}\})";
	string pattern_D = R"(\{D{3}\})";
	string pattern_perimetro = R"(\{4\*[a]{3}\})";
	string pattern_mult = R"(\[\{D\*dd\}\])";
	string pattern_area = R"(\{D\*d\/[2]\})";

	regex regex_a(pattern_a);
	regex regex_d(pattern_d);
	regex regex_D(pattern_D);
	regex regex_perimetro(pattern_perimetro);
	regex regex_mult(pattern_mult);
	regex regex_area(pattern_area);

	string elemento_a = atributoEspaciado(to_string(a), a);
	string elemento_d = atributoEspaciado(to_string(d), d);
	string elemento_D = atributoEspaciado(to_string(D), D);

	string elemento_area = areaEspaciada(to_string(area()), area());
	if(area()>99999 && area() < 999999)
		elemento_area = areaEspaciada(to_string(area()) + " ", area()); 

	string elemento_perimetro = perimetroEspaciado(to_string(perimetro()), perimetro());

	int mult = (D * d);
	string elemento_mult = to_string((D * d));
	if (mult < 9)
		elemento_mult = "   " + elemento_mult + "    ";
	else if (mult > 9 && mult < 99)
		elemento_mult = "   " + elemento_mult + "   ";
	else if (mult > 99 && mult < 999)
		elemento_mult = "  " + elemento_mult + "   ";
	else if (mult > 999 && mult < 9999)
		elemento_mult =  "  " + elemento_mult + "  ";
	else if(mult > 9999 && mult < 99999)
		elemento_mult = " " + elemento_mult + "  ";
	else if(mult > 99999 && mult < 999999)
		elemento_mult = " " + elemento_mult + " ";
	else if (mult > 999999 && mult < 9999999)
		elemento_mult = elemento_mult + " ";

	//tildes
	string apostrophePatterns = R"(\í)";
	string apostropheArea = R"(\�)";
	regex apostrophe_i{ apostrophePatterns };
	regex apostrophe_a{ apostropheArea };

	//imprime el .txt
	fstream file("Rombo.txt", ios::in);
	string line;
	if (file) {
		while (getline(file, line)) {
			line = regex_replace(line, regex_a, elemento_a);
			line = regex_replace(line, regex_d, elemento_d);
			line = regex_replace(line, regex_D, elemento_D);
			line = regex_replace(line, regex_perimetro, elemento_perimetro);
			line = regex_replace(line, regex_mult, elemento_mult);
			line = regex_replace(line, regex_area, elemento_area);
			line = regex_replace(line, apostrophe_i, "�");
			line = regex_replace(line, apostrophe_a, "�");
			cout << line << endl;
		}

	}
	file.close();
}
