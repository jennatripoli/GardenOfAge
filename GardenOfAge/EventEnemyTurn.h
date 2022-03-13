#ifndef __END_ENEMY_TURN_EVENT_H__
#define __END_ENEMY_TURN_EVENT_H__

#include "Event.h"

#define END_ENEMY_TURN_EVENT "enemyendturn"

class EventEnemyEndTurn : public df::Event {
 public:
	 EventEnemyEndTurn();
};

#endif __END_ENEMY_TURN_EVENT_H__
