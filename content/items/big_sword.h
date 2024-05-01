#pragma once

#include "item.h"

class BigSword : public Item {
public:
    explicit BigSword(int damage);
    void use(Engine& engine, Entity&, Entity& defender) override;

private:
    int damage;
};
