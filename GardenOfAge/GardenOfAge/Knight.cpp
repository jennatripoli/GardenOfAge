#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "Knight.h"
#include "EventDamage.h"
#include "EventEnemyTurn.h"
#include "Explosion.h"
#include "EventStartTurn.h"
#include "Princess.h"
#include "Announcement.h"

//#include <Windows.h>

Knight::Knight() {
	registerInterest(END_ENEMY_TURN_EVENT);
	setHP(80);
	setName("Knight");
	setSprite("knight");
	setPosition(df::Vector(60, 16));

	startTurnCount();
	priorMove = 0;
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
		turnCountManage();
		setCharacterMove(decideMove());
		characterMoveSet(getCharacterMove());
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
		//Sleep(500);
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::CYAN, "Little Knight");
}

int Knight::characterMoveSet(int choice) {

	LM.writeLog("Knight | EnenemyTurn %d.", getTurnCount());
	LM.writeLog("Knight | move %d.", getCharacterMove());

	switch (choice) {
	case 1:
		arrows();
		break;
	case 2:
		struggle();
		break;
	case 3:
		comrades();
		break;
	case 4:
		areHonorless();
		break;
	case 5:
		noSavior();
		break;
	default:
		noSavior();
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return choice;
}

int Knight::decideMove() {
	Princess* princess = dynamic_cast <Princess*> (getTarget());

	// no savior
	if (getTurnCount() > 5) return 5;

	else {
		// are honorless
		if (priorMove == 1) {
			priorMove = 0;
			return 4;
		}

		if (princess->getIsBraveHearty()) {
			priorMove = 1;
			return 1;
		}

		// comrades
		if (priorMove == 1) {
			priorMove = 0;
			return 3;
		}

		// struggle
		if (princess->getisOfKinderedSpirit()) return 2;

		// arrows
		if (princess->getHP() >= 10) return 1;
	}
}

void Knight::arrows() {
	Announcement* announce_move = new Announcement("Rain of Arrows", df::CYAN);
	dealDamage(20, getTarget());
}

void Knight::struggle() {
	Announcement* announce_move = new Announcement("We are but children.... fighting", df::CYAN);
	int current_HP = getHP() + 20;
	setHP(current_HP);
}

void Knight::comrades() {
	Announcement* announce_move = new Announcement("We serve the day we breathe all rulers", df::CYAN);
	Announcement* announce_move2 = new Announcement("For all rulers higher than us sprots", df::CYAN);
}

void Knight::areHonorless() {
	Announcement* announce_move = new Announcement("Are you honorless", df::CYAN);
	dealDamage(getTarget()->getHP() / 4, getTarget());
}

void Knight::noSavior() {
	Announcement* announce_move = new Announcement("You are not our savior...", df::CYAN);
	dealDamage(getTurnCount() * 7, getTarget());
}
