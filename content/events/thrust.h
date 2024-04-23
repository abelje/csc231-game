#pragma once

#include "sprite.h"
#include "event.h"

class Thrust : public Event {
public:
    Thrust(Sprite& sprite, Vec direction);

    // shift the sprite
    void execute(Engine& engine) override;

    // reset original sprite
    void when_done(Engine& engine) override;
private:
    Sprite& sprite; // original weapon sprite
    Sprite copy; // copy so that we can reset it after animation
    Vec direction; // which direction to shift
};
