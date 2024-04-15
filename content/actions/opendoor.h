#pragma once

#include "entity.h"
#include "engine.h"
#include "door.h"
#include "action.h"

class OpenDoor : public Action {
public:
    OpenDoor(Door& door);
    Result perform(Engine& engine, std::shared_ptr<Entity>) override;
private:
    Door& door;
};
