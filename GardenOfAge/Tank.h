#ifndef __TANK_H__
#define __TANK_H__

#include "Character.h"

class Tank : public Character {
public:
	Tank();
	~Tank();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
};

#endif __TANK_H__
