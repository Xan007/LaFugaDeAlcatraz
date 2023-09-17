#include "Juego.h"
#include "Escena.h"

#include <iostream>
using namespace std;

// Constructor por defecto
Juego ::Juego()
{
    historia_actual = Historia();
}

// Constructor por parametro
// Recibe una escena inicial como parametro
Juego ::Juego(Escena &escena_inicial)
{
    historia_actual = Historia(escena_inicial); // Crear una historia que empieza en escena_inicial
}

// Metodo para tomar la entrada de la siguiente decision y la verifica
int Juego ::pedir_decision()
{
    int indx_decision = 0;
    bool ok = false;

    do
    {
        cout << "Ingrese la decision que quiere tomar: ";
        cin >> indx_decision;
        cin.ignore(10000, '\n');

        // Indice dentro del rango de 0 hasta el tamaño de decisiones
        if (indx_decision > 0 && indx_decision <= historia_actual.escena_actual.decisiones.size())
            ok = true;
        else
            cout << "\nEscriba el numero de la decision que va tomar.\n";
    } while (!ok);

    // Se le resta uno para que coincida como indice en el vector
    return indx_decision - 1;
}

Juego ::~Juego()
{
    historia_actual = {};
}