//#include <Windows.h>

#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "ViewObject.h"

#include "Sister.h"
#include "EventDamage.h"
#include "EventEnemyTurn.h"
#include "EventStartTurn.h"
#include "Princess.h"
#include "Announcement.h"

#include <Windows.h>

Sister::Sister() {
	registerInterest(END_ENEMY_TURN_EVENT);
	setHP(80);
	setName("Sister");
	setSprite("sister");
	setPosition(df::Vector(60, 16));
	startTurnCount();

	power_track = true;
}

// handle event (return 0 if ignored, else return 1)
int Sister::eventHandler(const df::Event* p_e) {
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

// draw Sister and its hp on screen
int Sister::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Sister | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::MAGENTA, "Raile the Magic Warrior");
}

int Sister::characterMoveSet(int choice) {
	switch (choice) {
	case 1:
		gatheringMagic();
		break;
	case 2:
		Taunt();
		break;
	case 3:
		eleusiveStrike(); 
	default:
		eleusiveStrike();
		break;
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return choice;
}

int Sister::decideMove() {
	Princess* princess = dynamic_cast <Princess*> (getTarget());

	if (princess->getIsIronFast()) return 3;
	else {
		if (power_track == true) {
			power_track = false;
			return 1;
		} else {
			power_track = true;
			return 2;
		}
	}
}
	
void Sister::gatheringMagic() {
	Announcement* announce_move1 = new Announcement("I was never treated like the flower you are", df::CYAN);
	Announcement* announce_move3 = new Announcement("I'll use theose around me and strike", df::CYAN);
	Announcement* announce_move2 = new Announcement("Come little sister", df::CYAN);
}

void Sister::Taunt() {
	Announcement* announce_move2 = new Announcement("Can you hadnle this SISTER!", df::CYAN);
	dealDamage((getTarget()->getHP() * .7), getTarget());
}

void Sister::eleusiveStrike() {
	Announcement* announce_move2 = new Announcement("You dare trick me, me who waters your sprout!", df::CYAN);
	dealDamage(20, getTarget()); 
}
