//#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "Knight.h"
#include "EventDamage.h"
#include "EventEnemyTurn.h"
#include "EventStartTurn.h"
#include "Princess.h"
#include "Announcement.h"

#include <Windows.h>

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
		setMove(decideMove());
		moveSet(getMove());
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
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::CYAN, "Little Knight");
}

int Knight::moveSet(int choice) {

	LM.writeLog("Knight | EnemyTurn %d.", getTurnCount());
	LM.writeLog("Knight | move %d.", getMove());

	switch (choice) {
	case 1:
		attackArrows();
		break;
	case 2:
		attackStruggle();
		break;
	case 3:
		attackComrades();
		break;
	case 4:
		attackIsHonorless();
		break;
	case 5:
		attackNoSavior();
		break;
	default:
		attackNoSavior();
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
		// honorless
		if (priorMove == 1) {
			priorMove = 0;
			return 4;
		}

		// brave hearty
		if (princess->getBraveHearty()) {
			priorMove = 1;
			return 1;
		}

		// comrades
		if (priorMove == 1) {
			priorMove = 0;
			return 3;
		}

		// struggle
		if (princess->getKinderedSprit()) return 2;

		// arrows
		if (princess->getHP() >= 10) return 1;
	}
	return 0;
}

void Knight::attackArrows() {
	Announcement* announce_move = new Announcement("Rain of arrows!", df::CYAN);
	dealDamage(20, getTarget());
}

void Knight::attackStruggle() {
	Announcement* announce_move = new Announcement("We are just children...", df::CYAN);
	int current_HP = getHP() + 20;
	setHP(current_HP);
}

void Knight::attackComrades() {
	Announcement* announce_move = new Announcement("We serve since the day we take our first breath.", df::CYAN);
	Announcement* announce_move2 = new Announcement("For all rulers are higher than us children.", df::CYAN);
}

void Knight::attackIsHonorless() {
	Announcement* announce_move = new Announcement("Have you lost your honor?", df::CYAN);
	dealDamage(getTarget()->getHP() / 4, getTarget());
}

void Knight::attackNoSavior() {
	Announcement* announce_move = new Announcement("You are not our savior...", df::CYAN);
	dealDamage(getTurnCount() * 7, getTarget());
}
