#include "WorldManager.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "LogManager.h"
#include "Event.h"
#include "EventStep.h"

#include "MenuGuide.h"
#include "MenuSelect.h"
#include "MenuButton.h"

MenuGuide::MenuGuide() {
	registerInterest(df::STEP_EVENT); 
	
	time_tracker = 0;
	is_toggled = false;
	s_guide_counter = 0;
	b_guide_counter = 0;
}

// add new menu to the management of MenuGuide
int MenuGuide::addMenu(MenuSelect* new_menu) {
	if (s_guide_counter < MAXCAPACITY) {
		menu_s_lists[s_guide_counter] = new_menu;
		s_guide_counter++;
		LM.writeLog("MenuGuide | addMenu() sucess.");
		return 0;
	}

	LM.writeLog("MenuGuide | addMenu() failure.");
	return -1;
}

int MenuGuide::addButton(MenuButton* new_button) {
	if (b_guide_counter < MAXCAPACITY) {
		menu_b_lists[s_guide_counter] = new_button;
		b_guide_counter++;
		LM.writeLog("MenuGuide | addButton() sucess.");
		return 0;
	}

	LM.writeLog("MenuGuide | addButton() failure.");
	return -1;
}

// return a specifc menu based on index
MenuSelect* MenuGuide::getMenu(int select_menu) const { return menu_s_lists[select_menu]; }

// return a specific button based on index
MenuButton* MenuGuide::getButton(int select_button) const { return menu_b_lists[select_button]; }

void MenuGuide::controlToggle(bool do_activate) { is_toggled = do_activate; }
