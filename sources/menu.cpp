#include <iostream>
#include "menu.h"
#include "juego.h"
#include <clocale>

using namespace std;

///tarea de las funciones
void menuOpciones()
{

    cout << "----------------------------" << endl;
    cout << "** CAZADORES DE TORMENTAS **" << endl;
    cout << "----------------------------" << endl;
    cout << " 1 - MODO UN JUGADOR        " << endl;
    cout << " 2 - MODO DOS JUGADORES     " << endl;
    cout << " 3 - ESTADÍSTICAS           " << endl;
    cout << " 4 - CRÉDITOS               " << endl;
    cout << " 0 - SALIR                  " << endl;
    cout << "ELIGIR OPCIÓN: ";
}

void menuPrincipal(){
    string nombreRec = "";
    int puntajeRec = 0;

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
        system("cls");
        string nombre;

        cout << "Ingrese su nombre: ";
        cin >> nombre;

        ///llamamos a la funcion jugar al apretar el 1
        jugar(nombre, nombreRec, puntajeRec);

        cout << "Presione cualquier tecla para volver al menu" << endl;
        system("pause > nul");
        }
        break;
        case 2:
        {
        jugar2(nombreRec, puntajeRec);
        }
        break;
        case 3:
        {
        estadisticas(nombreRec, puntajeRec);
        }
        break;
        case 4:
        {
        creditos();
        }
        break;
        case 0:
        {
        cout << "Gracias por jugar!" << endl;
        return;
        }
        break;
        case 777:
        {
        modoSimulado();
        }
        break;
        default:
        cout << "Opcion invalida"<< endl;
        system ("pause");
        }

    }
}
void creditos(){
    system("cls");

    cout << "------------------------------" << endl;
    cout << "**         CRÉDITOS         **" << endl;
    cout << "------------------------------" << endl;
    cout << "EQUIPO: LIGHTNING RUNNERS     " << endl;
    cout << "LEGAJO   APELLIDO   NOMBRE    " << endl;
    cout << "34936    LUDUEÑA    LAUTARO   " << endl;
    cout << "34948    MARTÍNEZ   DYLAN     " << endl;
    cout << "34445    CUMPA      LEONARDO  " << endl;

    cout << "PRESIONE CUALQUIER TECLA PARA VOLVER" << endl;
    system("pause > nul");
}

void estadisticas(string nombreRec, int puntajeRec){

    system("cls");

    cout << "------------------------------------" << endl;
    cout << "**          ESTADÍSTICAS          **" << endl;
    cout << "------------------------------------" << endl;
    if(nombreRec == ""){
        cout << "Todavía no hay partidas jugadas" << endl;
    }
    else{
        cout << "RANKING      JUGADOR     PUNTAJE" << endl;
        cout << "1            " << nombreRec << "     " << puntajeRec  << " puntos" << endl;
    }

    cout << "PRESIONE CUALQUIER TECLA PARA VOLVER" << endl;
    system("pause > nul");
    }


