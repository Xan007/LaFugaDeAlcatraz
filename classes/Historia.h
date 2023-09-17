#ifndef HISTORIA_H
#define HISTORIA_H

#include <string>
#include <vector>
#include "Escena.h"

using namespace std;

class Historia
{
public:
    Historia();
    Historia(Escena &escena_inicial);

    // Escena que cambia cada vez que se toma decisiones
    Escena escena_actual;

    // Toma el indice de la escena nueva, verifica y cambia la escena
    bool cambiar_escena(int indx_escena);

    // Toma la decision, verifica y cambia la escena
    bool tomar_decision(int indx_decision);

    ~Historia();
};

#endif