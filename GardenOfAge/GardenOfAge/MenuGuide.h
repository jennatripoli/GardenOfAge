#ifndef __MENU_GUIDE_H__
#define __MENU_GUIDE_H__

#include "MenuSelect.h"
#include "MenuButton.h"
#include "ViewObject.h"
#include "Object.h"
#include "Event.h"

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

	void clearMenu();
	void toggleMenu();
	void controlToggle(bool do_activate);
	int eventHandler(const df::Event* p_e); 
};

#endif __MENU_GUIDE_H__
