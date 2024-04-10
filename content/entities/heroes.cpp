#include "heroes.h"

namespace Heroes {
    void make_knight(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("knight");
        hero->set_max_health(10);
    }
}
