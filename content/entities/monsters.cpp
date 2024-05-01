#include "monsters.h"

#include "action.h"
#include "engine.h"
#include "move.h"
#include "rest.h"
#include "randomness.h"
#include "wander.h"
#include "knife.h"
#include "spiked_club.h"

namespace Monsters {
void make_demon_tiny(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("demon_tiny");
    monster->set_max_health(3);
    monster->add_to_inventory(std::make_shared<Knife>(1));
    monster->behavior = behavior;
}

void make_goblin(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("goblin");
    monster->set_max_health(6);
    monster->add_to_inventory(std::make_shared<Knife>(3));
    monster->behavior = behavior2;
}

void make_orc_masked(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("orc_masked");
    monster->set_max_health(7);
    monster->add_to_inventory(std::make_shared<SpikedClub>(4));
    monster->behavior = behavior2;
}

std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
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

std::unique_ptr<Action> behavior2(Engine&, Entity&) {
    if (probability(80)) {
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}

}