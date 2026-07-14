#ifndef GAME_H
#define GAME_H

#include "Language.h"
#include "Story.h"

#include <memory>

class Game
{
public:
    Game();
    explicit Game(ScenePtr root_scene, Language lang = Language::Spanish);

    Story& story();
    const Story& story() const;

    void display_current_scene() const;

    std::size_t prompt_decision() const;

    bool play_turn();

    ~Game();

private:
    Language lang_;
    std::unique_ptr<Story> story_;

    std::string decision_prompt_text() const;
    std::string ending_text() const;
};

#endif
