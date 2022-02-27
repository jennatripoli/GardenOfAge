#include "EventToggleMenu.h"

EventToggleMenu::EventToggleMenu(MenuGuide* new_guide)
{
	p_m_guide = new_guide; 
}

MenuGuide* EventToggleMenu::getMenuGuide() const
{
	return p_m_guide;
}

bool EventToggleMenu::isEvent(MenuGuide* same_guide)
{
	return p_m_guide == same_guide; 
}