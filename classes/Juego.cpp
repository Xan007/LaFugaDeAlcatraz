#include "Juego.h"
#include "Escena.h"

#include <iostream>
using namespace std;

Juego ::Juego()
{
    caminos_tomados = {};
    escena_actual = Escena();
}

Juego ::Juego(vector<int> camino_inicial, int indx_narracion)
{
    caminos_tomados = camino_inicial;
    escena_actual = Escena(camino_inicial, indx_narracion);
}

int Juego ::pedir_decision()
{
    escena_actual.mostrar_decisiones();

    int indx_decision = 0;
    bool ok = false;

    do
    {
        cout << "Ingrese la decision que quiere tomar: ";
        cin >> indx_decision;
        cin.ignore(10000, '\n');

        if (indx_decision > 0 && indx_decision <= escena_actual.decisiones.size() - 1)
            ok = true;
        else
            cout << "\nEscriba el numero de la decision que va tomar.\n";
    } while (!ok);

    // Se le resta uno para que coincida como indice en el vector
    return indx_decision - 1;
}