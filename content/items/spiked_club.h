#pragma once

#include "item.h"

class Spiked_club : public Item {
public:
    explicit Spiked_club(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender);

private:
    int damage;
};