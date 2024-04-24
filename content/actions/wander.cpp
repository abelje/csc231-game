#include "wander.h"

#include "action.h"
#include "engine.h"
#include "entity.h"
#include "move.h"
#include "rest.h"
#include "randomness.h"
#include "attack.h"

Result Wander::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    // randomize order of neighbors: shuffle in engine/utils/randomness.h
    shuffle(std::begin(neighbors), std::end(neighbors));
    // find first open floor tile
    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (!tile.is_wall() && !tile.has_entity()) {
            Vec direction = neighbor - position;
            return alternative(Move{direction});
        }
        if(tile.has_entity() && entity->get_team() != tile.entity->get_team() && probability(25)) {
            return alternative(Attack{*tile.entity});
        }
    }
    return alternative(Rest{});
}
