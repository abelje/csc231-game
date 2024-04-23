#include "thrust.h"

constexpr int duration = 10; // number of frames
constexpr int delta = 3;

Thrust::Thrust(Sprite& sprite, Vec direction)
:Event {duration}, sprite{sprite}, copy{sprite}, direction{direction} {
    // orient the weapon towards direction
    sprite.center = sprite.size / 2;
    sprite.shift.y -= sprite.size.y / 4;

    if (direction == Vec {1,0}) { // right
        sprite.angle = 90;
    }
    else if (direction == Vec {-1,0}) { // left
        sprite.angle = -90;
    }
    else if (direction == Vec {0,1}) { // up
        sprite.angle = 0;
    }
    else { // down
        sprite.angle = 180;
    }
}

void Thrust::execute(Engine&) {
    //shift in pixels (16 per tile)
    sprite.shift += direction * delta;
}

void Thrust::when_done(Engine&) {

}