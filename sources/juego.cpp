#include <iostream>
#include "juego.h"
#include <clocale>

using namespace std;

int jugar(string nombre, string &nombreRecord, int &puntajeRecord){
    int ptsTotales = 0;

    system("cls");

    cout << "Bienvenido a cazadores de tormentas, " << nombre << endl;

    cout << "Presione cualquier tecla para empezar" << endl;
    system("pause > nul");

    system("cls");

    int const cantRondas = 3;

    for(int ronda = 1; ronda <= cantRondas; ronda++){
    int tirada = 0;


    int ptsRonda = 0;

    cout << "** Empieza la ronda " << ronda << " **" << endl;

    ///generacion aleatoria de los bloqueadores, nunca salen dos iguales gracias al while
    int viento1 = rand()%6+1;
    int viento2 = rand()%6+1;

    while(viento1 == viento2){
    viento2= rand()%6+1;
    }

    ///generamos los 5 dados iniciales del usuario
    int cantDados = 5;
    int dados[5] = {0};

    while(true){
    tirada += 1;
    cout << "Tirada número " << tirada << endl;

    cout << "Los dados de viento son: " << viento1 << " y " << viento2 << endl;

    cout << "Tus dados son: ";
    generarDados(dados, cantDados);

    for(int i = 0; i < cantDados; i++){
    cout << dados[i] << " ";
    }

    cout << endl;

    int bloqueados = contBloqueados(dados, cantDados, viento1, viento2);
    int ptsTirada = calcularPts(dados, cantDados, viento1, viento2);
    int cantOriginal = cantDados;
    cantDados -= bloqueados;

    cout << "Hay " << bloqueados << " dados bloqueados. Estos NO sumarán puntos" << endl;

    cout << "En la proxima tirada, tendrás " << cantDados << " dados" << endl;

    if(tormentaPerfecta(dados, cantOriginal, viento1, viento2) == true){
    cout << "------------------------------" << endl;
    cout << "      Tormenta perfecta!      " << endl;
    cout << "Puntos de tirada multiplicados" << endl;
    cout << "------------------------------" << endl;

    ptsTirada *= 2;
    ptsRonda += ptsTirada;

    cout << "pts de esta tirada: " << ptsTirada << endl;

    cout << "pts acumulados en la ronda: " << ptsRonda << endl;

    cout << "Está forzado a seguir jugando si logra una tormenta perfecta" << endl;

    separacion();

    continue;
    }

    if(cantDados == 0){
    cout << "No te quedan dados, los puntos de esta ronda pasan a 0" << endl;
    ptsRonda = 0;

    if(ronda == 3){
        separacion();

        /// 13
        cout << "**           Fin del juego           **" << endl;
        separacion();
    }else{
    separacion();

    /// 17
    cout << "**         Fin de la ronda " << ronda << "         **" << endl;
    separacion();
    }
    break;
    }

    cout << "pts de esta tirada: " << ptsTirada << endl;

    ptsRonda += ptsTirada;

    cout << "pts acumulados en la ronda: " << ptsRonda << endl;

    char opcion;
    cout << "Deasea seguir jugando esta ronda? (S/N): ";
    cin >> opcion;

    separacion();

    while(opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n'){
    cout << "No ingreso un carácter válido (S/N)" << endl;

    cout << "Deasea seguir jugando esta ronda? (S/N): ";
    cin >> opcion;

    separacion();

    }

    if(opcion == 'N' || opcion == 'n'){
    cout << "Fin de la ronda " << ronda << endl;
    separacion();
    break;
    }

    }
    ptsTotales += ptsRonda;
    if(ronda == 3){
    cout << "Han acabado las 3 rondas" << endl;
    cout << "Su puntuación final es de: " << ptsTotales << endl;

    if(ptsTotales > puntajeRecord){
    puntajeRecord = ptsTotales;
    nombreRecord = nombre;
    }
    }

    }
    return ptsTotales;
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

    for(int i = 0; i < cantDados; i++){
        if(dados[i] != viento1 && dados[i] != viento2){
            puntos += dados[i];
        }
    }
    return puntos;
}

    ///si el dado es bloqueado, el contador sube
int contBloqueados(int dados[], int cantDados, int viento1, int viento2){
    int bloqueados = 0;

    for(int i = 0; i < cantDados; i++){
        if(dados[i] == viento1 || dados[i] == viento2){
            bloqueados++;
        }

    }
    return bloqueados;
}
    ///verificamos si todos los dados del usuario son iguales y NO coinciden con los dados de viento
bool tormentaPerfecta(int dados[], int cantDados, int viento1, int viento2){

    ///establecemos un dado de referencia y comparamos los demas valores del vector para definir si son todos iguales
    int referencia = dados[0];

    for(int i = 0; i < cantDados; i++){
        if(dados[i] != referencia){
            ///no hay tormenta perfecta (no son todos iguales)
            return false;
        }


    }if(referencia == viento1 || referencia == viento2){
        return false;
    }
    return true;
}

void separacion(){
    cout << endl;
    cout << "=======================================" << endl;
    cout << endl;
}

int calcularPtsS(int dadosSimulados[], int cantDadosSimulados, int vientoS1, int vientoS2){
    int puntos = 0;

    for(int i = 0; i < cantDadosSimulados; i++){
        if(dadosSimulados[i] != vientoS1 && dadosSimulados[i] != vientoS2){
            puntos += dadosSimulados[i];
        }
    }
    return puntos;
}





void modoSimulado(){
    system("cls");

    int cantDadosSimulados = 5;
    int dadosSimulados[5] = {0};

    int vientoS1, vientoS2;

    cout << "** MODO SIMULADO **" << endl;

    cout << "Presione cualquier tecla para empezar" << endl;
    system("pause > nul");

    system("cls");

    cout << "** MODO SIMULADO **" << endl;

    for(int i = 1; i <= cantDadosSimulados; i++){
    cout << "Valor del dado número " << i << ": ";
    cin >> dadosSimulados[i-1];

    while(dadosSimulados[i-1] < 1 || dadosSimulados[i-1] > 6){

    cout << "Valor inválido. El número debe estar entre 1 y 6." << endl;

    cout << "Ingrese nuevamente el valor del dado número "<< i << ": ";
    cin >> dadosSimulados[i-1];
    }
}

    cout << "Los valores cargados a los dados son: ";

    for(int i = 0; i < cantDadosSimulados; i++){
    cout << dadosSimulados[i] << " ";
    }

    cout << endl;

    cout << "Ingrese el dado de viento número 1: ";
    cin >> vientoS1;

    while(vientoS1 < 1 || vientoS1 > 6){

    cout << "Valor inválido. El número debe estar entre 1 y 6." << endl;

    cout << "Ingrese nuevamente el dado de viento número 1: ";
    cin >> vientoS1;
    }

    cout << "Ingrese el dado de viento número 2: ";
    cin >> vientoS2;

    while(vientoS1 < 1 || vientoS1 > 6){
    cout << "Valor inválido. El número debe estar entre 1 y 6." << endl;

    cout << "Ingrese nuevamente el dado de viento número 2: ";
    cin >> vientoS2;
    }

    cout << "Los dados de viento son: " << vientoS1 << " y " << vientoS2 << endl;

    int ptsTirada = calcularPtsS(dadosSimulados, cantDadosSimulados, vientoS1, vientoS2);

    separacion();

    cout << "Los puntos de esta tirada serían: " << ptsTirada << " puntos" << endl;

    cout << "Presione cualquier tecla para volver al menú" << endl;
    system("pause > nul");

}

