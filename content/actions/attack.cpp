#include "attack.h"
#include "item.h"
#include "entity.h"

Attack::Attack(Entity& defender)
:defender{defender}{}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    attacker->get_current_item()->use(engine,*attacker,defender);
    return success();
}