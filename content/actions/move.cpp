#include "move.h"

#include "door.h"
#include "engine.h"
#include "entity.h"
#include "opendoor.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec pos = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(pos);
    if (tile.is_wall() || tile.has_entity()) {
        // cannot move there
        return failure();
    }
    if (tile.has_door() && !tile.door->is_open()) {
        return alternative(OpenDoor{*tile.door});
    }

    entity->change_direction(direction);
    entity->move_to(pos);
    return success();
}

Move::Move(Vec direction)
: direction{direction} {

}