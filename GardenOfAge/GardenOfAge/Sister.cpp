#include <Windows.h>
#include "Sister.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "EventEnemeyTurn.h"
#include "LogManager.h"
#include "ViewObject.h"
#include "Explosion.h"
#include "EventStartTurn.h"


Sister::Sister() {
	registerInterest(END_ENEMY_TURN_EVENT);
	setHP(80);
	setName("Sister");
	setSprite("sister");
	setPosition(df::Vector(60, 5));
	turnCountManage();

}

Sister::~Sister() {
	for (int i = -8; i <= 8; i += 5) {
		for (int j = -5; j <= 5; j += 3) {
			df::Vector temp_pos = this->getPosition();
			temp_pos.setX(this->getPosition().getX() + i);
			temp_pos.setY(this->getPosition().getY() + j);
			Explosion* p_explosion = new Explosion;
			p_explosion->setPosition(temp_pos);
		}
	}

	//WM.markForDelete(this);Sister
}

// handle event (return 0 if ignored, else return 1)
int Sister::eventHandler(const df::Event* p_e) {
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

// draw Sister and its HP on screen
int Sister::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Sister | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		Sleep(500);
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::MAGENTA, "Raile the Magic Warrior");
}

int Sister::characterMoveSet(int choice) {
	if (true)
	{
		LM.writeLog("Boo EnenemyTurn , %d", getTurnCount());
	}

	EventStartTurn* nextTurn = new EventStartTurn();
	Character* the_player = getTarget();
	the_player->eventHandler(nextTurn);

	return 0;
}
