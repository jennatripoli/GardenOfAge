#include "Princess.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "ViewObject.h"
#include "GameOver.h"
#include <Windows.h>

Princess::Princess() {
	setHP(80);
	setName("Princess");
	setSprite("princess");
	setPosition(df::Vector(20, 5));
}

Princess::~Princess() {
	new GameOver;
	//WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Princess::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		setPosition(df::Vector(getPosition().getX() - 1, getPosition().getY()));
		if (getHP() <= 0) WM.markForDelete(this);
		return 1;
	}

	return 0;  // event ignored
}

// draw Princess and its HP on screen
int Princess::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Princess | draw() failure.");
		return -1;
	}

	if (getPosition().getX() != 20) {
		Sleep(500);
		setPosition(df::Vector(getPosition().getX() + 1, getPosition().getY()));
	}

	return drawHP(df::YELLOW, "Princess Lyla");
}

int Princess::moveSet(int choice) {
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
