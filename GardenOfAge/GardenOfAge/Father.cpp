#include <Windows.h>

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

//#include <Windows.h>

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
		setCharacterMove(decideMove());
		characterMoveSet(getCharacterMove());
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

	return drawHP(df::WHITE, "Ghost of Father");
}

int Father::characterMoveSet(int choice) {
	switch (choice) {
	case 1:
		woeIsMe();
		break;
	case 2:
		woeIsYou();
		break;
	case 3:
		theEnd();
		break;
	default:
		theEnd();
		break;
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return choice;
}

int Father::decideMove() {
	Princess* princess = dynamic_cast <Princess*> (getTarget());

	if (princess->getisTheRightfulHeir()){
		return 3; 
		LM.writeLog("Father | end turn.");
	}
	
	if (getTurnCount() % 2 == 0) return 1;
	else return 2;
}

void Father::woeIsMe() {
	Announcement* announce_move = new Announcement("Woe is me, Dead king of an unkempt garden", df::CYAN);
	Announcement* announce_move2 = new Announcement("Can a light shower groawth on me", df::CYAN);
	int current_HP = getHP() + 30;
	setHP(current_HP);
}

void Father::woeIsYou() {
	Announcement* announce_move = new Announcement("Woe is you sprout in a garden not yours", df::CYAN);
	Announcement* announce_move2 = new Announcement("Will you be the one to slay the weeds of youthful sprouts", df::CYAN);
	if(getTarget()->getHP() != 0) dealDamage(getTarget()->getHP() / 2, getTarget());
}

void Father::theEnd() {
	Announcement* announce_move = new Announcement("Have I failed you...I'm sorry", df::CYAN);
	setHP(1);
	getTarget()->setHP(80); 
}
