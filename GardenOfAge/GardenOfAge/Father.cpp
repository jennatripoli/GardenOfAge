#include "Father.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "ViewObject.h"
#include <Windows.h>

Father::Father() {
	setHP(120);
	setName("Father");
	setSprite("father");
	setPosition(df::Vector(60, 5));
}

Father::~Father() {
	//WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Father::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
		return 1;
	}

	return 0;  // event ignored
}

// draw Princess and its HP on screen
int Father::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Father | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 60) {
		Sleep(500);
		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
	}

	return drawHP(df::WHITE, "Ghost of Father");
}

int Father::characterMoveSet(int choice) {
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
