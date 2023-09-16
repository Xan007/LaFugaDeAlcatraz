#include <iostream>
#include "./Classes/Juego.h"
#include "./Classes/Escena.h"
#include "./Classes/Historia.h"

using namespace std;

int main()
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

    Juego Alcatraz = Juego(inicio);
    Historia &historiaJuego = Alcatraz.historia_actual;

    Escena &escenaJuego = historiaJuego.escena_actual;

    while (true)
    {
        escenaJuego.mostrar_narracion();
        if (!escenaJuego.siguiente_narracion())
        {
            if (!escenaJuego.mostrar_decisiones()) {
                cout << "Has llegado a un final... Felicitaciones!";
                break;
            }

            if (!historiaJuego.tomar_decision(Alcatraz.pedir_decision()))
                cout << "Hay un error en la historia...\n";
        }
    }
}