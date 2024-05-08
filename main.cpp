#include <iostream>

#include "engine.h"
#include "healing_potion.h"
#include "heroes.h"
#include "item.h"
#include "monsters.h"
#include "spiked_club.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_knight(hero);

        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<Entity> tiny_demon = engine.create_monster();
            std::shared_ptr<Entity> goblin = engine.create_monster();
            std::shared_ptr<Entity> masked_orc = engine.create_monster();
            std::shared_ptr<Entity> necromancer = engine.create_monster();

            Monsters::make_demon_tiny(tiny_demon);
            Monsters::make_goblin(goblin);
            Monsters::make_orc_masked(masked_orc);
            Monsters::make_necromancer(necromancer);
        }

        for (int i = 0; i < 5; ++i) {
            // make the item and look up it's sprite
            auto heal = std::make_shared<HealingPotion>(4);
            heal->sprite = engine.graphics.get_sprite(heal->name);

            //place it on a random tile
            Vec heal_pos = engine.dungeon.random_open_room_tile();
            Tile& tile = engine.dungeon.get_tile(heal_pos);
            tile.item = heal;
        }

        // make item and look up sprite
        auto club = std::make_shared<SpikedClub>(6);
        club->sprite = engine.graphics.get_sprite(club->name);

        // place the item on a random tile
        Vec club_pos = engine.dungeon.random_open_room_tile();
        Tile& club_tile = engine.dungeon.get_tile(club_pos);
        club_tile.item = club;

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
