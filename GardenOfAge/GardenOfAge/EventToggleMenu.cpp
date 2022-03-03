#include "EventToggleMenu.h"

EventToggleMenu::EventToggleMenu(MenuGuide* new_guide) {
	menu_guide = new_guide; 
}

MenuGuide* EventToggleMenu::getMenuGuide() const { return menu_guide; }

bool EventToggleMenu::isEvent(MenuGuide* same_guide) {
	return menu_guide == same_guide; 
}
