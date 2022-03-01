#include "Character.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "EventDamage.h"

Character::Character() {
	df::Object::setType("Character");
	setPosition(df::Vector());

	setHP(0);
	setName("Character");
}

// these three functions will be overridden
int Character::eventHandler(const df::Event* p_e) { return 0; }
int Character::draw() { return 0; }
int Character::moveSet(int choice) { return 0; }


// getters and setters for Character data
int Character::getHP() { return m_hp; }
void Character::setHP(int new_hp) { m_hp = new_hp; }
std::string Character::getName() { return m_name; }
void Character::setName(std::string new_name) { m_name = new_name; }

// send parameter damage to a specific character
void Character::dealDamage(int damage, Character* recipient) {
	EventDamage* p_damage_event = new EventDamage(damage);
	recipient->eventHandler(p_damage_event);
}

// decrease Character's m_hp by parameter damage
void Character::takeDamage(int damage) {
	if (getHP() - damage <= 0) setHP(0);
	else setHP(getHP() - damage);
}

// draw HP on screen underneath Character
int Character::drawHP(df::Color color, std::string name) {
	df::Vector hp_pos(getPosition().getX(), getPosition().getY() + 6);
	std::string hp_str = name + " HP: " + std::to_string(getHP());

	if (DM.drawString(hp_pos, hp_str, df::CENTER_JUSTIFIED, color) == -1) {
		LM.writeLog("Character | draw() hp failure.");
		return -1;
	}

	return 0;
}
