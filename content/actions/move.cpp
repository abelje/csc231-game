#include "move.h"

#include "attack.h"
#include "door.h"
#include "engine.h"
#include "entity.h"
#include "opendoor.h"
#include "rest.h"
#include "item.h"

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);

    Vec pos = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(pos);
    if (tile.is_wall()) {
        // cannot move there
        return failure();
    }
    if (tile.has_entity()) {
        return alternative(Attack{*tile.entity});
    }
    if (tile.has_door() && !tile.door->is_open()) {
        return alternative(OpenDoor{*tile.door});
    }
    if(tile.has_item()) {
        tile.item->interact(engine, *entity);
    }
    entity->move_to(pos);
    return success();
}

Move::Move(Vec direction)
: direction{direction} {

}