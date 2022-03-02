#include "MenuButton.h"
#include "Object.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Color.h"

MenuButton::MenuButton() {
	setType("MenuButton");
	setBorder(false);
	setViewString("");
	setHighlightColor(df::WHITE);
	setDefaultColor(df::WHITE);
}

MenuButton::MenuButton(std::string m_string, df::Color c_highlight, df::Color c_default, int d_int) {
	if (d_int < -1) m_string = std::to_string(d_int) + " " + m_string;

	setType(MENUBUTTON);
	setBorder(false);
	setViewString(m_string);
	setHighlightColor(c_highlight);
	setDefaultColor(c_default);
}

int MenuButton::draw() {
	if (DM.drawString(getPosition(), getViewString(), df::CENTER_JUSTIFIED, getColor()) == -1) {
		LM.writeLog("MenuButton | draw() failure.");
		return -1;
	}

	return 0;
}

void MenuButton::update(std::string m_string, int d_int) {
	if (d_int < -1) m_string = std::to_string(d_int) + " " + m_string;
	setViewString(m_string);
}

void MenuButton::setLocation(float x_view, float y_view) {
	df::Vector new_pos = df::Vector();
	new_pos.setXY(WM.getView().getHorizontal() * (x_view / 10), WM.getView().getVertical() * (y_view / 10));
	setPosition(new_pos);
	LM.writeLog("MenuButton | setLocation() x = %.1f, y = %.1f.", getPosition().getX(), getPosition().getY());
}

// going to be redefined based on each button's specific use (ex: quit, magic spell, toggle)
void MenuButton::callback() {
	LM.writeLog("Button Clicked");
}

void MenuButton::setButtonActive(bool status)
{
	setActive(status);
}