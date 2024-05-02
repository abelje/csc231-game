#include "healing_potion.h"

#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "pick_up.h"

HealingPotion::HealingPotion(int health) // maybe pass in Item or Tile?
: Item{"potion_red"}, health{health * -1} {}

void HealingPotion::use(Engine& engine, Entity& attacker, Entity&) {
    engine.events.create_event<Hit>(attacker, health);

}

void HealingPotion::interact(Engine& engine, Entity& entity) {
    // get current tile and generate a pickup event
    Vec pos = entity.get_position();
    Tile& tile = engine.dungeon.get_tile(pos);
    engine.events.create_event<PickUp>(entity, tile);
}