#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include <vector>
using namespace std;

class Juego
{
public:
    Juego();

    // Guarda el indice de los caminos tomados
    int caminos_tomados = {};

    // Cuando indx_historia este en el ultimo elemento de sig_historia, va mostrar las decisiones
    int indx_historia = 0;

    vector<string> actual_historia = {};
    vector<string> sig_decisiones = {}; // Decisiones que debe tomar al finalizar actual historia

    void mostrar_decisiones();          // Muestra las decisiones
    void pedir_decision();              // Pedir decision y verifica que sea correcta, luego llama a actualzar(decision)
    void mostrar_historia();            // Muestra el string en el indice de la historia y actualiza el indice.
    void actualizar(int indx_decision); // Verificar que la decision exista. Añade el camino. Actualiza la historia y siguientes decisiones.
};

#endif