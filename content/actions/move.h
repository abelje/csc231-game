#pragma once

#include "action.h"
#include "vec.h"
#include "entity.h"

class Move : public Action {
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
    Move(Vec direction);
private:
    Vec direction;
};