#ifndef __CHARACTER_BUTTON_H__
#define __CHARACTER_BUTTON_H__

#include "MenuGuide.h"
#include "MenuButton.h"
#include "Character.h"

class CharacterButton : public MenuButton {
private:
    bool show_display;
    std::string name;
    Character* stored_character;
    MenuGuide* character_guide;
    CharacterButton();

public:
    CharacterButton(Character* character, df::Color c_highlight, df::Color c_default);

    void callback();
    bool isDisplayed() const;
    void setDisplayed(bool new_state);
    Character* getCharacter() const;
};

#endif __CHARACTER_BUTTON_H__
