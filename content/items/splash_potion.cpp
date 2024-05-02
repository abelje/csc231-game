#include "splash_potion.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "animation.h"
#include "throw.h"

SplashPotion::SplashPotion(int health)
: Item{"potion_large_blue"}, health{health * -1} {}

void SplashPotion::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Hit>(attacker, health);
    engine.events.create_event<Hit>(defender, health);
    // create blue splash area, use throw
    std::make_shared<Animation>("magic", defender.get_position());
    engine.events.create_event<Throw>(sprite, attacker.get_direction());
}

void SplashPotion::interact(Engine& engine, Entity& entity) {

}