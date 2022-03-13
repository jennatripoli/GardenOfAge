//#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "Father.h"
#include "EventDamage.h"
#include "EventEnemyTurn.h"
#include "EventStartTurn.h"
#include "Princess.h"
#include "Announcement.h"

#include <Windows.h>

Father::Father() {
	registerInterest(END_ENEMY_TURN_EVENT);
	setHP(120);
	setName("Father");
	setSprite("father");
	setPosition(df::Vector(60, 16));
	startTurnCount();
}

// handle event (return 0 if ignored, else return 1)
int Father::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == DAMAGE_EVENT) {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());
		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
		return 1;
	}

	if (p_e->getType() == END_ENEMY_TURN_EVENT) {
		turnCountManage();
		setMove(decideMove());
		moveSet(getMove());
		return 1;
	}

	return 0;  // event ignored
}

// draw Father and its hp on screen
int Father::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Father | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::WHITE, "Ghost of the King");
}

int Father::moveSet(int choice) {
	switch (choice) {
	case 1:
		LM.writeLog("Father | move 1 (woe is me) selected.");
		attackWoeIsMe();
		break;
	case 2:
		LM.writeLog("Father | move 2 (woe is you) selected.");
		attackWoeIsYou();
		break;
	case 3:
		LM.writeLog("Father | move 3 (the end) selected.");
		attackTheEnd();
		break;
	default:
		LM.writeLog("Father | move 3 (the end) selected.");
		attackTheEnd();
		break;
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return choice;
}

int Father::decideMove() {
	Princess* princess = dynamic_cast <Princess*> (getTarget());

	if (princess->getRightfulHeir()){
		return 3; 
		LM.writeLog("Father | end turn.");
	}
	
	if (getTurnCount() % 2 == 0) return 1;
	else return 2;
}

void Father::attackWoeIsMe() {
	Announcement* announce_move = new Announcement("Woe is me, the dead king of a messy garden.", df::CYAN);
	Announcement* announce_move2 = new Announcement("I shower myself in the rain of a plentiful harvest.", df::CYAN);
	int current_HP = getHP() + 30;
	setHP(current_HP);
}

void Father::attackWoeIsYou() {
	Announcement* announce_move = new Announcement("How dare you sprout in a garden that is not yours?", df::CYAN);
	if(getTarget()->getHP() != 0) dealDamage(getTarget()->getHP() / 2, getTarget());
}

void Father::attackTheEnd() {
	Announcement* announce_move = new Announcement("Have I failed you, my dearest daughter?", df::CYAN);
	Announcement* announce_move2 = new Announcement("I... am so sorry.", df::CYAN);
	setHP(1);
	getTarget()->setHP(80); 
}
