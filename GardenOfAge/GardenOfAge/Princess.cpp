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
	setPosition(df::Vector(20, 9.5));
	
	isIronfast = false; 
	isBraveHearty = false;
	isOfKinderedSpirit = false;
	isTheRightfulHeir = false; 
}

// handle event (return 0 if ignored, else return 1)
int Princess::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == DAMAGE_EVENT) {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		
		if (!isIronfast) {
			if (isBraveHearty != true) {
				takeDamage(p_damage_event->getAmount());
				dealDamage(p_damage_event->getAmount() / 10, getTarget());
			} else {			
				takeDamage(p_damage_event->getAmount() + 15); 
				isBraveHearty = false; 
			}
		} else {
			takeDamage((p_damage_event->getAmount()/2));
			isIronfast = false;
			if (isIronfast) {
				if (isBraveHearty != true) {
					takeDamage(p_damage_event->getAmount()/5);
					dealDamage(p_damage_event->getAmount() / 10, getTarget());
				} else takeDamage(p_damage_event->getAmount() + 5);
			} else takeDamage((p_damage_event->getAmount()));
		}	

		isIronfast = false;
		isTheRightfulHeir = false;

		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
		
		if (getHP() <= 0) {
			new GameOver;
			//WM.markForDelete(this);
		}
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
		//Sleep(500);
		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
	}

	return drawHP(df::YELLOW, "Princess Lyla");
}

 int Princess::characterMoveSet(int choice) {
	switch (choice) {
	case 1:
		LM.writeLog("Princess | moveset 1 (caliburn) selected.");
		Caliburn();
		break;
	case 2:
		LM.writeLog("Princess | moveset 2 (gilded shield) selected.");
		GildedShield();
		break;
	case 3:
		LM.writeLog("Princess | moveset 3 (honorless) selected.");
		Honorless();
		break;
	default:
		LM.writeLog("Princess | moveset 4 (holy light) selected.");
		HolyLight();
		break;
	}

	return 0; 
}

// damage multiplier
void Princess::Caliburn() {
	Announcement* announce_move = new Announcement("Caliburn Strikes.", df::YELLOW);

	if (isBraveHearty) {
	 dealDamage(80, getTarget());
	 isBraveHearty = false;
	} else dealDamage(37, getTarget()); 

	isOfKinderedSpirit = !isOfKinderedSpirit;

}

// reduce incoming damage
void Princess::GildedShield() {
	Announcement* announce_move = new Announcement("Gilded Sheild Protects.");
	isIronfast = true;
}

// deal 5 damage
void Princess::Honorless() {
	Announcement* announce_move = new Announcement("Honorless");
	isBraveHearty = true;
	dealDamage(5, getTarget());
}

// heal by 50 hp
void Princess::HolyLight() {
	 Announcement* announce_move = new Announcement("HolyLight");
	 
	int current_HP = getHP() + 50; 
	setHP(current_HP);

		isTheRightfulHeir = true; 
}

bool Princess::getIsIronFast() const { return isIronfast; }
bool Princess::getIsBraveHearty() const { return isBraveHearty; }
bool Princess::getisOfKinderedSpirit() const { return isOfKinderedSpirit; }
bool Princess::getisTheRightfulHeir() const { return isTheRightfulHeir; }
