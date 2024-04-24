#pragma once

#include "item.h"

class Big_Sword : public Item {
public:
    explicit Big_Sword(int damage);
    void use(Engine& engine, Entity&, Entity& defender) override;

private:
    int damage;
};
