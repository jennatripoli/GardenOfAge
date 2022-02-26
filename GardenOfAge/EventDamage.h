#include "Event.h"

#define DAMAGE_EVENT "damage"

class EventDamage : public df::Event {
private:
	int m_amount;
	EventDamage();
public:
	EventDamage(int amount);
	int getAmount();
};