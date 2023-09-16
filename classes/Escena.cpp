#include "Escena.h"
#include <iostream>
using namespace std;

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
    if (indx_narracion + 1 >= narraciones.size())
        return false; // Llamar a mostrar decisiones y eso...

    indx_narracion += 1;
    return true;
}

bool Escena :: mostrar_decisiones()
{
    if (decisiones.size() == 0)
        return false; // Es un final

    cout << "\nQue decision tomas?\n\n";

    int i = 1;
    for (auto it = decisiones.begin(); it != decisiones.end(); it++)
    {
        cout << i << ". " << (*it) << endl;
        i++;
    }

    return true;
}