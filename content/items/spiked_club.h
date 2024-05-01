#pragma once

#include "item.h"

class SpikedClub : public Item {
public:
    explicit SpikedClub(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender);

private:
    int damage;
};