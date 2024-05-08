#include "big_sword.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "sound.h"
#include "swing.h"

BigSword::BigSword(int damage)
:Item{"sword_big"},damage{damage} {}

void BigSword::use(Engine& engine, Entity& attacker, Entity& defender) {
    auto swing =  engine.events.create_event<Swing>(sprite, attacker.get_direction());
    swing->add_next(Hit{defender, damage});
    swing->add_next(Sound{"metal-clang"});
}