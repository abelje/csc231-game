#pragma once

#include "action.h"

class Attack : public Action {
public:
    Attack(Entity& defender);
    // use current item on defender
    Result perform(Engine& engine, std::shared_ptr<Entity> attacker);
private:
    Entity& defender;
};