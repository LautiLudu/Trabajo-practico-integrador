#include <iostream>
#include "juego.h"
#include <clocale>

using namespace std;

void jugar2(string &nombreRec, int &puntajeRec){
    int ptsJugador1 = 0;
    int ptsJugador2 = 0;

    string jugador1;
    string jugador2;

    system("cls");

    cout << "Ingrese el nombre del jugador 1: ";
    cin >> jugador1;

    cout << "Ingrese el nombre del jugador 2: ";
    cin >> jugador2;

    cout << "Presione cualquier tecla para empezar" << endl;
    system("pause > nul");

    ptsJugador1 = jugar(jugador1, nombreRec, puntajeRec);

    cout << "Presione cualquier tecla para seguir con las rondas de " << jugador2 << endl;
    system("pause > nul");

    ptsJugador2 = jugar(jugador2, nombreRec, puntajeRec);

    cout << "Resultados finales: " << endl;
    cout << jugador1 << ": " << ptsJugador1 << " puntos" << endl;
    cout << jugador2 << ": " << ptsJugador2 << " puntos" << endl;

    separacion();

    if(ptsJugador1 > ptsJugador2){
    cout << "¡Gana " << jugador1 << "!" << endl;

    }else{
        if(ptsJugador2 > ptsJugador1){
            cout << "¡Gana " << jugador2 << "!"<< endl;

        }else{
        cout << "Empate" << endl;
        }
}
    separacion();

    cout << "Presione cualquier tecla para volver al menu";
    system("pause > nul");
}
