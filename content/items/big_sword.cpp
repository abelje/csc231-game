#include "big_sword.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "swing.h"
#include "thrust.h"

Big_Sword::Big_Sword(int damage)
:Item{"sword_big"},damage{damage} {}

void Big_Sword::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Swing>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}