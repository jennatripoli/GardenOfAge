#include "Princess.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "ViewObject.h"

Princess::Princess() {
	setHP(80);
	setName("Princess");
	setSprite("princess");
}

Princess::~Princess() {
	WM.markForDelete(this);
}

// handle event (return 0 if ignored, else return 1)
int Princess::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "damage") {
		const EventDamage* p_damage_event = dynamic_cast <const EventDamage*> (p_e);
		takeDamage(p_damage_event->getAmount());

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

	return drawHP(df::WHITE, "Princess");
}