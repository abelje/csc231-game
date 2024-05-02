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
//    std::shared_ptr<Event> int_hit = engine.events.create_event<Hit>(defender, damage);
//    std::shared_ptr<Event> self_hit = engine.events.create_event<Hit>(attacker, damage / 2);
//    std::shared_ptr<Event> sound = engine.events.create_event<Sound>("hit");
//    self_hit->add_next(sound);
//    int_hit->add_next(self_hit);
    swing->add_next(Hit{defender, damage});
    swing->add_next(Hit{attacker, damage / 2});
    swing->add_next(Sound{"hit"});
//    engine.events.create_event<Hit>(attacker, damage / 2);

}