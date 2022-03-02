#include <Windows.h>
#include "Princess.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "ViewObject.h"
#include "GameOver.h"
#include "Announcement.h"

Princess::Princess() {
	setHP(80);
	setName("Princess");
	setSprite("princess");
	setPosition(df::Vector(20, 5));
	
	isIronfast = false; 
	isBraveHearty = false;
	isOfKinderedSpirit = false;
	isTheRightfulHeir = false; 
}

Princess::~Princess() {
	//WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Princess::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		//isbraveHearty
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		
		if (!isIronfast) {
			if (isBraveHearty != true) takeDamage(p_damage_event->getAmount());
			else {			
				takeDamage(p_damage_event->getAmount() * 2); 
				isBraveHearty = false; 
			}
		} else {
			takeDamage((p_damage_event->getAmount()/2));
			isIronfast = false;
		}
		
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
		if (getHP() <= 0) {
			new GameOver;
			//WM.markForDelete(this);
		}
		return 1;
	}
	return 0;  // event ignored
}

// draw Princess and its HP on screen
int Princess::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Princess | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 20) {
		Sleep(500);
		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
	}

	return drawHP(df::YELLOW, "Princess Lyla");
}

 int Princess::characterMoveSet(int choice)
{
	switch (choice)
	{
	case 1:
		LM.writeLog("PrincessMoveSet 1 selected");
		Caliburn();
		break;
	case 2:
		LM.writeLog("PrincessMoveSet 2 selected");
		GildedSheild();
		break;
	case 3:
		LM.writeLog("PrincessMoveSet 3 selected");
		Honorless();
		break;
	default:
		LM.writeLog("PrincessMoveSet 4 selected");
		HolyLight();
		break;
	}
	return 0; 
}

 // damage multiplier
 void Princess::Caliburn()
{
 Announcement* announce_move = new Announcement("Caliburn Strikes", df::YELLOW);
	 //int mutliplier?
 if (isBraveHearty)
 {
	 dealDamage(60, getTarget());
	 isBraveHearty = false;
 }
 else
	 dealDamage(20, getTarget()); 
}

 void Princess::GildedSheild()

{ // reduces incoming damge by
	Announcement* announce_move = new Announcement("Gilded Sheild Protects");
	isIronfast = true;
}


void Princess::Honorless()
{
 //setmultiplier move deal 1 damage
 Announcement* announce_move = new Announcement("Honorless");
isBraveHearty = true;
dealDamage(5, getTarget());
}

 void Princess::HolyLight() {
	 Announcement* announce_move = new Announcement("HolyLight");
	 if (isTheRightfulHeir) {

	 } else {
		int current_HP = getHP() + 50; 
		setHP(current_HP);
	 }
 }

 bool Princess::getIsIronFast() const
 {
	 return isIronfast;
 }
 
 bool Princess::getIsBraveHearty() const
 {
	 return isBraveHearty;
 }

 bool Princess::getisOfKinderedSpirit() const
 {
	 return isOfKinderedSpirit;
 }

 bool Princess::getisTheRightfulHeir() const
 {
	 return isTheRightfulHeir;
 }
//three moves

//move 1 Impale Attack
//move 2 Guard Sheild
//move 3 Close Quarters
//healing move as mentioned by you granted by defeating sister
