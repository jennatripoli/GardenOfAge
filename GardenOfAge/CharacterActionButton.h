#ifndef __CHARACTER_ACTION_BUTTON_H__
#define __CHARACTER_ACTION_BUTTON_H__

#include "Character.h"
#include "Color.h"
#include "Event.h"
#include "MenuButton.h"

class CharacterActionButton : public MenuButton {
private:
    CharacterActionButton();
    int action_value;
    Character* character;

public:
    CharacterActionButton(int action_worth, Character* ch, std::string m_string);
    void callback();
};

#endif __CHARACTER_ACTION_BUTTON_H__
