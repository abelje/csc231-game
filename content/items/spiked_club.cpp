#include "spiked_club.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "sound.h"
#include "swing.h"
#include "thrust.h"

SpikedClub::SpikedClub(int damage)
:Item{"spiked_club"}, damage{damage}{}

void SpikedClub::use(Engine& engine, Entity& attacker, Entity& defender) {
    auto swing = engine.events.create_event<Swing>(sprite, attacker.get_direction());
    swing->add_next(Hit{defender, damage});
    swing->add_next(Hit{attacker, damage / 2});
    swing->add_next(Sound{"hit"});
}