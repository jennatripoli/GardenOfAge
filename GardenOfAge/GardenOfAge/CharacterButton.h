#ifndef __CHARACTER_BUTTON_H__
#define __CHARACTER_BUTTON_H__

#include "MenuGuide.h"
#include "MenuButton.h"
#include "Character.h"

class CharacterButton : public MenuButton {
private:
    bool showDisplay;
    std::string name;
    Character* stored_character;
    MenuGuide* character_guide;

public:
    CharacterButton();
    CharacterButton(Character* character, df::Color c_highlight, df::Color c_default);
    Character* getCharacter() const;

    bool isDisplayed() const;
    void setDisplayed(bool new_state);

    void callback();
};

#endif __CHARACTER_BUTTON_H__
