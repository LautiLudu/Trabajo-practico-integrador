#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <iostream>

using namespace std;

/// declaracion de funciones
void jugar();

void generarDados(int dados[], int cantDados);
void mostrarDados(int dados[], int cantDados);

int calcularPts(int dados[],int cantDados, int viento1, int viento2);
int contBloqueados(int dados[], int cantDados, int viento1, int viento2);

#endif // JUEGO_H_INCLUDED
