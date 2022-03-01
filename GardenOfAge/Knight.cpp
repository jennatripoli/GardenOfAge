#include "Knight.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "ViewObject.h"

Knight::Knight() {
	setHP(80);
	setName("Knight");
	setSprite("knight");
}

Knight::~Knight() {
	//WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Knight::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		return 1;
	}

	return 0;  // event ignored
}

// draw Princess and its HP on screen
int Knight::draw() {
	if (Object::draw() == -1) {
		LM.writeLog("Knight | draw() failure.");
		return -1;
	}

	return drawHP(df::WHITE, "Little Knight");
}

int Knight::moveSet(int choice) {
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
