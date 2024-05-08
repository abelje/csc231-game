#pragma once

#include "entity.h"
#include "event.h"
#include "item.h"
#include "tile.h"

class PickUp : public Event {
public:
    explicit PickUp(Entity& entity);

    // add item to entity's inventory
    void execute(Engine& engine) override;

private:
    Entity& entity;
};
