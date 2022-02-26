#include "EventDamage.h"

EventDamage::EventDamage(int amount) {
	setType(DAMAGE_EVENT);
	m_amount = amount;
}

int EventDamage::getAmount() { return m_amount; }
