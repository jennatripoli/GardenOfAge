Project 3 Alpha - GardenOfAge
Jenna Tripoli, Evans Owusu

TESTING: When running the code, the game start screen will appear. Press p to play or
q to quit the start screen. If p is pressed, the screen will change to have two sprites
on screen, one of a princess (the character the player is playing as) and a red box
that is a placeholder for the enemy. There are two relevant buttons to be pressed, 
one that damages the enemy by 7 HP, and the other that damages the enemy by 40 HP. Press
these buttons to decrease the health of the enemy. If the health of the enemy is less
than or equal 0, it will just be set to 0 and will not be decreased any more.

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