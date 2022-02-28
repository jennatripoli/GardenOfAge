Project 3 Alpha - GardenOfAge
Jenna Tripoli, Evans Owusu

Character class houses all types of Characters in the game. This includes
Characters that are controlled by the player and enemies. This class houses
the health of the Character (HP). The draw() and eventHandler() functions 
are overridden by child classes. dealDamage() will send an EventDamage to the
indicated Character for the indicated amount of damage, and takeDamage() will
adjust the Character's health based on the amount of damage taken. drawHP() draws
the health of the Character under its sprite.

Enemy, Princess, and Tank are all child classes of Character.

Completion of the Phase class alongside a number of helper classes to facilate 
going through a menu system of a traditional rpg and selecting a character action.

The code is capable of having the player select what all their party members will do, 
end their turn and specifically the phase class will have specified buttons hold 
information such as a character move, send it via an event to the event handler to 
trigger the action.