#include <iostream>
#include <string>
#include <windows.h> // Usado para limpiar la consola

#include "./Classes/Juego.h"
#include "./Classes/Escena.h"
#include "./Classes/Historia.h"

#include "Escenas.h" // Almacena la escena inicial.

using namespace std;

int main()
{
    Escena inicio = obtener_escena_inicial(); // Función definida en Escenas.h

    // Variable que decide si el jugador quiere seguir jugando o no
    bool jugando = true;

    do
    {
        system("cls");
        Juego Alcatraz = Juego(inicio);                     // Inicia el juego con la escena inicial
        Historia &historiaJuego = Alcatraz.historia_actual; // Referencia a la historia

        Escena &escenaJuego = historiaJuego.escena_actual; // Referencia a la escena actual

        cout << "===================================" << endl;
        cout << "Bienvenido a la fuga de Alcatraz" << endl;
        cout << "- Toma decisiones para escapar de Alcatraz, una prision de maxima seguridad en una isla remota." << endl;
        cout << "===================================" << endl
             << endl;

        // Bucle principal encargado de mostrar las siguientes
        // narraciones, decidir cuando se llega a un final
        // y cuando es momento de pedir decisiones y cambiar la escena
        while (true)
        {
            cout << "* ";
            escenaJuego.mostrar_narracion(); // Muestra la narracion actual

            // Si existe una narracion más, saltese la iteración
            if (escenaJuego.siguiente_narracion())
                continue;

            // A partir de aca se llegó a la ultima narracion
            // Si no se pueden mostrar decisiones significa que no hay
            // y por lo tanto es un final.
            if (!escenaJuego.mostrar_decisiones())
            {
                cout << "\n==> Has llegado a un final. Muchas gracias por jugar. Juega otra vez para descubrir mas finales!\n";
                break;
            }

            // A partir de aca esta mostrando las decisiones
            // Primero pide una decisión, el resultado se pasa
            // a la funcion tomar_decision para actualizar la escena
            
            // Si no se puede tomar la decisión significa que hay un error
            // en la creación de la historia
            if (!historiaJuego.tomar_decision(Alcatraz.pedir_decision()))
                cout << "Hay un error en la historia.\n";
                break;

            cout << "===================================\n\n";
        }

        do
        {
            string respuesta = "";
            cout << "\nDesea reiniciar el juego? (s/n): ";

            getline(cin >> ws, respuesta);

            // Se salta la iteración si no es una opcion valida
            if (respuesta != "s" && respuesta != "n")
                continue;

            // Si es no, se termina el programa
            if (respuesta == "n")
                jugando = false;

            // Rompe el bucle asi hubiera dicho si o no
            break;
        } while (true);
    } while (jugando); // Repetir mientras jugando sea verdadero
}