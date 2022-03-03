#ifndef __EVENT_END_TURN_H__
#define __EVENT_END_TURN_H__

#include "Event.h"

const std::string END_TURN_EVENT =  "endturn";

class EventEndTurn : public df::Event {
public:
	 EventEndTurn();
};

#endif __EVENT_END_TURN_H__
