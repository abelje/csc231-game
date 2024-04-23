#pragma once

#include "entity.h"
#include <memory>

namespace Monsters {
   void make_demon_tiny(std::shared_ptr<Entity>& monster);
   void make_goblin(std::shared_ptr<Entity>& monster);
   void make_orc_masked(std::shared_ptr<Entity>& monster);
   std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);
   std::unique_ptr<Action> behavior2(Engine&, Entity&);
}
