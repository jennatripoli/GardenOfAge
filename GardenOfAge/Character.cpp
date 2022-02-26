#include "Character.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"

Character::Character() {
	df::Object::setType("Character");
	setPosition(df::Vector());

	setHP(0);
	setName("Character");
}

// these two functions will be overridden by their child classes
int Character::eventHandler(const df::Event* p_e) { return 0; }
int Character::draw() { return 0; }

// getters and setters for Character data
int Character::getHP() { return m_hp; }
void Character::setHP(int new_hp) { m_hp = new_hp; }
std::string Character::getName() { return m_name; }
void Character::setName(std::string new_name) { m_name = new_name; }

void Character::takeDamage(int damage) {
	setHP(getHP() - damage);
}

int Character::drawHP(df::Color color) {
	df::Vector hp_pos(getPosition().getX(), getPosition().getY() + 1);
	std::string hp_str = "HP: " + std::to_string(getHP());

	if (DM.drawString(hp_pos, hp_str, df::CENTER_JUSTIFIED, color) == -1) {
		LM.writeLog("Tank | draw() hp failure.");
		return -1;
	}

	return 0;
}
