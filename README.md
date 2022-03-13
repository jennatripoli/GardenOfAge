# Garden of Age
 
Garden of Age is a turn-based strategy combat game. In this game, you play as Princess Lyla of Primus. When her father passed away a few years ago, Lyla was too young to be in charge of a country, so a regent ruled for her. Now, many years have passed, by the regent has yet to relinquish his power. To reclaim the power that was once supposed to be hers, Lyla will battle against those who have wronged her in the past, in hopes to resolve her feelings about the kingdom and find peace within about growing up.

This game was developed in C++ utilizing SFML-2.5.1 with the Dragonfly Engine.
______________________________________________________________________________________________________________________________

## **Princess Lyla (The Player)**

Lyla has four abilities she can use to reclaim her throne! Use the mouse to click the button corresponding to the move that you want to take, and click the End Turn button to lock in your choice. Based on responses, patterns, and damage output, utilize Lyla's abilities to claim her throne once and for all. When the Princess is deemed the True Ruler, each ability is modified to have a new trait, and enemies are aware of this.
                                      
### **Caliburn**  
A legendary sword that does 20 damage alone. If Honorless was used beforehand, it deals 50 damage.  
_True Ruler Ability: Caliburn Increased Strength_  

### **Honorless**  
Allows for immense damage to enemies, at the cost of an extra turn.  
_True Ruler Ability: Pride_  

### **Gilded Shield**  
A mythical shield that halves incoming damage and sends a portion of the damage back.  
_True Ruler Ability: Thorn Shield_  

### **Holy Light**  
Grants Lyla 50 HP back as per her divine right.  
_True Ruler Ability: Divine Rule_  
______________________________________________________________________________________________________________________________

## **Little Knight (Enemy #1)**

The knight is a young soldier of a similar age to the Princess but is still in forced labor to the kingdom. The knight is desperate for a chance to end their servitude, yet is loyal to the crown. He checks to see if the princess is their savior, strikes when they see the Princess is honorless, and heals themselves if the Princess is a kindred spirit.

### **Arrows**  
Sends a shower of arrows. Deals 20 damage.  

### **Struggle**  
Cries out loud, lamenting the past. Heals self for 20 HP.  

### **Comrades**  
No effects, but announces the current situation.  

### **Honorless**  
After seeing the princess use honorless, he asks if she lacks honor. Deals 25% of the Princess' HP in damage.  

### **Not a Savior**  
Gives up hope that the Princess will be able to save the kingdom. Deals increased damage every turn afterward, equivalent to the turn count multiplied by seven.  
______________________________________________________________________________________________________________________________

## **Charming Confidant (Enemy #2)**

The confidant is a past caretaker of the Princess and is affiliated with the regent. They gained Lyla's trust and betrayed her when her father passed. The confidant is quiet but is still able to strike the Princess without fear. They switch attacks every turn, revealing what they think of the Princess and how Lyla can defeat them.

### **Protect**  
Acknowledges the shield the Princess holds. Deals 20 damage.  

### **Betrayal**  
Appalled at being accused of treachery. Deals 10 damage.  

### **Realization**  
Seeing the error of their ways and that the Princess is independent, they accept defeat. Sets own HP to 1.  
______________________________________________________________________________________________________________________________

## **Ghost of the King (Enemy #3)**

The ghost is the spirit of the previous king, who was the Princess' father. He failed his daughter by not protecting her from the evils of the regent, and he haunts his daughter. He is filled with self-pity and fails to see how his actions impact his daughter. The ghost switches every turn between self-pity and hostility towards his daughter. It is only Lyla that can provide him salvation with Holy Light.

### **Woe is Me**  
Cries about his regrets and not being able to manage his kingdom. Heals self for 30 HP.  

### **Woe is You**  
Hurt that his daughter, the Princess, has taken over his garden. Deals 50% of the Princess' HP in damage.  

### **The End**  
If saved by holy light, he realizes his mistakes and accepts defeat. Sets own HP to 1 and heals the Princess to 80 HP.  
______________________________________________________________________________________________________________________________

## **Raille the Magic Warrior (Enemy #4)**

The warrior is the estranged older sister of the Princess. She learned the ways of the regent and failing kingdom and sees her sister as a rival up until the very end of their battle. She switches between taunting and gathering magic, and is an out-of-control character. This cycle is only stopped if the Princess shields herself.

### **Gathering Magic**  
Threatens to use extremely powerful magic to defeat sister. No effects, but warns the Princess.  

### **Taunt**  
Unleashes a massive attack. Deals 70% of the Princess' HP in damage.  

### **Elusive Strike**  
Seeing the Princess attempt to shield herself, she becomes enraged. Deals 20 damage.  
______________________________________________________________________________________________________________________________

## **Hallowed Regent	(Enemy #5)**

The regent is the corrupt official who took the kingdom away from the Princess in her youth. He only sees her as a child, not realizing she has grown. Now that Lyla has returned to fight, he sends harsh attacks, too blind to see the value of a youth perspective in the kingdom. If the regent sees the Princess showing that she is worthy of the throne, he questions it. Every three turns, he calls a reminder of the famine that he can cause with his powers, to discourage the Princess from attacking. He flaunts his power and demands that Lyla yields to him.

### **Famine**  
Cruelty led to massive famine that the Princess feels responsible for. Deals 20 damage every turn for three turns.  

### **Respect**  
Outwardly demands respect from the Princess purely because of age and power. Deals 60 damage.  

### **Not Worthy**  
Questions the Princess' royal worthiness. Heals himself by 40 HP and deals 30 damage.  
