#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include <vector>
#include "Escena.h"
using namespace std;

class Juego
{
public:
    Juego();
    Juego(vector<int> camino_inicial, int indx_narracion);

    // Guarda el indice de los caminos tomados
    vector<int> caminos_tomados;

    Escena escena_actual;

    // El juego mantiene llamando a mostrar_narracion y siguiente_narracion y si 
    // recibe false como resultado va pedir decision

    int pedir_decision(); // Mostrar Pedir al usuario la decision, verificarla, actualzar la escena.
};

#endif