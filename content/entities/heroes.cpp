#include "heroes.h"

#include "action.h"
#include "big_sword.h"
#include "closedoor.h"
#include "engine.h"
#include "healing_potion.h"
#include "move.h"
#include "rest.h"
#include "use_item.h"

namespace Heroes {

    void make_knight(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("knight");
        hero->set_max_health(10);
        hero->add_to_inventory(std::make_shared<BigSword>(4));
        hero->add_to_inventory(std::make_shared<HealingPotion>(5));
        hero->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        std::string key = engine.input.get_last_keypress();
        if (key == "Right" || key == "D") {
            return std::make_unique<Move>(Vec{1, 0});
        }
        else if (key == "Left" || key == "A") {
            return std::make_unique<Move>(Vec{-1, 0});
        }
        else if (key == "Up" || key == "W") {
            return std::make_unique<Move>(Vec{0, 1});
        }
        else if (key == "Down"|| key == "S") {
            return std::make_unique<Move>(Vec{0, -1});
        }
        else if (key == "R") {
            return std::make_unique<Rest>();
        }
        else if (key == "C") {
            return std::make_unique<CloseDoor>();
        }
        else if (key == "H") {
            return std::make_unique<UseItem>();
        }
        else if (!key.empty() && std::isdigit(key.at(0))){
            int item_num = std::stoi(key) - 1; // "1" -> index 0
            entity.select_item(item_num);
        }
        return nullptr;
    }
}
