#include <iostream>
#include "menu.h"
#include "juego.h"
;
using namespace std;

///tarea de las funciones
void menuOpciones()
{
    cout << "----------------------------" << endl;
    cout << "** Cazadores de tormentas **" << endl;
    cout << "----------------------------" << endl;
    cout << " 1 - MODO UN JUGADOR        " << endl;
    cout << " 2 - MODO DOS JUGADORES     " << endl;
    cout << " 3 - ESTADISTICAS           " << endl;
    cout << " 4 - CREDITOS               " << endl;
    cout << " 0 - SALIR                  " << endl;
    cout << "ELIGIR OPCION: ";
}

void menuPrincipal()
{
    while(true)
    {
        int opcion;

        system("cls");
        menuOpciones();
        cin >> opcion;

        switch(opcion)
        {
        case 1:
        {
        ///llamamos la funcion jugar al apretar el 1
        jugar();
        }
        break;
        case 2:
        {

        }
        break;
        case 3:
        {

        }
        break;
        case 4:
        {

        }
        break;
        case 0:
        {
            cout << "¡Gracias por jugar!" << endl;
            return;
        }
        break;
        default:
            cout << "Opcion invalida"<< endl;

        }

    }
}
