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
	string patron_area = R"(\{D\*d\/2\})";
	string patron_suma_perimetro = R"(\{a\+b\})";
	string patron_multiplicacion_area = R"(\{DD\*dd\})";

	regex regex_a{ patron_a };
	regex regex_b{ patron_b };
	regex regex_d{ patron_d };
	regex regex_D{ patron_D };
	regex regex_area{ patron_area };
	regex regex_perimetro{ patron_perimetro };
	regex regex_suma_area{ patron_suma_perimetro };
	regex regex_suma_perimetro{ patron_multiplicacion_area };

	//strings de los elementos del cometa
	string elemento_a = to_string(a);
	string elemento_b = to_string(b);
	string elemento_d = to_string(d);
	string elemento_D = to_string(D);
	//string de area y perimetro
	int area_cometa = area();
	int perimetro_cometa = perimetro();
	int suma_perimeter = a + b;
	int mult_area = d * D;

	string elementoArea = to_string(area_cometa);
	string elementoPerimetro = to_string(perimetro_cometa);
	string elementoSumaPerimeter = to_string(suma_perimeter);
	string elementoMultPerimetro = to_string(mult_area);
	
	elemento_a = atributoEspaciado(elemento_a, a);
	elemento_b = atributoEspaciado(elemento_b, b);
	elemento_d = atributoEspaciado(elemento_d, d);
	elemento_D = atributoEspaciado(elemento_D, D);
	//espaciado

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
	if (suma_perimeter < 10)
		elementoSumaPerimeter = "  " + elementoSumaPerimeter + "  ";
	else if (suma_perimeter < 100)
		elementoSumaPerimeter = " " + elementoSumaPerimeter + "  ";
	else if (suma_perimeter < 1000)
		elementoSumaPerimeter = " " + elementoSumaPerimeter + " ";
	else if (suma_perimeter < 10000)
		elementoSumaPerimeter = elementoSumaPerimeter + " ";


	if (mult_area < 10)
		elementoMultPerimetro = "  " + elementoMultPerimetro + "    ";
	else if (mult_area < 100)
		elementoMultPerimetro = "  " + elementoMultPerimetro + "   ";
	else if (mult_area < 1000)
		elementoMultPerimetro = "  " + elementoMultPerimetro + "  ";
	else if (mult_area < 10000)
		elementoMultPerimetro = elementoMultPerimetro + "   ";
	else if (mult_area < 100000)
		elementoMultPerimetro = elementoMultPerimetro + "  ";
	else if(mult_area < 1000000)
		elementoMultPerimetro = elementoMultPerimetro + " ";
	else if(mult_area < 1000000)
		elementoMultPerimetro = elementoMultPerimetro;

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
			
			linea = regex_replace(linea, regex_suma_area, elementoSumaPerimeter);
			linea = regex_replace(linea, regex_suma_perimetro, elementoMultPerimetro);
			cout << linea << "\n";
		}
	}
	file.close();

}