#pragma once

#include "event.h"
#include "vec.h"
#include "animatedsprite.h"

class Animation : public Event {
public:
    explicit Animation(std::string name, Vec position);

    void execute(Engine& engine) override;

private:
    Vec position;
    AnimatedSprite sprite;
    std::string name;
};