# General Notes for Project
## 04/10
Move:Action
    Result perform(Eng,ent)
        ent-> move_to(pos) // up, down, left or right
Need all the private data

Don't try to create a Result directly, use helper functions!
success()
    Action worked, Entity finished turn
failure()
    Couldn't perform Action, give Entity another turn
alternative(AnotherAction{})
    Couldn't perform Action, do this one instead!

Wander for monsters, check for walkability and use alternative to make it Rest the turn

### Checkpoint 1
Create a Move action
Only move Hero to an empty tile
(success())
Walls doors, and other entities block
(failure())
Don't forget to set direction of entity
Key Bindings

#### Tiles
Common bug:
Vec position{1,2}
Tile& tile = engine.dungeon.get_tile(position);
// do things with tile

Remember to pass by reference Tile&

#### Behaviors
Taking turns 

## 04/12
#### Doors
To open the door do this:
```c++
tile.door->open();
```
Add a function to open door with a key?
Close Door Action