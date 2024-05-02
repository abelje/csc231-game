#include "pick_up.h"

#include "engine.h"
#include "entity.h"
#include "tile.h"
#include "item.h"

PickUp::PickUp(Entity& entity, Tile& tile)
:entity{entity}, tile{tile} {}

void PickUp::execute(Engine& engine) {
    //add to inventory
    entity.add_to_inventory(tile.item);
}

void PickUp::when_done(Engine& engine) {
    // remove from the ground
    std::shared_ptr<Item> item;
    tile.item = item; // Might work have to check, want to remove the item from the tile
}