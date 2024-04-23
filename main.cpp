#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_knight(hero);

        for (int i = 0; i < 4; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            std::shared_ptr<Entity> monster2 = engine.create_monster();
            std::shared_ptr<Entity> monster3 = engine.create_monster();
            Monsters::make_demon_tiny(monster);
            Monsters::make_goblin(monster2);
            Monsters::make_orc_masked(monster3);
        }

//        std::shared_ptr<Entity> monster = engine.create_monster();
//        Monsters::make_demon_tiny(monster);
//
//        std::shared_ptr<Entity> monster2 = engine.create_monster();
//        Monsters::make_goblin(monster2);

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
