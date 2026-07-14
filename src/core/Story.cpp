#include "Story.h"

#include <stdexcept>

Story::Story()
{
}

Story::Story(ScenePtr root_scene)
    : root_scene_(root_scene),
      current_scene_(root_scene)
{
}

const Scene& Story::current_scene() const
{
    if (!current_scene_)
        throw std::runtime_error("story has no current scene");
    return *current_scene_;
}

void Story::next_narration()
{
    if (!current_scene_)
        throw std::runtime_error("story has no current scene");
    current_scene_->advance_narration();
}

bool Story::is_at_ending() const
{
    return !current_scene_ || current_scene_->is_ending();
}

void Story::choose(std::size_t decision_index)
{
    advance_to_next_scene(decision_index);
}

void Story::restart()
{
    if (root_scene_)
        root_scene_->reset_narration();
    current_scene_ = root_scene_;
}

void Story::advance_to_next_scene(std::size_t decision_index)
{
    if (!current_scene_)
        throw std::runtime_error("story has no current scene");

    ScenePtr next = current_scene_->next_scene_for(decision_index);
    if (next)
        next->reset_narration();
    current_scene_ = next;
}

Story::~Story()
{
}
