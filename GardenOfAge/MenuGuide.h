#ifndef __MENU_GUIDE_H__
#define __MENU_GUIDE_H__

#include "ViewObject.h"
#include "Object.h"
#include "Event.h"
#include "MenuSelect.h"
#include "MenuButton.h"

const int MAXCAPACITY = 50;

class MenuGuide : df::Object {
private:
	MenuSelect* menu_s_lists[MAXCAPACITY];
	MenuButton* menu_b_lists[MAXCAPACITY];

	int s_guide_counter;
	int b_guide_counter; 
	int time_tracker; 
	bool is_toggled;

public:
	MenuGuide();
	int addMenu(MenuSelect* new_menu);
	int addButton(MenuButton* new_button);

	MenuSelect* getMenu(int select_menu) const;
	MenuButton* getButton(int select_button) const;

	void controlToggle(bool do_activate);
};

#endif __MENU_GUIDE_H__
