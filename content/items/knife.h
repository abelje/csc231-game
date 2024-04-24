#pragma once

#include "item.h"

class Knife : public Item {
public:
    explicit Knife(int damage);
    void use(Engine& engine, Entity&, Entity& defender) override;

private:
    int damage;
};