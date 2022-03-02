#ifndef __END_TURN_BUTTON_H__
#define __END_TURN_BUTTON_H__

#include "WorldManager.h"
#include "MenuButton.h"

class EndTurnButton : public MenuButton {
public:
	EndTurnButton(); 
	void callback(); 
};
#endif __END_TURN_BUTTON_H__