#include "pick_up.h"

#include "engine.h"
#include "entity.h"
#include "tile.h"
#include "item.h"

PickUp::PickUp(Entity& entity)
:entity{entity} {}

void PickUp::execute(Engine& engine) {
    //add to inventory
    Vec pos = entity.get_position();
    Tile& tiles = engine.dungeon.get_tile(pos);
    entity.add_to_inventory(tiles.item);

    // override item on tile with blank item to remove from game world
    std::shared_ptr<Item> item;
    tiles.item = item;
}