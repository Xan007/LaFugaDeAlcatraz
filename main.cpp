#include <iostream>
#include <string>
#include <windows.h>
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

    bool jugando = true;

    do
    {
        system("cls");
        Juego Alcatraz = Juego(inicio);
        Historia &historiaJuego = Alcatraz.historia_actual;

        Escena &escenaJuego = historiaJuego.escena_actual;

        cout << "===================================" << endl;
        cout << "Bienvenido a la fuga de Alcatraz" << endl;
        cout << "- Toma decisiones para escapar de Alcatraz, una prision de maxima seguridad en una isla remota." << endl;
        cout << "===================================" << endl
             << endl;

        while (true)
        {
            cout << "* ";
            escenaJuego.mostrar_narracion();
            if (escenaJuego.siguiente_narracion())
                continue;

            if (!escenaJuego.mostrar_decisiones())
            {
                cout << "\n==> Has llegado a un final. Muchas gracias por jugar. Juega otra vez para descubrir mas finales!\n";
                break;
            }

            if (!historiaJuego.tomar_decision(Alcatraz.pedir_decision()))
                cout << "Hay un error en la historia.\n";

            cout << "===================================\n\n";
        }

        do
        {
            string respuesta = "";
            cout << "\nDesea reiniciar el juego? (s/n): ";

            getline(cin >> ws, respuesta);

            if (respuesta != "s" && respuesta != "n")
                continue;

            if (respuesta == "n")
                jugando = false;

            break;
        } while (true);
    } while (jugando);
}