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
}

void CharacterActionButton::callback() {
	character->setMove(action_value);
}
