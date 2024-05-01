#include "knife.h"

#include "animation.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "throw.h"
#include "thrust.h"

Knife::Knife(int damage)
: Item{"knife"}, damage{damage} {}

void Knife::use(Engine& engine, Entity& attacker, Entity& defender) {
   auto thrust = engine.events.create_event<Throw>(sprite, attacker.get_direction());
    std::shared_ptr<Event> fire = std::make_shared<Animation>("fire", defender.get_position());
    fire->add_next(Hit{defender,damage});
    thrust->add_next(fire);
}
