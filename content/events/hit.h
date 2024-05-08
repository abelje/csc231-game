#pragma once

#include "event.h"

// forward declaration (declare the type)
class Entity;

class Hit : public Event {
public:
    Hit(Entity& entity, int damage);

    void execute(Engine& engine) override;

    // PLay die event if the entity is dead
    void when_done(Engine& engine) override;

private:
    Entity& entity;
    int damage;
};