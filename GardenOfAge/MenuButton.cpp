#include "MenuButton.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Color.h"



MenuButton::MenuButton(std::string m_string, df::Color c_highlight, df::Color c_default, int d_int)
{
	if (d_int < -1) m_string = std::to_string(d_int) + " " + m_string;

	setType(MENUBUTTON);
	setBorder(false);
	setViewString(m_string);
	setHighlightColor(c_highlight);
	setDefaultColor(c_default);
}

int MenuButton::draw() //modfy like menu select
{

	if (DM.drawString(getPosition(), getViewString(), df::CENTER_JUSTIFIED, getColor()) == -1) {
		LM.writeLog("MenuButton | draw() failure.");
		return -1;
	}
	else return 0;
}

void MenuButton::update(std::string m_string, int d_int)
{
	if (d_int < -1) m_string = std::to_string(d_int) + " " + m_string;
	setViewString(m_string);
}

void MenuButton::setLocation(float x_view, float y_view) //modified to draw 0 by 10 area like menu_ select
{
	df::Vector new_pos = df::Vector();
	// LM.writeLog("MenuSelect | setLocation() window width = %.1f, window height = %.1f.", WM.getView().getHorizontal(), WM.getView().getVertical());

	new_pos.setXY(WM.getView().getHorizontal() * (x_view / 10), WM.getView().getVertical() * (y_view / 10));
	setPosition(new_pos);
	LM.writeLog("MenuButton | setLocation() x = %.1f, y = %.1f.", getPosition().getX(), getPosition().getY());
}

void MenuButton::callback()
// going to be redefined based on each button specific use i,e quit, magic spell, or toggle 
// or hav certain functions passed as arguements
{
	LM.writeLog("Button Clicked");
}
