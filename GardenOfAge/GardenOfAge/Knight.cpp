//#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "Knight.h"
#include "EventDamage.h"
#include "EventEnemyTurn.h"
#include "Explosion.h"
#include "EventStartTurn.h"

#include <Windows.h>

Knight::Knight() {
	registerInterest(END_ENEMY_TURN_EVENT);
	setHP(80);
	setName("Knight");
	setSprite("knight");
	setPosition(df::Vector(60, 5));

	turnCountManage();
}

// handle event (return 0 if ignored, else return 1)
int Knight::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == DAMAGE_EVENT) {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
		return 1;
	}

	if (p_e->getType() == END_ENEMY_TURN_EVENT) {
		setCharacterMove(decideMove());
		characterMoveSet(0);
		return 1;
	}

	return 0;  // event ignored
}

// draw Knight and its hp on screen
int Knight::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Knight | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		Sleep(500);
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::CYAN, "Little Knight");
}

int Knight::characterMoveSet(int choice) {
	if (choice == 0) LM.writeLog("Boo EnemyTurn, %d", getTurnCount());

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return 0;
}
