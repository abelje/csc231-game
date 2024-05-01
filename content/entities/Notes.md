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

## 04/15
### Derefrencing
obj = *ptr // get obj being pointed to
ptr = &obj

## 04/17
### Checkpoint 2
Create OpenDoor Action (remember to add event
UpdateFOV) </n> x
Update Move::perform to return
alternative(OpenDoor{position}) when
appropriate </n>
Create two new Monsters (in addition to the
Masked Orc) </n>
Give all monsters a behavior function </n>
Add a few Monsters into your game (edit
main.cpp) </n>

### Items
Interact with, use on self and others </n>
Entities carry them </n>
Item causes damage to the entity not the entity itself.

## 04/23
### Checkpoint 3
Add Attack action
Modify Move::perform() to attack another entity if
on a different team
Add code for Hit and Die classes
Make two new weapons, give them to
hero/monsters
Make sure attacking works!

### Ideas for Items
Heart pickup to increase player health

## 04/26
Create_event swing, add_next to get other things
Can make execute delay event to delay time

### idea for final
Create a healing item that I can pick up. Make splash potions that can heal monsters in a general area.
Need to make a new action and event.