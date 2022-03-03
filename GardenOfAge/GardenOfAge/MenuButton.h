#ifndef __MENU_BUTTON_H__
#define __MENU_BUTTON_H__

#include "Button.h"

const std::string MENUBUTTON = "MenuButton";

class MenuButton : public df::Button {
public:
	MenuButton();
	MenuButton(std::string m_string, df::Color c_highlight, df::Color c_default, int d_int = -1);
	
	int draw() override;
	void callback();

	void update(std::string m_string = "", int d_int = -1);
	void setLocation(float x_view, float y_view);
	void setButtonActive(bool status);
};

#endif __MENU_BUTTON_H__
