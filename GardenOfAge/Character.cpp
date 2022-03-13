#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "Sound.h"
#include "ResourceManager.h"

#include "EventDamage.h"
#include "Character.h"

Character::Character() {
	df::Object::setType("Character");
	setPosition(df::Vector());

	setHP(0);
	setName("Character");
	turn_count = 1; 
}

// these functions will be overridden
int Character::eventHandler(const df::Event* p_e) { return 0; }
int Character::draw() { return 0; }
int Character::characterMoveSet(int choice) { return 0; }
int Character::decideMove() { return 0; }


// getters and setters for Character data
int Character::getHP() { return hp; }
void Character::setHP(int new_hp) { hp = new_hp; }
void Character::startTurnCount() { turn_count = 0; }
void Character::turnCountManage() { turn_count++; }
int Character::getTurnCount() const { return turn_count; }
std::string Character::getName() { return name; }
void Character::setName(std::string new_name) { name = new_name; }
int Character::getCharacterMove() const { return current_moveset; }
Character* Character::getTarget() const { return target; }
void Character::setTarget(Character* the_enemy) { target = the_enemy; }

int Character::setCharacterMove(int choice) {
	current_moveset = choice;
	return current_moveset;
}

// send parameter damage to a specific character
void Character::dealDamage(int damage, Character* recipient) {
	EventDamage* p_damage_event = new EventDamage(damage);
	recipient->eventHandler(p_damage_event);
}

// decrease Character's hp by parameter damage
void Character::takeDamage(int damage) {
	df::Sound* p_sound = RM.getSound("damage");
	if (p_sound != NULL) p_sound->play(false);

	if (getHP() - damage <= 0) setHP(0);
	else setHP(getHP() - damage);
}

// draw hp on screen underneath Character
int Character::drawHP(df::Color color, std::string name) {
	df::Vector hp_pos(getPosition().getX(), getPosition().getY() + 6);
	std::string hp_str = name + " HP: " + std::to_string(getHP());

	if (DM.drawString(hp_pos, hp_str, df::CENTER_JUSTIFIED, color) == -1) {
		LM.writeLog("Character | draw() hp failure.");
		return -1;
	}

	return 0;
}
