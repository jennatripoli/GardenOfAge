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
#include "EventToggleMenu.h"

MenuGuide::MenuGuide() {
	registerInterest(df::STEP_EVENT); 
	registerInterest(MENU_TOGGLE_EVNT); 
	
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

void MenuGuide::clearMenu() {
	//for (int s_guide_count = 0; s_guide_count < s_guide_counter; s_guide_count++) WM.markForDelete(menu_s_lists[s_guide_count]);
	//s_guide_counter = 0;
}

// toggle the menu and all of its strings from MenuSelect (make visible and not visible when needed)
void MenuGuide::toggleMenu() {
	df::ObjectList s_world_list = WM.objectsOfType(MENUSELECT);
	df::ObjectListIterator* li_s = new df::ObjectListIterator(&s_world_list);

	for (int s_traverse_list = 0; s_traverse_list < s_guide_counter; s_traverse_list++) {
		li_s->first();
		while (!li_s->isDone()) {
			df::Object* temp_object = li_s->currentObject();
			MenuSelect* temp_menu = dynamic_cast<MenuSelect*> (temp_object);

			if (temp_menu == menu_s_lists[s_traverse_list])
				temp_menu->setActive(is_toggled);
			li_s->next();
		}

		df::ObjectList b_world_list = WM.objectsOfType(MENUBUTTON);
		df::ObjectListIterator* li_b = new df::ObjectListIterator(&b_world_list);

		for (int b_traverse_list = 0; b_traverse_list < b_guide_counter; b_traverse_list++) {
			WM.markForDelete(menu_b_lists[b_traverse_list]);

			/*
			li_b->first();
			while (!li_b->isDone()) {
				df::Object* temp_object = li_b->currentObject();
				MenuButton* temp_menu = dynamic_cast<MenuButton*> (temp_object);

				if (temp_menu == menu_b_lists[b_traverse_list])
					temp_menu->setActive(isToggled);
				li_b->next();
			}
			*/
		}
		is_toggled = !is_toggled;
	}
}

void MenuGuide::controlToggle(bool do_activate) { is_toggled = do_activate; }

int MenuGuide::eventHandler(const df::Event* p_e) {
	return 0;  // event ignored
}
