#include "Escena.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Escena ::Escena()
{
    indx_narracion = 0;
    narraciones = {};
    decisiones = {};
    sig_escenas = {};
}

void Escena ::mostrar_narracion()
{
    cout << narraciones[indx_narracion] << endl;
}

bool Escena ::siguiente_narracion()
{
    // Si el siguiente indice de narracion no existe en narraciones
    if (indx_narracion + 1 >= narraciones.size())
        return false; // Llamar a mostrar decisiones y eso...

    indx_narracion += 1;
    return true;
}

bool Escena :: mostrar_decisiones()
{
    // Una escena es un final si no tiene decisiones
    if (decisiones.size() == 0)
        return false;
    
    // Imprimir las decisiones en lista empezando en 1

    cout << "\n=>Toma una decision<=\n\n";

    int i = 1;
    for (auto it = decisiones.begin(); it != decisiones.end(); it++)
    {
        cout << i << ". " << (*it) << endl;
        i++;
    }

    return true;
}

Escena :: ~Escena() {
    narraciones = {};
    decisiones = {};
    sig_escenas = {};
}