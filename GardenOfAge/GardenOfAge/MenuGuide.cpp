#include "MenuGuide.h"
#include "MenuSelect.h"
#include "MenuButton.h"
#include "Object.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "LogManager.h"
#include "Event.h"
#include "EventStep.h"
#include "EventToggleMenu.h"

MenuGuide::MenuGuide() {
	registerInterest(df::STEP_EVENT); 
	registerInterest(MENU_TOGGLE_EVNT); 
	
	timetracker = 0;
	isToggled = false;
	s_guide_counter = 0;
	b_guide_counter = 0;
}

// adds a new menu to the management of MenuGuide
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

// return a specifc menu_select based on index
MenuSelect* MenuGuide::getMenu(int select_menu) const {
	return menu_s_lists[select_menu];
}

MenuButton* MenuGuide::getButton(int select_button) const {
	return menu_b_lists[select_button];
}

void MenuGuide::clearMenu() {
	for (int s_guide_count = 0; s_guide_count < s_guide_counter; s_guide_count++) WM.markForDelete(menu_s_lists[s_guide_count]);
	s_guide_counter = 0;

	for (int b_guide_count = 0; b_guide_count < b_guide_counter; b_guide_count++) WM.markForDelete(menu_s_lists[b_guide_count]);
	b_guide_counter = 0;
}

// toggle the menu and all of its strings from MenuSelect (make visible and not visible when needed)
void MenuGuide::toggleMenu() {
	setActive(isToggled);

	df::ObjectList s_world_list = WM.objectsOfType(MENUSELECT);
	df::ObjectListIterator* li_s = new df::ObjectListIterator(&s_world_list);
	int guide_count = 0;

	li_s->first(); 
	while (!li_s->isDone() && guide_count != s_guide_counter) {
		df::Object* temp_object = li_s->currentObject();
		const MenuSelect* temp_menu = dynamic_cast<const MenuSelect*> (temp_object);

		if (temp_menu == menu_s_lists[guide_count]) setActive(isToggled);

		guide_count++;
		li_s->next();
	}

	guide_count = 0;
	df::ObjectList b_world_list = WM.objectsOfType(MENUBUTTON);
	df::ObjectListIterator* li_b = new df::ObjectListIterator(&b_world_list);

	while (!li_b->isDone() && guide_count != s_guide_counter) {
		df::Object* temp_object = li_b->currentObject();
		const MenuButton* temp_menu = dynamic_cast<const MenuButton*> (temp_object);

		if (temp_menu == menu_b_lists[guide_count]) setActive(isToggled);

		guide_count++;
		li_b->next();
	}
	isToggled = !isToggled;
}

void MenuGuide::controlToggle(bool doActivate) {
	isToggled = doActivate;
}

int MenuGuide::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		const df::EventStep* p_step_event = dynamic_cast<const df::EventStep*> (p_e);
		if (timetracker % 300 == 0) toggleMenu();
		if (timetracker > 1200) clearMenu(); 
		return 1;
	}

	return 0;  // event ignored
}
