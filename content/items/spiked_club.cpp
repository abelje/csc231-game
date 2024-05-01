#include "spiked_club.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "swing.h"
#include "thrust.h"

Spiked_club::Spiked_club(int damage)
:Item{"spiked_club"}, damage{damage}{}

void Spiked_club::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Swing>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
    engine.events.create_event<Hit>(attacker, damage / 2);
}