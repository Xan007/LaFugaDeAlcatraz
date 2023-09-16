#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include <vector>
#include "Escena.h"
#include "Historia.h"
using namespace std;

class Juego
{
public:
    Juego();
    Juego(Escena &escena_inicial);

    Historia historia_actual;

    // El juego mantiene llamando a mostrar_narracion y siguiente_narracion y si 
    // recibe false como resultado va pedir decision

    int pedir_decision(); // Mostrar Pedir al usuario la decision, verificarla, actualzar la escena.

    ~Juego();
};

#endif