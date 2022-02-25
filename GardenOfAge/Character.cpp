#include "Character.h"
#include "WorldManager.h"

Character::Character() {
	df::Object::setType("Character");
	setPosition(df::Vector());
	hp = 0;
}

int Character::eventHandler(const df::Event* p_e) { return 0; }

int Character::draw() { return 0; }

int Character::getHP() { return hp; }

void Character::setHP(int new_hp) { hp = new_hp; }
