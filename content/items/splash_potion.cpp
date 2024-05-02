#include "splash_potion.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "animation.h"
#include "throw.h"

SplashPotion::SplashPotion(int health)
: Item{"potion_large_blue"}, health{health * -1} {}

void SplashPotion::heal_defender(Engine& engine, Entity& attacker, Entity& defender, Tile& tile) {
    if (tile.has_entity() && defender.get_team() == attacker.get_team()) {
        auto thrown = engine.events.create_event<Throw>(sprite, attacker.get_direction());
        thrown->add_next(Hit{defender, health});
        thrown->add_next(Animation{"magic", defender.get_position()});
    }
}

void SplashPotion::use(Engine& engine, Entity& attacker, Entity& defender) {
    // heal user
    engine.events.create_event<Hit>(attacker, health);

    // search and heal entities from the same team
    for(int i = -1; i < 1; ++i) {
        // check up/down
        Vec pos_vertical = attacker.get_position() + Vec{0, i};
        Tile& tile = engine.dungeon.get_tile(pos_vertical);
        heal_defender(engine, attacker, defender, tile);

        // check left/right
        Vec pos_horizontal = attacker.get_position() + Vec{i, 0};
        tile = engine.dungeon.get_tile(pos_horizontal);
        heal_defender(engine, attacker, defender, tile);

        // check upper right and bottom left corners
        Vec corners = attacker.get_position() + Vec{i, i};
        tile = engine.dungeon.get_tile(corners);
        heal_defender(engine, attacker, defender, tile);

        // check upper left and bottom right corners
        Vec corners2 = attacker.get_position() + Vec{-i, i};
        tile = engine.dungeon.get_tile(corners2);
        heal_defender(engine, attacker, defender, tile);
    }
}

void SplashPotion::interact(Engine& engine, Entity& entity) {

}