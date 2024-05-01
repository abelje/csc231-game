#include "throw.h"

constexpr int duration = 4; // number of frames
constexpr int delta = 2;
constexpr int spin = 25;
constexpr int rev_spin = -25;

Throw::Throw(Sprite& sprite, Vec direction)
:Event{duration}, sprite{sprite}, copy{sprite} {
    // orient the weapon towards direction
    sprite.center = sprite.size / 2;
    sprite.shift.y -= sprite.size.y / 4;

    if (direction == Vec {1,0}) { // right
        sprite.size.y += sprite.size.y / 2;
        sprite.angle = 90;
        angle = sprite.angle;
    }
    else if (direction == Vec {-1,0}) { // left
        sprite.size.y += sprite.size.y / 2;
        sprite.angle = -90;
        angle = sprite.angle;
    }
    else if (direction == Vec {0,1}) { // up
        sprite.angle = 0;
        angle = sprite.angle;
        this->direction = -1 * direction;
    }
    else { // down
        sprite.angle = 180;
        angle = sprite.angle;
        sprite.shift.y += sprite.size.y;
        this->direction = -1 * direction;
    }
}

void Throw::execute(Engine&) {
    // 16 pixels per tile
    // add an if statement for if it goes to the left.
    for(int i = 0; i < 8; ++i) {
        if (i % 2 == 0 && angle < 0) {
            sprite.angle += rev_spin;
        }
        if (i % 2 == 0 && angle >= 0) {
            sprite.angle += spin;
        }
        else {
            sprite.shift += direction * delta;
        }
    }
}

void Throw::when_done(Engine&) {
    sprite = copy;
}