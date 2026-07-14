#ifndef SCENE_H
#define SCENE_H

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class Scene;
using ScenePtr = std::shared_ptr<Scene>;

class Scene
{
public:
    Scene();

    bool has_next_narration() const;
    void advance_narration();

    const std::string& current_narration() const;

    bool is_ending() const;

    std::size_t decision_count() const;
    const std::string& decision_at(std::size_t index) const;

    ScenePtr next_scene_for(std::size_t decision_index) const;

    void set_narrations(std::vector<std::string> narrations);
    void set_decisions(std::vector<std::string> decisions);
    void set_next_scenes(std::vector<ScenePtr> next_scenes);

    void reset_narration();

    ~Scene();

private:
    std::size_t              narration_index_;
    std::vector<std::string> narrations_;
    std::vector<std::string> decisions_;
    std::vector<ScenePtr>    next_scenes_;
};

#endif
