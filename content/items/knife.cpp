#include "knife.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "thrust.h"

Knife::Knife(int damage)
: Item{"knife"}, damage{damage} {}

void Knife::use(Engine& engine, Entity&, Entity& defender) {
    //engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}
