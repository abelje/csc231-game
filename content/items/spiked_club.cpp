#include "spiked_club.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "swing.h"
#include "thrust.h"

SpikedClub::SpikedClub(int damage)
:Item{"spiked_club"}, damage{damage}{}

void SpikedClub::use(Engine& engine, Entity& attacker, Entity& defender) {
    auto swing = engine.events.create_event<Swing>(sprite, attacker.get_direction());
    std::shared_ptr<Event> int_hit = engine.events.create_event<Hit>(defender, damage);
    std::shared_ptr<Event> self_hit = engine.events.create_event<Hit>(attacker, damage / 2);
    int_hit->add_next(self_hit);
    swing->add_next(int_hit);

}