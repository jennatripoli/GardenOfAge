#include "WorldManager.h"
#include "EndTurnButton.h"
#include "Color.h"
#include "EventEndTurn.h"

EndTurnButton::EndTurnButton() {
	setType(MENUBUTTON);
	setBorder(false);
	setViewString("End Turn");
	setHighlightColor(df::WHITE);
	setDefaultColor(df::RED);
}

void EndTurnButton::callback() {
	EventEndTurn* endturn = new EventEndTurn(); 
	WM.onEvent(endturn);
}
