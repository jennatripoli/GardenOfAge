#include "CharacterButton.h"
#include "MenuButton.h"
#include "ViewObject.h"
#include "Color.h"

CharacterButton::CharacterButton() {
	setType(MENUBUTTON);
	setBorder(false);
	setViewString("");
	setHighlightColor(df::WHITE);
	setDefaultColor(df::WHITE);
	showDisplay = false;
}

//use adress for character
CharacterButton::CharacterButton(Character* character, df::Color c_highlight, df::Color c_default) {
	setType(MENUBUTTON);
	setBorder(false);
	setViewString(character->getName());
	setHighlightColor(c_highlight);
	setDefaultColor(c_default);
	showDisplay = false;
	stored_character = character;
}

Character* CharacterButton::getCharacter() const {
	// TODO: insert return statement here
	return stored_character;
}

bool CharacterButton::isDisplayed() const {
	return showDisplay;
}

void CharacterButton::setDisplayed(bool new_state) {
	showDisplay = new_state;
}

void CharacterButton::callback() {
	showDisplay = !showDisplay;
}
