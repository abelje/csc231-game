#pragma once

#include "sprite.h"
#include "event.h"

class Throw : public Event {
public:
    Throw(Sprite& sprite, Vec direction);

    // throw(shift) item a couple of tiles
    void execute(Engine&) override;

    // reset item to original position
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    Vec direction;
    double angle;
};
