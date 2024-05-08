#include "use_item.h"

#include "action.h"
#include "entity.h"

Result UseItem::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->get_current_item()->use(engine, *entity);
    return success();
}


