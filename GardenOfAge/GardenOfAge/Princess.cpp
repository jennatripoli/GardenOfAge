#include <Windows.h>
#include "Princess.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "ViewObject.h"
#include "GameOver.h"


Princess::Princess() {
	setHP(80);
	setName("Princess");
	setSprite("princess");
	setPosition(df::Vector(20, 5));
}

Princess::~Princess() {
	new GameOver;
	//WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Princess::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
		if (getHP() <= 0) WM.markForDelete(this);
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
		break;
	case 2:
		LM.writeLog("PrincessMoveSet 2 selected");
		break;
	case 3:
		LM.writeLog("PrincessMoveSet 3 selected");
		break;
	default:
		LM.writeLog("PrincessMoveSet 4 selected");
		break;
	}
	return 0;
}

//three moves

//move 1 Impale Attack
//move 2 Guard Sheild
//move 3 Close Quarters
//healing move as mentioned by you granted by defeating sister
