#include "Cometa.h"
Cometa::Cometa() {

}

Cometa::Cometa(int a, int b, int d, int D) {
	this->a = a;
	this->b = b;
	this->d = d;
	this->D = D;
}

int Cometa::area() {
	return (D * d) / 2;
}

int Cometa::perimetro() {
	return 2 * (b + a);
}

void Cometa::Dibujar() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "spanish");
	//apostrophes
	string apostrophePatterms = R"(\Ã­)";
	string apostropheArea = R"(\Ã)";

	regex apostrophe_i{ apostrophePatterms };
	regex apostrophe_a{ apostropheArea };

	//regexes de los otros elementos
	string patron_a = R"(\{a{3}\})";
	string patron_b = R"(\{b{3}\})";
	string patron_d = R"(\{d{3}\})";
	string patron_D = R"(\{D{3}\})";
	string patron_perimetro = R"(\{2\*a\+b\})";
	string patron_area = R"(\{D\+d\/2\})";
	string patron_suma_area = R"(\{a\+b\})";
	string patron_suma_perimetro = R"(\{D\*d\})";

	regex regex_a{ patron_a };
	regex regex_b{ patron_b };
	regex regex_d{ patron_d };
	regex regex_D{ patron_D };
	regex regex_area{ patron_area };
	regex regex_perimetro{ patron_perimetro };
	regex regex_suma_area{ patron_suma_area };
	regex regex_suma_perimetro{ patron_suma_perimetro };

	//strings de los elementos del cometa
	string elemento_a = to_string(a);
	string elemento_b = to_string(b);
	string elemento_d = to_string(d);
	string elemento_D = to_string(D);
	//string de area y perimetro
	int area_cometa = area();
	int perimetro_cometa = perimetro();
	int suma_area = a + b;
	int suma_perimetro = d * D;

	string elementoArea = to_string(area_cometa);
	string elementoPerimetro = to_string(perimetro_cometa);
	string elementoSumaArea = to_string(suma_area);
	string elementoSumaPerimetro = to_string(suma_perimetro);
	
	//espaciado
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

	//d
	if (d < 10)
		elemento_d = "  " + elemento_d + "  ";
	else if (d < 100)
		elemento_d = " " + elemento_d + "  ";
	else if (d < 1000)
		elemento_d = " " + elemento_d + " ";
	else if (d < 10000)
		elemento_d = elemento_d + " ";

	//D
	if (D < 10)
		elemento_D = "  " + elemento_D + "  ";
	else if (D < 100)
		elemento_D = " " + elemento_D + "  ";
	else if (D < 1000)
		elemento_D = " " + elemento_D + " ";
	else if (D < 10000)
		elemento_D = elemento_D + " ";

	//area
	if (area_cometa < 10)
		elementoArea = "   " + elementoArea + "   ";
	else if (area_cometa < 100)
		elementoArea = "  " + elementoArea + "   ";
	else if (area_cometa < 1000)
		elementoArea = "  " + elementoArea + "  ";
	else if (area_cometa < 10000)
		elementoArea = " " + elementoArea + "  ";
	else if (area_cometa < 100000)
		elementoArea = " " + elementoArea + " ";
	else if (area_cometa < 1000000)
		elementoArea = elementoArea + " ";

	//perimetro
	if (perimetro_cometa < 10)
		elementoPerimetro = "   " + elementoPerimetro + "   ";
	else if (perimetro_cometa < 100)
		elementoPerimetro = "  " + elementoPerimetro + "   ";
	else if (perimetro_cometa < 1000)
		elementoPerimetro = "  " + elementoPerimetro + "  ";
	else if (perimetro_cometa < 10000)
		elementoPerimetro = " " + elementoPerimetro + "  ";
	else if (perimetro_cometa < 100000)
		elementoPerimetro = " " + elementoPerimetro + " ";
	else if (perimetro_cometa < 1000000)
		elementoPerimetro = elementoPerimetro + " ";

	//reemplazo de las sumas de en medio
	if (suma_area < 10)
		elementoSumaArea = "  " + elementoSumaArea + "  ";
	else if (suma_area < 100)
		elementoSumaArea = " " + elementoSumaArea + "  ";
	else if (suma_area < 1000)
		elementoSumaArea = " " + elementoSumaArea + " ";
	else if (suma_area < 10000)
		elementoSumaArea = elementoSumaArea + " ";


	if (suma_perimetro < 10)
		elementoSumaPerimetro = "  " + elementoSumaPerimetro + "  ";
	else if (suma_perimetro < 100)
		elementoSumaPerimetro = " " + elementoSumaPerimetro + "  ";
	else if (suma_perimetro < 1000)
		elementoSumaPerimetro = " " + elementoSumaPerimetro + " ";
	else if (suma_perimetro < 10000)
		elementoSumaPerimetro = elementoSumaPerimetro + " ";
	//impresion de figura
	fstream file("Cometa.txt", ios::in);
	string linea;
	if (file) {
		while (getline(file, linea)) {
			linea = regex_replace(linea, regex_a, elemento_a);
			linea = regex_replace(linea, regex_b, elemento_b);
			linea = regex_replace(linea, regex_d, elemento_d);
			linea = regex_replace(linea, regex_D, elemento_D);
			linea = regex_replace(linea, regex_area, elementoArea);
			linea = regex_replace(linea, regex_perimetro, elementoPerimetro);
			linea = regex_replace(linea, apostrophe_i, "í");
			linea = regex_replace(linea, apostrophe_a, "Á");
			
			linea = regex_replace(linea, regex_suma_area, elementoSumaArea);
			linea = regex_replace(linea, regex_suma_perimetro, elementoSumaPerimetro);
			cout << linea << "\n";
		}
	}
	file.close();

}