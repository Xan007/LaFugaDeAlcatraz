#ifndef HISTORIA_H
#define HISTORIA_H

#include <string>
#include <vector>
using namespace std;

const vector<vector<string>> narracion_decision = {
    // El ultimo elemento indica de las decisiones siguientes 
    {"Te encuentras a un dragon durmiendo", "0"},
    {"Mientras corres una roca te hace caer y el dragon te mata","F"},
    {"El dragon despierta y te come", "F"},
    {"Buscas a tu alrededor y ves una espada y una pistola", "La espada tiene una punta muy afilada y a pistola esta vieja...", "1"},

    {"Le entierras la espada en la cabeza al dragon y lo matas.", "Pero de repente llegan bebes dragones y te atacan", "2"},
    {"Te escondes y no te encuentran.", "F"},
    {"Peleas y te matan", "F"},

    {"Le disparas al dragon pero no lo matas. El dragon termina comiendote.", "F"}
};

const vector<vector<string>> decision_narracion = {

    // Se separa el ultimo elemento por espacios
    // El primer elemento separado es la nueva historia que se pondra si se elige la opcion 1
    // Lo mismo con lo demas
    {"Salir corriendo", "Gritar", "Buscar como matarlo", "1 2 3"},
    {"Agarrar la espada", "Agarrar la pistola", "4 5"},
    {"Esconderte", "Pelear a puño limpio", "5 6"}
};

#endif