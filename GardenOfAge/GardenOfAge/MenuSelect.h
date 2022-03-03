#ifndef __MENU_SELECT_H__
#define __MENU_SELECT_H__

#include "Object.h"
#include "Event.h"
#include "ViewObject.h"
#include "Color.h"

const std::string MENUSELECT = "MenuSelect";

class MenuSelect : public df::ViewObject {
private:
	std::string menu_message;

public:
	MenuSelect();
	MenuSelect(std::string m_string, df::Color color = df::WHITE, int d_int = -1);
	void update(std::string m_update = "", int d_update = -1);

	int draw() override;
	void setLocation(float x_view, float y_view);
	void setSelectActive(bool status);
};

#endif __MENU_SELECT_H__
