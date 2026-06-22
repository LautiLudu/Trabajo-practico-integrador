#include <iostream>
#include "juego.h"
;
using namespace std;

void jugar()
{   system("cls");

    ///nombre del usuario
    string nombre;

    cout << "Nombre: ";
    cin >> nombre;

    cout << "BIENVENIDOS A CAZADORES DE TORMENTAS, " << nombre << endl;

    system("pause");
    system("cls");

    int const cantRondas = 3;

    for(int ronda = 1; ronda <= cantRondas; ronda++){

    srand(time(NULL));

    cout << "Comienza la ronda " << ronda << endl;

    ///generacion aleatoria de los bloqueadores, nunca salen dos iguales gracias al while
    int viento1 = rand()%6+1;
    int viento2 = rand()%6+1;

    while(viento1 == viento2){
    viento2= rand()%6+1;
}

    cout << "Los bloqueadores de viento son: " << viento1 << " y " << viento2 << endl;

    ///generamos los 5 dados iniciales del usuario
    int cantDados = 5;
    int dados[5] = {0};

    cout << "Tus dados son: ";
    generarDados(dados, cantDados);

    for(int i = 0; i < cantDados; i++)
    {
    cout << dados[i] << " ";

    }
    cout << endl;

    int bloqueados = contBloqueados(dados, cantDados, viento1, viento2);

    cout << "Los dados bloqueados son: " << bloqueados << ", asi que NO sumaran puntos" << endl;

    int ptsTirada = calcularPts(dados, cantDados, viento1, viento2);

    cout << "Puntos obtenidos en esta tirada: " << ptsTirada << endl;

     while(true){


     }
   }
}

    void generarDados(int dados[], int cantDados){

    ///la cantidad de dados va a variar dependiendo de la suerte del usuario
    for(int i = 0; i < cantDados; i++)
    {
        dados[i] = rand()%6+1;
    }
}

    ///si el dado NO es bloqueado, se suma su puntaje
    int calcularPts(int dados[],int cantDados, int viento1, int viento2){
    int puntos = 0;

    for(int i = 0; i < cantDados; i++)
    {
        if(dados[i] != viento1 && dados[i] != viento2)
        {
            puntos += dados[i];
        }
    }
    return puntos;
}

    ///si el dado es bloqueado, el contador sube
    int contBloqueados(int dados[], int cantDados, int viento1, int viento2){
    int bloqueados = 0;

    for(int i = 0; i < cantDados; i++)
    {
        if(dados[i] == viento1 || dados[i] == viento2){
            bloqueados++;
        }

    } return bloqueados;
}
