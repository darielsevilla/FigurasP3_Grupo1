#include "Funciones.h"
#include <locale.h>
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "spanish");
    string opcion_seleccionada = (argc > 1) ? argv[1] : "";
    accion(opcion_seleccionada, argv, argc);
}

