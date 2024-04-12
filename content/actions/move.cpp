#include "move.h"

#include "../entities/heroes.h"
#include "door.h"
#include "engine.h"
#include "entity.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec pos = entity->get_position() + vec;
    Tile& tile = engine.dungeon.get_tile(pos);
    if (tile.is_wall() || tile.has_entity()) {
        // cannot move there
        return failure();
    }
    if (tile.has_door()) {
        // do something with door
        // open door
        tile.door->open();
        // move the entity
        entity->change_direction(vec);
        entity->move_to(pos);
        return success();
    }
    else {
        entity->change_direction(vec);
        entity->move_to(pos);
    }
    // set direction of entity

    return success();
}

Move::Move(Vec vec)
:vec{vec} {

}