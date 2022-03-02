#ifndef __START_TURN_EVENT_H__
#define __START_TURN_EVENT_H__

#include "Event.h"

const std::string START_TURN_EVENT =  "startturn";

class EventStartTurn : public df::Event {
 public:
	 EventStartTurn();
};

#endif __START_TURN_EVENT_H__
