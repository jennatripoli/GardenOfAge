#include "Tank.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"

Tank::Tank() {
	setHP(100);
	setName("Tank");
}

Tank::~Tank() {
	WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Tank::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

		return 1;
	}

	return 0;  // event ignored
}

// draw Tank and its HP on screen
int Tank::draw() {
	if (DM.drawCh(getPosition(), 'O', df::GREEN) == -1) {
		LM.writeLog("Tank | draw() failure.");
		return -1;
	}

	return drawHP();
}
