#pragma once

#include "entity.h"
#include <memory>

namespace Heroes {
    void make_knight(std::shared_ptr<Entity>& hero);
    std::unique_ptr<Action> behavior(Engine& engine, Entity&);
}

