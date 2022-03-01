//
// EventNuke.h
//

#include "Event.h"

const std::string END_TURN_EVENT =  "endturn";

class EventEndTurn : public df::Event {

 public:
	 EventEndTurn();
};
