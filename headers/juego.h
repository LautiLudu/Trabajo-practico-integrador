#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <iostream>

using namespace std;

/// declaracion de funciones
int jugar(string nombre, string &nombreReco, int &puntajeRec);
void jugar2(string &nombreRec, int &puntajeRec);

void generarDados(int dados[], int cantDados);
void mostrarDados(int dados[], int cantDados);

int calcularPts(int dados[],int cantDados, int viento1, int viento2);
int contBloqueados(int dados[], int cantDados, int viento1, int viento2);

bool tormentaPerfecta(int dados[], int cantDados, int viento1, int viento2);

void separacion();

int calcularPtsS(int dadosSimulados[], int cantDadosSimulados, int vientoS1, int vientoS2);

#endif // JUEGO_H_INCLUDED
