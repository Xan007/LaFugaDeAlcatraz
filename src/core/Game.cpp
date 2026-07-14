#include "Game.h"

#include "../../util/Input.h"

#include <iostream>

Game::Game()
    : lang_(Language::Spanish),
      story_(std::make_unique<Story>())
{
}

Game::Game(ScenePtr root_scene, Language lang)
    : lang_(lang),
      story_(std::make_unique<Story>(root_scene))
{
}

Story& Game::story()
{
    return *story_;
}

const Story& Game::story() const
{
    return *story_;
}

void Game::display_current_scene() const
{
    const Scene& scene = story_->current_scene();
    std::cout << "* " << scene.current_narration() << "\n";
}

std::string Game::decision_prompt_text() const
{
    if (lang_ == Language::Spanish)
        return "=> Toma una decision <=\n\n";
    return "=> Make a decision <=\n\n";
}

std::string Game::ending_text() const
{
    if (lang_ == Language::Spanish)
        return "\n==> Has llegado a un final. Gracias por jugar! "
               "Juega otra vez para descubrir mas finales!\n";
    return "\n==> You have reached an ending. Thanks for playing! "
           "Play again to discover more endings!\n";
}

std::size_t Game::prompt_decision() const
{
    const Scene& scene = story_->current_scene();
    std::size_t count = scene.decision_count();
    if (count == 0)
        return 0;

    std::cout << "\n" << decision_prompt_text();
    for (std::size_t i = 0; i < count; ++i)
        std::cout << (i + 1) << ". " << scene.decision_at(i) << "\n";

    if (lang_ == Language::Spanish)
        std::cout << "\nIngrese el numero de la decision que desea tomar:\n";
    else
        std::cout << "\nEnter the number of the decision you want to make:\n";

    unsigned long long choice = input_between<unsigned long long>(1ULL, static_cast<unsigned long long>(count));

    return static_cast<std::size_t>(choice - 1ULL);
}

bool Game::play_turn()
{
    const Scene& scene = story_->current_scene();
    std::cout << "* " << scene.current_narration() << "\n";

    if (scene.has_next_narration())
    {
        story_->next_narration();
        return true;
    }

    if (scene.is_ending())
    {
        std::cout << ending_text();
        return false;
    }

    std::size_t decision_index = prompt_decision();
    story_->choose(decision_index);

    std::cout << "===================================\n\n";
    return true;
}

Game::~Game()
{
}
