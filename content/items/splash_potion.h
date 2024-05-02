#pragma once

#include "item.h"

class SplashPotion : public Item {
public:
    explicit SplashPotion(int health);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;
    // pick up when on the ground
    void interact(Engine& engine, Entity& entity) override;

private:
    int health;
};