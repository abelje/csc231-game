#include "closedoor.h"

#include "entity.h"
#include "sound.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool closed_any_doors{false};
    for (Vec neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if(tile.has_door() && tile.door->is_open()) {
            tile.door->close();
            engine.events.create_event<Sound>("door-close");
            closed_any_doors = true;
        }
    }

    if (closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else {
        return failure(); // don't lose out turn if no doors were around us.
    }
}
