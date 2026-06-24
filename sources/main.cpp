#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
    ///configuracion de texto para los caracteres en español
    setlocale(LC_ALL, "Spanish");

    srand(time(NULL));

    menuPrincipal();

    return 0;
}
