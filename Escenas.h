#ifndef ESCENAS_H
#define ESCENAS_H

#include "./Classes/Escena.h"

/* CREACIÓN DE ESCENAS:
Aqui se crea la historia completa
Se conforma por escenas

* Narraciones vector<string>: Es lo que se le cuenta al usuario
* Decisiones vector<string>: Son las decisiones posibles que puede tomar el usuario

sig_escenas vector<Escena>: Es un vector conformado por Escenas. Su indice coincide con el de decisiones
*/

// Devuelve la escena inicial
Escena obtener_escena_inicial()
{
    Escena inicio;
    inicio.narraciones = {"A"};
    inicio.decisiones = {"Respuesta 1"};

    Escena resp1;
    resp1.narraciones = {"B"};
    resp1.decisiones = {"Respuesta 1.1", "Respuesta 1.2"};

    Escena resp11;
    resp11.narraciones = {"C"}; // No tiene decisiones, es un final

    Escena resp12;
    resp12.narraciones = {"D"}; // No tiene decisiones es un final

    resp1.sig_escenas = {resp11, resp12}; // La decision 1 esta ligado a rep11, la 2 a rep12
    inicio.sig_escenas = {resp1};         // La desición 1 esta ligado a resp1

    return inicio;
}

#endif