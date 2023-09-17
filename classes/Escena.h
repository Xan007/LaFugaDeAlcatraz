#ifndef ESCENA_H
#define ESCENA_H

#include <string>
#include <vector>
using namespace std;

class Escena
{
public:
    Escena();

    // Lleva la cuenta del indice de la narracion
    int indx_narracion;

    vector<string> narraciones;

    // El indice de decisiones coincide con el indice de sig_escenas
    // Por ejemplo, si se toma la primera decision, la siguiente escena sera la
    // primera de sig_escenas
    vector<string> decisiones;
    vector<Escena> sig_escenas;

    void mostrar_narracion();   // Muestra el string en el indice de la historia.
    bool siguiente_narracion(); // Actualiza el indice de narracion
    bool mostrar_decisiones();  // Muestra las decisiones

    ~Escena();
};

#endif