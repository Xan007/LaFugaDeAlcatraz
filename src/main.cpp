#include "core/Game.h"
#include "core/Language.h"
#include "data/EscapeStory.h"

#include <iostream>
#include <string>

int main()
{
    Language lang = Language::Spanish;

    std::cout << "Select language / Seleccione idioma:\n";
    std::cout << "1. English\n";
    std::cout << "2. Espanol\n";

    std::string lang_choice;
    do {
        std::cout << ">> ";
        std::getline(std::cin >> std::ws, lang_choice);
    } while (lang_choice != "1" && lang_choice != "2");

    if (lang_choice == "1")
        lang = Language::English;

    ScenePtr root = build_escape_story(lang);
    bool playing = true;

    do {
        system("cls");

        if (lang == Language::English)
        {
            std::cout << "===================================\n";
            std::cout << "Welcome to Escape from Alcatraz\n";
            std::cout << "- Make decisions to escape from Alcatraz, a maximum security prison on a remote island.\n";
            std::cout << "===================================\n\n";
        }
        else
        {
            std::cout << "===================================\n";
            std::cout << "Bienvenido a La Fuga de Alcatraz\n";
            std::cout << "- Toma decisiones para escapar de Alcatraz, una prision de maxima seguridad en una isla remota.\n";
            std::cout << "===================================\n\n";
        }

        Game game(root, lang);

        while (game.play_turn())
            ;

        std::string answer;
        do {
            if (lang == Language::English)
                std::cout << "\nDo you want to restart the game? (y/n): ";
            else
                std::cout << "\nDesea reiniciar el juego? (s/n): ";

            std::getline(std::cin >> std::ws, answer);
            if (lang == Language::English)
            {
                if (answer != "y" && answer != "n")
                    continue;
                if (answer == "n")
                    playing = false;
            }
            else
            {
                if (answer != "s" && answer != "n")
                    continue;
                if (answer == "n")
                    playing = false;
            }
            break;
        } while (true);
    } while (playing);

    return 0;
}
