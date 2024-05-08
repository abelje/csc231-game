#pragma once

#include "item.h"
#include "tile.h"

class SplashPotion : public Item {
public:
    explicit SplashPotion(int health);

    // helper function to heal enemies around the entity
    void heal_defender(Engine& engine, Entity& attacker, Entity& defender, Tile& tile);

    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int health;
};