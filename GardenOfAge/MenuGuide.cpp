#include "MenuGuide.h"
#include "MenuSelect.h"
#include "Object.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "LogManager.h"

MenuGuide::MenuGuide()
{
	guide_counter = 0; 
	isToggled = false; 
}

int MenuGuide::addMenu(MenuSelect* new_menu)// adds a new menu to the management of a menu guide
{
	if (guide_counter < 5)
	{
		menu_lists[guide_counter] = new_menu;
		guide_counter++;
		LM.writeLog("Menu Guide | addMenu sucess"); 
		return 0;
	
	}
	LM.writeLog("Menu Guide | addMenu failed");

	return -1;
}

MenuSelect* MenuGuide::getMenu(int select_menu) const // return a specifc menu_select based on index
{
	return menu_lists[select_menu];
}

void MenuGuide::clearMenu()
{
	for (int guide_count = 0; guide_count < guide_counter; guide_count ++)
		WM.markForDelete(menu_lists[guide_count]); 
	guide_counter = 0; 
}

void MenuGuide::toggleMenu() //toggle the menu and all of its strings from menu select thus making visibvle and non visible when needed
{
	setActive(isToggled);
	
	df::ObjectList world_list = WM.objectsOfType(MENUSELECT); 
	df::ObjectListIterator* li = new df::ObjectListIterator(&world_list);

	int guide_count = 0; 
	while (!li->isDone() && guide_count != guide_counter)
	{
		df::Object* temp_object = li->currentObject(); 
		const MenuSelect* temp_menu = dynamic_cast< const MenuSelect*> (temp_object);
		
		if (temp_menu == menu_lists[guide_count])
			setActive(isToggled); 

		guide_count++;
	}
	isToggled = !isToggled; 
}

void MenuGuide::controlToggle(bool doActivate) //direct acess to toggle method just in case
{
	isToggled = doActivate; 
}

