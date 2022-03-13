//#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "Confidant.h"
#include "EventDamage.h"
#include "EventEnemyTurn.h"
#include "EventStartTurn.h"
#include "Princess.h"
#include "Announcement.h"

#include <Windows.h>

Confidant::Confidant() {
	registerInterest(END_ENEMY_TURN_EVENT);
	setHP(80);
	setName("Confidant");
	setSprite("confidant");
	setPosition(df::Vector(60, 16));
	startTurnCount();
}

// handle event (return 0 if ignored, else return 1)
int Confidant::eventHandler(const df::Event* p_e) {
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

// draw Confidant and its hp on screen
int Confidant::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Confidant | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::BLUE, "Charming Confidant");
}

int Confidant::moveSet(int choice) {
	switch (choice) {
	case 1:
		LM.writeLog("Confidant | move 1 (betray) selected.");
		attackBetray();
		break;
	case 2:
		LM.writeLog("Confidant | move 2 (protect) selected.");
		attackProtect();
		break;
	case 3:
		LM.writeLog("Confidant | move 3 (realization) selected.");
		attackRealization();
		break;
	default:
		LM.writeLog("Confidant | move 1 (betray) selected.");
		attackBetray();
		break;
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return choice;
}

int Confidant::decideMove() {
	Princess* princess = dynamic_cast <Princess*> (getTarget());

	if (princess->getIronFast()) {
		return 3;
		LM.writeLog("Confidant | end turn.");
	}
	
	if (getTurnCount() % 2 == 0) return 1;
	else return 2;
}

void Confidant::attackProtect() {
	Announcement* announce_move = new Announcement("Your shield is beatiful, like the roses.", df::CYAN);
	dealDamage(20, getTarget());
}

void Confidant::attackBetray() {
	Announcement* announce_move = new Announcement("Betrayed you say? I cannot believe you!", df::CYAN);
	dealDamage(10, getTarget());
}

void Confidant::attackRealization() {
	Announcement* announce_move2 = new Announcement("You no longer need me, huh?", df::CYAN);
	Announcement* announce_move3 = new Announcement("I guess that is for the best.", df::CYAN);
	setHP(1); 
}
