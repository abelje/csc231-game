#include "splash_potion.h"

#include "animation.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "swing.h"
#include "throw.h"
#include "thrust.h"

SplashPotion::SplashPotion(int health)
: Item{"potion_blue"}, health{health * -1} {}

void SplashPotion::heal_defender(Engine& engine, Entity& attacker, Entity& defender, Tile& tile) {
    if (tile.has_entity() && defender.get_team() == attacker.get_team() && !tile.is_wall()) {
        engine.events.create_event<Hit>(defender, health);
        engine.events.create_event<Animation>("magic", defender.get_position());
    }
}

void SplashPotion::use(Engine& engine, Entity& attacker, Entity& defender) {
    // heal user
    auto thrown = engine.events.create_event<Throw>(sprite, attacker.get_direction());
    thrown->add_next(Hit{attacker, health});
    thrown->add_next(Animation{"magic", attacker.get_position()});
    // search and heal entities from the same team
    for(int i = -1; i < 1; i += 2) {
        // check up/down
        Vec pos_vertical = attacker.get_position() + Vec{0, i};
        Tile& vert_tiles = engine.dungeon.get_tile(pos_vertical);
        heal_defender(engine, attacker, defender, vert_tiles);

        // check left/right
        Vec pos_horizontal = attacker.get_position() + Vec{i, 0};
        Tile& horizontal_tiles = engine.dungeon.get_tile(pos_horizontal);
        heal_defender(engine, attacker, defender, horizontal_tiles);

        // check upper right and bottom left corners
        Vec corners = attacker.get_position() + Vec{i, i};
        Tile& corner = engine.dungeon.get_tile(corners);
        heal_defender(engine, attacker, defender, corner);

        // check upper left and bottom right corners
        Vec corners2 = attacker.get_position() + Vec{-i, i};
        Tile& corner2 = engine.dungeon.get_tile(corners2);
        heal_defender(engine, attacker, defender, corner2);
    }
}