#include "die.h"

#include "engine.h"
#include "entity.h"
#include "sound.h"

Die::Die(Entity& entity)
:entity{entity}{}

void Die::execute(Engine& engine) {
    engine.events.create_event<Sound>("death");
    engine.remove_entity(entity);
}