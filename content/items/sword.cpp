#include "sword.h"

#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"

Big_Sword::Big_Sword(int damage)
:Item{"sword_big"},damage{damage} {}

void Big_Sword::use(Engine& engine, Entity& attacker, Entity& defender) {
    //engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}