# Bug Log for Project
## 04/12
### change_direction not working consistently
This function is based on positive and negative direction for left and right. Use the direction of movement for the
positive or negative number.
```c++
entity->change_direction(direction);
```
You can get current direction for an entity using a helper function.
```c++
entity->get_direction();
```
### Entity is not moving
Make sure that the position that you are checking for is the tile in the direction you want to move.</n>
```c++
Vec pos = entity->get_position() + direction;
Tile& tile = engine.dungeon.get_tile(pos);
```
Make sure that the entity is set to move.
```c++
entity->move_to(pos);
```
### You have a behavior, but the executable won't build.
Make sure that the behavior that you have is nested in the namespace of the character.
```c++
namespace Heroes {
    
void make_knight(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("knight");
        hero->set_max_health(10);
        hero->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
        std::string key = engine.input.get_last_keypress();
        if (key == "Right" || key == "D") {
            return std::make_unique<Move>(Vec{1, 0});
        }
        else if (key == "Left" || key == "A") {
            return std::make_unique<Move>(Vec{-1, 0});;
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
        return nullptr;
    }
}
```