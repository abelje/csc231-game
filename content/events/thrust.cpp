#include "thrust.h"

constexpr int duration = 4; // number of frames
constexpr int delta = 3;

Thrust::Thrust(Sprite& sprite, Vec direction)
:Event {duration}, sprite{sprite}, copy{sprite}, direction{direction} {
    // orient the weapon towards direction
    sprite.center = sprite.size / 2;
    sprite.shift.y -= sprite.size.y / 4;

    if (direction == Vec {1,0}) { // right
        sprite.size.y += sprite.size.y / 2;
        sprite.angle = 90;
    }
    else if (direction == Vec {-1,0}) { // left
        sprite.size.y += sprite.size.y / 2;
        sprite.angle = -90;
    }
    else if (direction == Vec {0,1}) { // up
        sprite.angle = 0;
        this->direction = -1 * direction;
    }
    else { // down
        sprite.angle = 180;
        sprite.shift.y += sprite.size.y;
        this->direction = -1 * direction;
    }
}

void Thrust::execute(Engine&) {
    //shift in pixels (16 per tile)
    sprite.shift += direction * delta;
}

void Thrust::when_done(Engine&) {
    sprite = copy;
}