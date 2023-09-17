#include "Historia.h"
#include "Escena.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Historia :: Historia() {
    escena_actual = Escena();
};

// Constructor por parametro
// Empieza la historia desde la escena inicial
Historia :: Historia(Escena &escena_inicial) {
    escena_actual = escena_inicial;
}

// Se encarga de actualizar la escena actual
bool Historia::cambiar_escena(int indx_escena)
{
    // Si el indice de la nueva escena no está dentro de las escenas
    if (indx_escena >= escena_actual.sig_escenas.size())
        return false;

    // Hace una copia de la siguiente escena desde escena_actual
    Escena escena_nueva = escena_actual.sig_escenas[indx_escena];
    escena_actual = escena_nueva;

    return true;
}

bool Historia ::tomar_decision(int indx_decision)
{
    // Si el indice de decision no esta dentro de las decisiones
    if (indx_decision >= escena_actual.decisiones.size())
        return false;

    // Si no es posible cambiar la escena, significa que hay un error 
    // en la creacion de la historia
    if (!cambiar_escena(indx_decision))
        return false; 

    return true;
}

Historia :: ~Historia() {
    escena_actual = {};
}