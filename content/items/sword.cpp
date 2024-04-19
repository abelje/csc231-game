#include "sword.h"

#include "engine.h"
#include "hit.h"

Big_Sword::Big_Sword(int damage)
:Item{"sword_big"},damage{damage} {}

void Big_Sword::use(Engine& engine, Entity&, Entity& defender){
    engine.events.create_event<Hit>(defender, damage);
}