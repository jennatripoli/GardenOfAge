#ifndef __CHARACTER_ACTION_BUTTON_H__
#define __CHARACTER_ACTION_BUTTON_H__

#include "Character.h"
#include "Color.h"
#include "MenuButton.h"
#include "Event.h"

class CharacterActionButton : public MenuButton {
private:
    CharacterActionButton();
    int characterAction;
    //df::Event* current;
    Character* character;
    Character* target;
    int action_value;

public:
    CharacterActionButton(int action_worth, Character* ch, std::string m_string);
    int getButtonAction();
    void callback();
};

#endif __CHARACTER_ACTION_BUTTON_H__
