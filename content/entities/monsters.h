#pragma once

#include "entity.h"
#include <memory>
#include "tile.h"

namespace Monsters {
   void make_demon_tiny(std::shared_ptr<Entity>& monster);
   void make_goblin(std::shared_ptr<Entity>& monster);
   void make_orc_masked(std::shared_ptr<Entity>& monster);
   void make_necromancer(std::shared_ptr<Entity>& monster);
   std::unique_ptr<Action> chaser(Engine& engine, Entity& entity);
   std::unique_ptr<Action> wanderer(Engine&, Entity&);
   Vec path(Engine& engine, Entity& entity,  Tile& tile);
   std::unique_ptr<Action> healer(Engine& engine, Entity& entity);

}
