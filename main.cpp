#include <iostream>
#include "./Classes/Juego.h"
#include "./Classes/Escena.h"

using namespace std;

Juego Alcatraz = Juego();

int main()
{
    Escena escenaJuego = Alcatraz.escena_actual;

    while (true)
    {
        escenaJuego.mostrar_narracion();
        if (!escenaJuego.siguiente_narracion())
        {
            if (!escenaJuego.tomar_decision(Alcatraz.pedir_decision()))
                cout << "Hay un error en la historia...\n";
        }

        if (escenaJuego.es_final)
        {
            cout << "FIN...";
            break;
        }
    }
}