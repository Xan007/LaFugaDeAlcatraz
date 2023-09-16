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

    Escena escena_actual;

    bool cambiar_escena(int indx_escena);
    bool tomar_decision(int indx_decision);

    ~Historia();
};

#endif