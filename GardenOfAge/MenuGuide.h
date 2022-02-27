#ifndef __MENU_GUIDE_H__
#define __MENU_GUIDE_H__
#include "MenuSelect.h"
#include "Object.h"
const int MAXCAPACITY = 5;

class MenuGuide : df::Object
{
private:
	MenuSelect* menu_lists[MAXCAPACITY];
	int guide_counter;
	bool isToggled;

public:
	MenuGuide();
	int addMenu(MenuSelect* new_menu);
	MenuSelect* getMenu(int select_menu)const;
	void clearMenu();
	void toggleMenu();
	void controlToggle(bool doActivate);
};

#endif __MENU_GUIDE_H__
