#include "Escena.h"
#include "../Historia.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Devuelve el nuevo indice de la historia, toma como parametro
// el indice de decision a historia y la decision tomada
// si devuelve -1 es que no se encontro la decisión
int next_indx_historia(string &indx_decision_historia, int decision_tomada)
{
    int i = 0;
    string delimiter = " "; // Delimitador

    int start, end = -delimiter.size();
    do
    {
        start = end + delimiter.size();
        end = indx_decision_historia.find(delimiter, start);

        if (end != -1)
        {
            if (i == decision_tomada)
                return stoi(indx_decision_historia.substr(start, end - start));
            i++;
        } else if (start >= 0) {
            return stoi(indx_decision_historia.substr(start));
        }

    } while (end != -1);

    return -1;
}

Escena ::Escena()
{
    decisiones = {};
    narracion = {};

    indx_narracion = 0;
    indx_historia = 0;
    actualizar_narraciones();
    actualizar_decisiones();
};

Escena ::Escena(vector<int> camino_inicial, int indx_narracion)
{
    indx_historia = camino_inicial.back();
    actualizar_narraciones();
    actualizar_decisiones();

    // Valida el indice dentro del tamaño de la narración
    indx_narracion = indx_valido(indx_narracion) ? indx_narracion : 0;
};

// Actualiza la lista de narracion en base a indx_historia
void Escena ::actualizar_narraciones()
{
    narracion = narracion_decision[indx_historia];
}

void Escena ::actualizar_decisiones()
{
    if (narracion[narracion.size() - 1] == "F") return;

    int indx = stoi(narracion[narracion.size() - 1]);
    decisiones = decision_narracion[indx];
}

void Escena ::mostrar_narracion()
{
    cout << narracion[indx_narracion] << endl;
}

bool Escena ::siguiente_narracion()
{
    if (indx_valido(indx_narracion + 1))
        indx_narracion += 1;
    else
    {
        if (narracion[narracion.size() - 1] == "F")
            es_final = true;
        else
            return false;
    }

    return true;
}

void Escena ::mostrar_decisiones()
{
    cout << "Que decision tomas?\n\n";

    int i = 1;
    for (auto it = decisiones.begin(); it != decisiones.end() - 1; it++)
    {
        cout << i << ". " << (*it) << endl;
        i++;
    }
}

bool Escena ::tomar_decision(int decision_tomada)
{
    int new_indx_historia = next_indx_historia(decisiones[decisiones.size() - 1], decision_tomada);

    if (new_indx_historia < 0)
        return false;

    indx_historia = new_indx_historia;
    indx_narracion = 0;
    decisiones = {};

    actualizar_narraciones();
    actualizar_decisiones();
        

    return true;
}

bool Escena ::indx_valido(int indx_validar) { return indx_narracion < narracion.size() - 2; }