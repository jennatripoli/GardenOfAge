#include "LogManager.h"
#include "CharacterButton.h"
#include "MenuGuide.h"
#include "MenuButton.h"
#include "CharacterActionButton.h"
#include "ViewObject.h"
#include "Color.h"

CharacterButton::CharacterButton() {
	setType(MENUBUTTON);
	setBorder(false);
	setViewString("");
	setHighlightColor(df::WHITE);
	setDefaultColor(df::WHITE);
	showDisplay = false;
	character_guide = new MenuGuide();

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
	character_guide = new MenuGuide();

	int y_view = 8;
	int x_view = 5;
	int stored_move = 1;
	for (int i = 0; i < 4; i++)
	{
		CharacterActionButton* current_button = new CharacterActionButton(stored_move, stored_character, "Attack " + i);
		stored_move++;
		current_button->setLocation(x_view, y_view);
		if (i % 2 == 0)
			x_view += 2;
		else
		{
			x_view -= 2;
			y_view++;
		}
		character_guide->addButton(current_button);
	}
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
	LM.writeLog("Character Button");

}
