//#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "EventDamage.h"
#include "EventEnemyTurn.h"
#include "Explosion.h"
#include "EventStartTurn.h"
#include "Regent.h"
#include "Princess.h"
#include "Announcement.h"

#include <Windows.h>

Regent::Regent() {
	//registerInterest(END_ENEMY_TURN_EVENT);
	setHP(400);
	setName("Regent");
	setSprite("regent");
	setPosition(df::Vector(60, 11));
	startTurnCount();
	countdown = 0; 
}

// handle event (return 0 if ignored, else return 1)
int Regent::eventHandler(const df::Event* p_e) {
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

// draw Princess and its hp on screen
int Regent::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Confidant | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		//Sleep(500);
		//setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::RED, "Hallowed Regent");
}

int Regent::characterMoveSet(int choice) {

	switch (choice) {
	case 1:
		famineOfWeeds();
		break;
	case 2:
		respectMyrule();
		break;
	case 3:
		areYouEvenWorthy();
		break;
	default:
		famineOfWeeds();
		break;
	}

	if (countdown > 0) {
		Announcement* announce_move = new Announcement("Famine deicmate the youth", df::CYAN);
		dealDamage(20, getTarget());
		countdown--; 
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return 0;
}

int Regent::decideMove() {
	Princess* princess = dynamic_cast <Princess*> (getTarget());

	if (princess->getisTheRightfulHeir()) return 3; 
	if (getTurnCount() % 3 == 0) return 1;
	if (princess->getIsBraveHearty()) return 2;
	if (princess->getisOfKinderedSpirit()) return 3;
	return 0;
}

void Regent::famineOfWeeds() {
	Announcement* announce_move = new Announcement("Perpetual damage to drain the youth and aquire the crops I want", df::CYAN);
	countdown = 3;
}

void Regent::respectMyrule() {
	Announcement* announce_move = new Announcement("Yiled you unworthy child", df::CYAN);
	dealDamage(60, getTarget()); 
}

void Regent::areYouEvenWorthy() {
	Announcement* announce_move = new Announcement("How can you fathom what a child, fathom my power", df::CYAN);
	dealDamage(30, getTarget()); 
	int heal = getHP();
	setHP(getHP() + 40); 
}
