#pragma once
#ifndef __EVENT_TOGGLE_MENU_H__
#define __EVENT_TOGGLE_MENU_H__

#include "Event.h"
#include "MenuGuide.h"
const std::string MENU_TOGGLE_EVNT = "EventToggleMenu"; 
class EventToggleMenu
{
private:
	MenuGuide* p_m_guide; 

public:
	EventToggleMenu(MenuGuide* new_guide); 
	MenuGuide* getMenuGuide()const;
	bool isEvent(MenuGuide* same_guide);


};

#endif __EVENT_TOGGLE_MENU__H__ 