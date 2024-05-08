#pragma once

#include "item.h"
#include "tile.h"

class HealingPotion : public Item {
public:
    explicit HealingPotion(int health);

    void use(Engine& engine, Entity& owner) override;

    // pick up when on the ground
    void interact(Engine& engine, Entity& entity) override;

private:
    int health;
};
