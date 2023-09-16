#include "Historia.h"
#include "Escena.h"
#include <iostream>
using namespace std;

Historia :: Historia() {
    escena_actual = Escena();
};

Historia :: Historia(Escena &escena_inicial) {
    escena_actual = escena_inicial;
}

bool Historia::cambiar_escena(int indx_escena)
{
    if (indx_escena >= escena_actual.sig_escenas.size())
        return false; // Indice invalido

    Escena escena_nueva = escena_actual.sig_escenas[indx_escena];
    escena_actual = escena_nueva;

    return true;
}

bool Historia ::tomar_decision(int indx_decision)
{
    if (indx_decision >= escena_actual.decisiones.size())
        return false; // Indice invalido

    if (!cambiar_escena(indx_decision))
        return false; // El cambio de escena no sirvio, algo esta mal

    return true;
}