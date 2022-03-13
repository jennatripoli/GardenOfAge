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
		setMove(decideMove());
		moveSet(getMove());
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

int Sister::moveSet(int choice) {
	switch (choice) {
	case 1:
		attackGatheringMagic();
		break;
	case 2:
		attackTaunt();
		break;
	case 3:
		attackElusiveStrike(); 
	default:
		attackElusiveStrike();
		break;
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return choice;
}

int Sister::decideMove() {
	Princess* princess = dynamic_cast <Princess*> (getTarget());

	if (princess->getIronFast()) return 3;
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
	
void Sister::attackGatheringMagic() {
	Announcement* announce_move1 = new Announcement("I was never treated like the flower you are.", df::CYAN);
	Announcement* announce_move3 = new Announcement("I gather the magic around me and strike!", df::CYAN);
	Announcement* announce_move2 = new Announcement("Oh, little sister...", df::CYAN);
}

void Sister::attackTaunt() {
	Announcement* announce_move2 = new Announcement("Can you handle this attack, sister?!", df::CYAN);
	dealDamage( (int) ((getTarget()->getHP() * .7)), getTarget());
}

void Sister::attackElusiveStrike() {
	Announcement* announce_move2 = new Announcement("How dare you trick me, the one who waters your garden?", df::CYAN);
	dealDamage(20, getTarget()); 
}
