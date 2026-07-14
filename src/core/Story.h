#ifndef STORY_H
#define STORY_H

#include "Scene.h"

#include <cstddef>

class Story
{
public:
    Story();
    explicit Story(ScenePtr root_scene);

    const Scene& current_scene() const;

    void next_narration();

    bool is_at_ending() const;

    void choose(std::size_t decision_index);

    void restart();

    ~Story();

private:
    ScenePtr root_scene_;
    ScenePtr current_scene_;

    void advance_to_next_scene(std::size_t decision_index);
};

#endif
