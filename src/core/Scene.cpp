#include "Scene.h"

#include <stdexcept>

Scene::Scene()
    : narration_index_(0)
{
}

bool Scene::has_next_narration() const
{
    return narration_index_ + 1 < narrations_.size();
}

void Scene::advance_narration()
{
    if (narration_index_ + 1 >= narrations_.size())
        throw std::out_of_range("no next narration");
    narration_index_ += 1;
}

const std::string& Scene::current_narration() const
{
    return narrations_[narration_index_];
}

bool Scene::is_ending() const
{
    return decisions_.empty();
}

std::size_t Scene::decision_count() const
{
    return decisions_.size();
}

const std::string& Scene::decision_at(std::size_t index) const
{
    if (index >= decisions_.size())
        throw std::out_of_range("decision index out of range");
    return decisions_[index];
}

ScenePtr Scene::next_scene_for(std::size_t decision_index) const
{
    if (decision_index >= next_scenes_.size())
        throw std::out_of_range("decision index out of range");
    return next_scenes_[decision_index];
}

void Scene::set_narrations(std::vector<std::string> narrations)
{
    narrations_ = std::move(narrations);
}

void Scene::set_decisions(std::vector<std::string> decisions)
{
    decisions_ = std::move(decisions);
}

void Scene::set_next_scenes(std::vector<ScenePtr> next_scenes)
{
    next_scenes_ = std::move(next_scenes);
}

void Scene::reset_narration()
{
    narration_index_ = 0;
}

Scene::~Scene()
{
}
