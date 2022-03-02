#include <Windows.h>
#include "Father.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "EventEnemeyTurn.h"
#include "LogManager.h"
#include "ViewObject.h"
#include "EventStartTurn.h"


Father::Father() {
	registerInterest(END_ENEMY_TURN_EVENT);
	setHP(120);
	setName("Father");
	setSprite("father");
	setPosition(df::Vector(60, 5));
	turnCountManage();
}

Father::~Father() {
	//WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Father::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
		return 1;
	}

	if (p_e->getType() == END_ENEMY_TURN_EVENT)
	{
		setCharacterMove(decideMove());
		characterMoveSet(getCharacterMove());
	}

	return 0;  // event ignored
}

// draw Princess and its HP on screen
int Father::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Father | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		Sleep(500);
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::WHITE, "Ghost of Father");
}

int Father::characterMoveSet(int choice) {
	if (true)
	{
		LM.writeLog("Boo EnenemyTurn , %d", getTurnCount());
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return 0;
}
