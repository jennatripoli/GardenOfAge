#include "MenuSelect.h"
#include "ViewObject.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include <iostream>

// easily write and display information the game will communicate to the player (ex: health)
MenuSelect::MenuSelect(std::string m_string, df::Color color, int d_int) {
	if (d_int > -1) m_string = std::to_string(d_int) + " " + m_string;

	df::ViewObject::setViewString(m_string);
	setColor(color);
	setBorder(false);
	setLocation(0, 0);
}

// update the string being displayed
void MenuSelect::update(std::string m_update, int d_update) {
	if (m_update.empty()) m_update = menu_message;
	if (d_update >-1) m_update = std::to_string(d_update) + " " + m_update;
	setViewString(m_update);
}

// draw the menu string on screen (return 0 if no issues, else return -1)
int MenuSelect::draw() {	
	if (DM.drawString(getPosition(), getViewString(), df::CENTER_JUSTIFIED, getColor()) == -1) {
		LM.writeLog("MenuSelect | draw() failure.");
		return -1;
	} else return 0;
}

// horizontal and vertical axes are divided into 10 sections each, so parameters should be (0, 10)
void MenuSelect::setLocation(float x_view, float y_view) {
	df::Vector new_pos = df::Vector();
	// LM.writeLog("MenuSelect | setLocation() window width = %.1f, window height = %.1f.", WM.getView().getHorizontal(), WM.getView().getVertical());

	new_pos.setXY(WM.getView().getHorizontal() * (x_view / 10), WM.getView().getVertical() * (y_view / 10));
	setPosition(new_pos);
	LM.writeLog("MenuSelect | setLocation() x = %.1f, y = %.1f.", getPosition().getX(), getPosition().getY());
}
