//#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "Princess.h"
#include "GameOver.h"
#include "Announcement.h"
#include "EventDamage.h"

#include <Windows.h>

Princess::Princess() {
	setHP(80);
	setName("Princess");
	setSprite("princess");
	setPosition(df::Vector(20, 16));
	
	iron_fast = false; 
	brave_hearty = false;
	kindered_spirit = false;
	rightful_heir = false; 
	setTrueRuler(false);
	victor = false;
}

void Princess::setVictory(bool state)
{
	victor = state; 
}

// handle event (return 0 if ignored, else return 1)
int Princess::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == DAMAGE_EVENT) {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
	
		if (iron_fast) {
			takeDamage((p_damage_event->getAmount() / 2));
			dealDamage((p_damage_event->getAmount() / 3), getTarget());
			iron_fast = false;
			rightful_heir = false;
		} else {				
			if (kindered_spirit) takeDamage(p_damage_event->getAmount() * (.9));
			else takeDamage(p_damage_event->getAmount());
			rightful_heir = false;
		}

		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
		
		if (victor) new GameOver(true);
		if (getHP() <= 0) new GameOver();	

		return 1;
	}

	return 0;  // event ignored
}

// draw Princess and its hp on screen
int Princess::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Princess | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 20) {
		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
	}

	return drawHP(df::YELLOW, "Princess Lyla");
}

int Princess::moveSet(int choice) {
	switch (choice) {
	case 1:
		LM.writeLog("Princess | move 1 (caliburn) selected.");
		attackCaliburn();
		break;
	case 2:
		LM.writeLog("Princess | move 2 (gilded shield) selected.");
		attackGildedShield();
		break;
	case 3:
		LM.writeLog("Princess | move 3 (honorless) selected.");
		attackHonorless();
		break;
	default:
		LM.writeLog("Princess | move 4 (holy light) selected.");
		attackHolyLight();
		break;
	}

	return 0; 
}

// damage multiplier
void Princess::attackCaliburn() {
	Announcement* announce_move = new Announcement("Caliburn strikes the enemy.", df::YELLOW);

	if (brave_hearty) {
	 dealDamage(60, getTarget());
	 brave_hearty = false;
	} else dealDamage(30, getTarget()); 

	if (true_ruler) {
		Announcement* announce_move = new Announcement("True Ruler Ability: Caliburn Increased Strength");
		dealDamage(30, getTarget());
	}

	kindered_spirit = !kindered_spirit;
}

// reduce incoming damage
void Princess::attackGildedShield() {
	Announcement* announce_move = new Announcement("Protect me with the gilded shield.");
	iron_fast = true;

	if (true_ruler) {
		Announcement* announce_move = new Announcement("True Ruler Ability: Thorn Shield");
		dealDamage(15, getTarget());
	}
}

// deal 5 damage
void Princess::attackHonorless() {
	Announcement* announce_move = new Announcement("You have lost your honor.");
	brave_hearty = true;
	dealDamage(5, getTarget());

	if (true_ruler) {
		Announcement* announce_move = new Announcement("True Ruler Ability: Pride");
		iron_fast = true;
	}
}

// heal by 50 hp
void Princess::attackHolyLight() {
	 Announcement* announce_move = new Announcement("Handle the holy light!");
	 
	int current_HP = getHP() + 50; 
	setHP(current_HP);
	rightful_heir = true; 

	if (true_ruler) {
		Announcement* announce_move = new Announcement("True Ruler Ability: Divine Rule");
		int current_HP = getHP() + 40;
		setHP(current_HP);
	}
}

bool Princess::getIronFast() const { return iron_fast; }
bool Princess::getBraveHearty() const { return brave_hearty; }
bool Princess::getKinderedSprit() const { return kindered_spirit; }
bool Princess::getRightfulHeir() const { return rightful_heir; }
void Princess::setTrueRuler(bool state) { true_ruler = state; }
