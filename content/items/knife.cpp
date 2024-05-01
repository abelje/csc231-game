#include "knife.h"

#include "animation.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "sound.h"
#include "throw.h"
#include "thrust.h"

Knife::Knife(int damage)
: Item{"knife"}, damage{damage} {}

void Knife::use(Engine& engine, Entity& attacker, Entity& defender) {
   auto thrown = engine.events.create_event<Throw>(sprite, attacker.get_direction());
    std::shared_ptr<Event> fire = std::make_shared<Animation>("fire", defender.get_position());
    fire->add_next(Hit{defender,damage});
    thrown->add_next(fire);
    engine.events.create_event<Sound>("fire");
}
