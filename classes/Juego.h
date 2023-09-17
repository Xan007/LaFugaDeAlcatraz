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
    // Constructor por defecto
    Juego();

    //Constructor por parametro
    Juego(Escena &escena_inicial);

    Historia historia_actual;

    int pedir_decision(); // Pedir al usuario la decision y verificarla

    ~Juego();
};

#endif