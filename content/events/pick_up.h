#pragma once

#include "entity.h"
#include "event.h"
#include "item.h"
#include "tile.h"

class PickUp : public Event {
public:
    PickUp(Entity& entity, Tile& tile);

    // add item to entity's inventory
    void execute(Engine& engine) override;

    // remove item from game world
    void when_done(Engine& engine) override;
private:
    Entity& entity;
    Tile& tile;
    Item reset{"bite"};
};
