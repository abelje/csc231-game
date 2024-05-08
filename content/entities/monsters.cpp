#include "monsters.h"

#include "action.h"
#include "engine.h"
#include "knife.h"
#include "move.h"
#include "randomness.h"
#include "rest.h"
#include "spiked_club.h"
#include "splash_potion.h"
#include "wander.h"

namespace Monsters {
void make_demon_tiny(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("demon_tiny");
    monster->set_max_health(3);
    monster->add_to_inventory(std::make_shared<Knife>(1));
    monster->behavior = chaser;
}

void make_goblin(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("goblin");
    monster->set_max_health(6);
    monster->add_to_inventory(std::make_shared<Knife>(3));
    monster->behavior = chaser;
}

void make_orc_masked(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("orc_masked");
    monster->set_max_health(7);
    monster->add_to_inventory(std::make_shared<SpikedClub>(4));
    monster->behavior = wanderer;
}

void make_necromancer(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("necromancer");
    monster->set_max_health(15);
    monster->add_to_inventory(std::make_shared<SplashPotion>(4));
    monster->behavior = healer;
}

std::unique_ptr<Action> chaser(Engine& engine, Entity& entity) {
    // if monster is visible and can see hero
    if (entity.is_visible() && engine.hero) {
        auto path =
            engine.dungeon.calculate_path(entity.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            auto direction = path.at(1) - path.at(0);
            if (probability (15)) {
                return std::make_unique<Rest>();
            }
            return std::make_unique<Move>(direction);
        }
    }

    // if monster can't see hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}

std::unique_ptr<Action> wanderer(Engine&, Entity&) {
    if (probability(80)) {
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}

Vec path(Engine& engine, Entity& entity,  Tile& tile) {
    // move if the tile has an entity, is on the same team, and is visible
    if (tile.has_entity() && tile.entity->get_team() == entity.get_team() &&
        tile.entity->is_visible() && engine.hero && !tile.is_wall()) {
        auto path =
            engine.dungeon.calculate_path(entity.get_position(), tile.entity->get_position());
        if (path.size() > 1) {
            auto direction = path.at(1) - path.at(0);
            return direction;
        }
    }
    return Vec {0,0};
}

std::unique_ptr<Action> healer(Engine& engine, Entity& entity) {
    //check for monsters in an 3 by 3 area around the user and path over to it
    for(int i = -1; i < 1; i += 1) {
        // check up/down
        Vec pos_vertical = entity.get_position() + Vec{0, i};
        Tile& vert_tiles = engine.dungeon.get_tile(pos_vertical);
        if (path(engine, entity, vert_tiles) != Vec {0,0}) {
            return std::make_unique<Move>(path(engine, entity, vert_tiles));
        }

        // check left/right
        Vec pos_horizontal = entity.get_position() + Vec {i, 0};
        Tile& horizontal_tiles = engine.dungeon.get_tile(pos_horizontal);
        if (path(engine, entity, horizontal_tiles) != Vec {0,0}) {
            return std::make_unique<Move>(path(engine, entity, horizontal_tiles));
        }

        // check upper right and bottom left corners
        Vec corners = entity.get_position() + Vec{i, i};
        Tile& corner = engine.dungeon.get_tile(corners);
        if (path(engine, entity, corner) != Vec {0,0}) {
            return std::make_unique<Move>(path(engine, entity, corner));
        }

      // check upper left and bottom right corners
        Vec corners2 = entity.get_position() + Vec{-i, i};
        Tile& corner2 = engine.dungeon.get_tile(corners2);
        if (path(engine, entity, corner2) != Vec {0,0}) {
            return std::make_unique<Move>(path(engine, entity, corner2));
        }
    }

    // wander if it is not visible
    if (probability(75)) {
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}
}