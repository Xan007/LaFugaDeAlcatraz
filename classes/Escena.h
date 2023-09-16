#ifndef ESCENA_H
#define ESCENA_H

#include <string>
#include <vector>
using namespace std;

class Escena
{
public:
    Escena();

    int indx_narracion;

    vector<string> narraciones;
    vector<string> decisiones;
    vector<Escena> sig_escenas;

    void mostrar_narracion();   // Muestra el string en el indice de la historia.
    bool siguiente_narracion(); // Actualiza el indice de narracion o decide si mostrar opciones.
    bool mostrar_decisiones();  // Muestra las decisiones

    ~Escena();
};

#endif