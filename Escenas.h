#ifndef ESCENAS_H
#define ESCENAS_H

#include "./Classes/Escena.h"

Escena obtener_escena_inicial()
{
    Escena inicio;
    inicio.narraciones = {"A"};
    inicio.decisiones = {"Respuesta 1"};

    Escena resp1;
    resp1.narraciones = {"B"};
    resp1.decisiones = {"Respuesta 1.1", "Respuesta 1.2"};

    Escena resp11;
    resp11.narraciones = {"C"};

    Escena resp12;
    resp12.narraciones = {"D"};

    resp1.sig_escenas = {resp11, resp12};
    inicio.sig_escenas = {resp1};

    return inicio;
}

#endif