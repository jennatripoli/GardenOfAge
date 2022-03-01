#include "WorldManager.h"
#include "Color.h"
#include "Event.h"
#include "CharacterActionButton.h"
#include "Object.h"

CharacterActionButton::CharacterActionButton(int action_worth, Character* ch, std::string m_string) {
	setType(MENUBUTTON);
	setBorder(false);
	setViewString(m_string);
	setHighlightColor(df::CYAN);
	setDefaultColor(df::WHITE);

	character = ch;
	action_value = action_worth;
	//current = current_event;
}

int CharacterActionButton::getButtonAction() {
	return 0;
}

void CharacterActionButton::callback() {
	character->setCharacterMove(action_value);
}
