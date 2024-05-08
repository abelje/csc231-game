# Final Project
## Healing Potion
The healing potion item heals the player by a certain amount of health. Here's an example for creating the item:
```c++
hero->add_to_inventory(std::make_shared<HealingPotion>(5));
```
Potion takes makes inputted healing amount negative.
```c++
HealingPotion::HealingPotion(int health)
: Item{"potion_red"}, health{health * -1} {}
```
The item calls a hit on the player. Because the health inputted is made negative, the item heals the player. 
The item is removed from the inventory after use.
```c++
void HealingPotion::use(Engine& engine, Entity& owner) {
    engine.events.create_event<Hit>(owner, health);
    owner.remove_item(this);
}
```
The item is used by the player by calling a use item action.
```c++
else if (key == "H") {
            return std::make_unique<UseItem>();
        }
```
## Randomized Placement
Sprite is created for the engine to use. The engine chooses a random open tile and puts the healing potion item on it.
```c++
// make the item and look up it's sprite
auto heal = std::make_shared<HealingPotion>(4);
heal->sprite = engine.graphics.get_sprite(heal->name);
        
// place it on a random tile
Vec pos = engine.dungeon.random_open_room_tile();
Tile& tile = engine.dungeon.get_tile(pos);
tile.item = heal;
```
## Pickup Event
Takes in the entity to get the item.
```c++
PickUp::PickUp(Entity& entity)
:entity{entity} {}
```
Execute adds to inventory by taking the current tile position and adding the item to inventory
```c++
void PickUp::execute(Engine& engine) {
    //add to inventory
    Vec pos = entity.get_position();
    Tile& tiles = engine.dungeon.get_tile(pos);
    entity.add_to_inventory(tiles.item);
```
Execute than takes that item and overrides it with a blank item, removing it from the game world.
```c++
    // override item on tile with blank item to remove from game world
    std::shared_ptr<Item> item;
    tiles.item = item;
}
```
### Setting up an item for pickup
Using an interact function for an item that can be overridden, create a pickup event to be used on pickup.
```c++
void HealingPotion::interact(Engine& engine, Entity& entity) {
    // generate a pickup event
    engine.events.create_event<PickUp>(entity);
}
```
I applied this code to the Healing Potion and the Spiked Club, which are strewn across the dungeon.
## Use Item Action
Use item is a simple action. Takes in only one entity so the item can only be used on the user.
```c++
Result UseItem::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->get_current_item()->use(engine, *entity);
    return success();
}
```
The use function on the item should use the owner only use function that can be overridden.
```c++
void HealingPotion::use(Engine& engine, Entity& owner) override;
```
## Splash Potion
Splash Potion is an item that heals the user and to entities around the user in a box around the player.
### Constructor
```c++
SplashPotion::SplashPotion(int health)
: Item{"potion_blue"}, health{health * -1} {}
```
### Use Function
The use function heals the user of the potion and searches around the user for people of the same team to heal them.
```c++
void SplashPotion::use(Engine& engine, Entity& attacker, Entity& defender) {
    // heal user
    thrown->add_next(Hit{attacker, health});
    thrown->add_next(Animation{"magic", attacker.get_position()});

    // search and heal entities from the same team
    for(int i = -1; i < 1; i += 2) {
        // check up/down
        Vec pos_vertical = attacker.get_position() + Vec{0, i};
        Tile& vert_tiles = engine.dungeon.get_tile(pos_vertical);
        heal_defender(engine, attacker, defender, vert_tiles);

        // check left/right
        Vec pos_horizontal = attacker.get_position() + Vec{i, 0};
        Tile& horizontal_tiles = engine.dungeon.get_tile(pos_horizontal);
        heal_defender(engine, attacker, defender, horizontal_tiles);

        // check upper right and bottom left corners
        Vec corners = attacker.get_position() + Vec{i, i};
        Tile& corner = engine.dungeon.get_tile(corners);
        heal_defender(engine, attacker, defender, corner);

        // check upper left and bottom right corners
        Vec corners2 = attacker.get_position() + Vec{-i, i};
        Tile& corner2 = engine.dungeon.get_tile(corners2);
        heal_defender(engine, attacker, defender, corner2);
    }
}
```

### Helper function
The helper function, heal_defender that I created takes care of the hit events for the splash potion. This shrank down 
the repetition of checking for an entity.
```c++
void SplashPotion::heal_defender(Engine& engine, Entity& attacker, Entity& defender, Tile& tile) {
    if (tile.has_entity() && defender.get_team() == attacker.get_team() && !tile.is_wall()) {
        engine.events.create_event<Hit>(defender, health);
        engine.events.create_event<Animation>("magic", defender.get_position());
    }
}
```

## Necromancer
The necromancer uses the splash potion item to heal fellow monsters. The follow behavior is set up in a similar way to
the chaser behavior, but it checks for tiles around the monster and moving towards it.
```c++
for(int i = -1; i < 1; i += 1) {
        // check up/down
        Vec pos_vertical = entity.get_position() + Vec{0, i};
        Tile& vert_tiles = engine.dungeon.get_tile(pos_vertical);
        if (path(engine, entity, vert_tiles) != Vec {0,0}) {
            return std::make_unique<Move>(path(engine, entity, vert_tiles));
        }
```
The check gets the tile and then gets the Vec for the move using helper function.
```c++
Vec path(Engine& engine, Entity& entity,  Tile& tile) {
    // move if the tile has an entity, is on the same team, and is visible
    if (tile.has_entity() && tile.entity->get_team() == entity.get_team() && tile.entity->is_visible() && engine.hero && !tile.is_wall()) {
        auto path = engine.dungeon.calculate_path(entity.get_position(), tile.entity->get_position());
        if (path.size() > 1) {
            auto direction = path.at(1) - path.at(0);
            return direction;
        }
    }
    return Vec {0,0};
}
```
This checks for what is on the tile and returns the vector to move the monster.

### Change to Move
Changed the check for entity on the tile inside move to always attack. This makes it so the necromancer can heal other
monsters. This also means that I made it so monsters can attack each other.
```c++
if (tile.has_entity()) {
        return alternative(Attack{*tile.entity});
    }
```

