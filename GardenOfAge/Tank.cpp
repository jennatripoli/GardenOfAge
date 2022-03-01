#include "Tank.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventDamage.h"
#include "LogManager.h"
#include "Explosion.h"

Tank::Tank() {
	setHP(100);
	setName("Tank");
	setSprite("generic");
}

Tank::~Tank() {
	for (int i = -4; i <= 4; i += 2) {
		for (int j = -4; j <= 4; j += 2) {
			df::Vector temp_pos = this->getPosition();
			temp_pos.setX(this->getPosition().getX() + i);
			temp_pos.setY(this->getPosition().getY() + j);
			Explosion* p_explosion = new Explosion;
			p_explosion->setPosition(temp_pos);
		}
	}
}

// handle event (return 0 if ignored, -1 if removed, else return 1)
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
	if (Object::draw() == -1) {
		LM.writeLog("Tank | draw() failure.");
		return -1;
	}

	return drawHP(df::WHITE, "Tank");
}
