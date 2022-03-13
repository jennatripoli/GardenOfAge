Garden of Age
By Jenna Tripoli and Evans Owusu

The main technical features of Garden of Age are the usage of buttons. 
The combat is turn-based, with each selection that the player makes for 
attacks or defenses being controlled by buttons on screen. Each selection 
is then placed in a queue of actions to take, which are executed when the 
player ends their selection turn. There is a Character base class that is 
used to contain general information about both the player's Character and 
the Enemy Characters. For example, the current health of the Character is 
housed in the Character class and is adjusted based on the outcome of the 
battle. From there, child classes for each type of Character store more 
specific information, such as custom move sets, enemy decision trees, and 
sprites. The final boss of the game (Hallowed Regent) is the most difficult 
to defeat, but the player receives a new ability from the previous battle 
(against Raile the Magic Warrior) that adds a twist to the story and helps 
the player finish the game.

______________________________________________________________________________________________________________________________
Garden of Age is a turn-based strategy combat game. In this game, you      
play as Princess Lyla of Primus. When her father passed away a few years ago, 
Lyla was too young to be in charge of a country, so a regent ruled for her.                         
                                                                           
Now, many years have passed, by the regent has yet to relinquish his       
power. To reclaim the power that was once supposed to be hers, Lyla will   
battle against those who have wronged her in the past, in hopes to resolve 
her feelings about the kingdom and find peace within about growing up.  

______________________________________________________________________________________________________________________________
Lyla has 4 abilitites she'll be using to reclaim her throne!           
Each Ability modifies a hidden trait that enemies are aware of.       
Based on responses, patterns, and damge output, utilize Lyla's         
abilitites to claim her throne once and for all.                       
*If Lyla proves her right to her family, all her move upgrade!         
Press your button and end your turn to continue                        
Highlight OVER the text to click                                       
Caliburn-     A legendary sword that does 20 damage alone. if          
              honorless was used beforehand it does 50.                
              *Becomes Excalibur                                       
Honorless-    Allows for immense damage to enemies at the cost of      
              an extra turn.                                           
              *Pride in all Ivy                                        
GildedShield- A mythical sheild that halves incoming damage and        
              provides a portion of the damage back.                   
              *Thorn Sheild of Roses                                   
Holylight-    Grants Lyla 50 HP back as per her divine right.          
              *Divinerule                                                          

Boss Descriptions
______________________________________________________________________________________________________________________________
Little Knight

The knight is a child soldier turned adult-like that of the princess 
who is still in forced labor to the kingdom and the regent and serves as the first boss.

Knight's Moveset 

Arrows: deals 20 damage to princess

Struggle:      Knight cries out loud lamenting their past
               *Heals 20hp

Comrades:      No effects but announce and deplores current situation

Are Hnorless:  After seeing the princess use honorless, ask directly if she too 
 	       like the current rulers lack honor
	       *Next turn do quarter damage of princess's HP

No savior:     Knight gives up hope on princess
	       *Each turn afterward do increased damage (damage = turn count * 7) 
	
Behavior       The knight desperate for a chance to end their servitude yet is loyal checks to see if the princess is
	       their savior. Striking down when they see the Princess is honorless and later above everything else then 
	       healing themself if the princess is a kindred spirit.
______________________________________________________________________________________________________________________________
Beguile Confidant

A past caretaker of the princess, who is in affiliation with the regent. Gained her trust and betrayed her. She left the 
princess astray

Confidant's Moveset

Protect:        Confidant acknowledges the shield the princess holds. how it protects her on her own terms
		*Deals 20 damage

Betray:         The confident is appalled at being accused of treachery
		*Deals 10

Realizations    Seeing the error of her ways and that the Princess has grown to be one her own she submits
		*Sets HP to 1

Behavior	The confidant is of meek natured. Yet is still able to strike the princess. Switching attacks every turn 
		revealing hints on what she thinks of the princess and how to defeat herself.
______________________________________________________________________________________________________________________________
Lyla's Father, the Dead King

Similar to the confidant, the dead king has failed his daughter. He is a ghost that haunts her battles. He is filled with self-pity and fails to see how it affects his daughter.

Father's Moveset:

Woe is Me:	Wails of his regrets and not being able to manage his kingdom foretold as a garden. Hints at his 
		possible salvation. 
		*Heals self for 30HP

Woe is You:	Wails about how the daughter is in his garden, seeing her as someone taking over his garden. Failing
		to see that it's theirs together.
		*Deals half HP of princess health

The End:        If saved by the holy light, realizes his mistakes and submits much like the confidant.
		*Sets HP to 1 heals Princess up to 80 HP

Behavior:	A regretful ghost that can only see the past. Switching every turn between self-pity and hostility towards his daughter. It is only his daughter that can provide him salvation via HolyLight.
______________________________________________________________________________________________________________________________
Raille the Magic Warrior

The estranged older sister of the princess. A magic warrior who learns the ways of the regent and failing kingdom. Who sees her
sister as a rival instead of a fellow person to band together until the end. 

Raille's Moveset

Gathering Magic:   Threatening to use extremely powerful magic to nearly wipe her sister. Cursing out of jealousy and hatred
		   *Does Nothing but warns player to anticipate actions

Taunt: 		   Unleashes the massive attack if not betrayed
		   *Deals 70 percent of princess HP

Elusive Strike:    Seeing the princess attempt to shield herself enrages Raille to physically attacking the princess
		   *Deals 20

Behavior:  	   Switching between taunting and gathering magic. Raille is an out-of-control character. Only stopping the cycle if
		   the princess shield herself.
______________________________________________________________________________________________________________________________
Hallowed Regent		

The corrupted official who took away the kingdom from the princess in her youth. Now that she has returned he provides harsh attacks
ultimately not seeing the value of the youth who he stole much from like the knight and the princess.

Regent's Moveset

Famine of Weeds:	The regent cruelty has lead to massive famine that the princess can't help but feel the pressure
			*Deals 20 damage every for 3 turns straight each.

Respect My Rule:	The regent outwardly demands respect to the princess despite all that's happened because of his older age 
			and position
			*Deals 60 damage to princess directly

Are you Even Worthy:	To add insult to injury, the regent questions the princess royal worth and ability to the erasure of responsibility
			Not acknowledging her or given her a chance
			*Heals HP by 40 deals 30 damage to princess

Behavior: 		If the regent sees the princess showing that she is worthy, lastly foster some sort of hope has divine right, 
			he questions it above all else. 
			Every 3 turns calls forth a reminder of famine and other deeds to discourage the princess
			Otherwise flaunting his power and demanding her to yield.