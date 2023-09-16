#ifndef ESCENA_H
#define ESCENA_H

#include <string>
#include <vector>
using namespace std;

class Escena
{
public:
    Escena();
    Escena(vector<int> camino_inicial, int indx_narracion);

    int indx_narracion, indx_historia;
    bool es_final;

    vector<string> narracion;
    vector<string> decisiones; // Decisiones que debe tomar al finalizar la narracion

    void mostrar_narracion();   // Muestra el string en el indice de la historia.
    bool siguiente_narracion(); // Actualiza el indice de narracion o decide si mostrar opciones.
    void mostrar_decisiones();  // Muestra las decisiones

    bool tomar_decision(int decision_tomada); // Verificar que la decision exista. Añade el camino. Actualiza la historia y siguientes decisiones.

    void actualizar_decisiones();  // Actuaiza las decisiones en base al vector narracion
    void actualizar_narraciones(); // Actuaiza las narraciones en base a indx_narracion

private:
    bool indx_valido(int indx_validar);
};

#endif