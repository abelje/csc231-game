#pragma once

#include "action.h"
#include "item.h"

class UseItem : public Action {
public:
    Result perform(Engine &engine, std::shared_ptr<Entity> entity) override;
};
