#include "healing_potion.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "pick_up.h"

HealingPotion::HealingPotion(int health)
: Item{"potion_red"}, health{health * -1} {}

void HealingPotion::use(Engine& engine, Entity& owner) {
    engine.events.create_event<Hit>(owner, health);
    owner.remove_item(this);
}

void HealingPotion::interact(Engine& engine, Entity& entity) {
    // generate a pickup event
    engine.events.create_event<PickUp>(entity);
}