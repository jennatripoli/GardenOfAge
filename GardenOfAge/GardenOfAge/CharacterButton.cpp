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

	show_display = false;
	character_guide = new MenuGuide();
}

CharacterButton::CharacterButton(Character* character, df::Color c_highlight, df::Color c_default) {
	setType(MENUBUTTON);
	setBorder(false);
	setViewString("");
	setHighlightColor(c_highlight);
	setDefaultColor(c_default);
	show_display = false;
	stored_character = character;
	character_guide = new MenuGuide();

	int y_view = 1;
	int x_view = 1.5;
	int stored_move = 1;
	std::string move_name = "";

	for (int i = 0; i < 4; i++) {
		// hardcode nanmes for functions
		if (stored_move == 1)
			move_name = "Caliburn";
		if (stored_move == 2)
			move_name = "Gilded Shield";
		if (stored_move == 3)
			move_name = "Honorless";
		if (stored_move == 4)
			move_name = "Holy Light";

		CharacterActionButton* current_button = new CharacterActionButton(stored_move, stored_character, move_name);
		stored_move++;
		current_button->setLocation(x_view, y_view);

		if (i % 2 == 0) x_view += 2;
		else {
			x_view -= 2;
			y_view++;
		}

		character_guide->addButton(current_button);
	}
}

Character* CharacterButton::getCharacter() const { return stored_character; }
bool CharacterButton::isDisplayed() const { return show_display; }
void CharacterButton::setDisplayed(bool new_state) { show_display = new_state; }

void CharacterButton::callback() {
	show_display = !show_display;
	//LM.writeLog("Character Button");
}
