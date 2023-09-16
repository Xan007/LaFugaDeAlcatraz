#ifndef HISTORIA_H
#define HISTORIA_H

#include <string>
#include <vector>
using namespace std;

const vector<vector<string>> historia = {
    // El ultimo elemento indica de las decisiones siguientes 
    {"Eres ...", "Pasa esto", "Y esto", "0"},
    {"Ya que elegiste opcion 1", "Entonces esto y esto", "1"},
    {"Ya que elegiste opcion 2", "...", "2"},
    {"Ya que... opcion 3", "..."}
};

const vector<vector<string>> decision_historia = {

    // Se separa el ultimo elemento por espacios
    // El primer elemento separado es la nueva historia que se pondra si se elige la opcion 1
    // Lo mismo con lo demas
    {"Opcion 1", "Opcion 2", "Opcion 3", "1 2 3"},
    {"Opcion 1.1", "Opcion 1.2", "Opcion 1.3", " "},

    {"Opcion 2.1", "Opcion 2.2", "Opcion 2.3", " "},
};

#endif