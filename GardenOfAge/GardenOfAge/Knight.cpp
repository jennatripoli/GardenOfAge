#include "Knight.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "ViewObject.h"
#include "Explosion.h"
#include <Windows.h>

Knight::Knight() {
	setHP(80);
	setName("Knight");
	setSprite("knight");
	setPosition(df::Vector(60, 5));
}

Knight::~Knight() {
	/*for (int i = -8; i <= 8; i += 5) {
		for (int j = -5; j <= 5; j += 3) {
			df::Vector temp_pos = this->getPosition();
			temp_pos.setX(this->getPosition().getX() + i);
			temp_pos.setY(this->getPosition().getY() + j);
			Explosion* p_explosion = new Explosion;
			p_explosion->setPosition(temp_pos);
		}
	}*/

	//WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Knight::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
		return 1;
	}

	return 0;  // event ignored
}

// draw Knight and its HP on screen
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
	int t = 0;
	switch (choice) {
	case 1:


		t = 20;
		break;
	case 2:
		t = 1;
		break;
	}
	return t;
}
