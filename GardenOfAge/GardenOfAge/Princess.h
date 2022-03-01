#ifndef __PRINCESS_H__
#define __PRINCESS_H__

#include "Character.h"

class Princess : public Character {
public:
	Princess();
	~Princess();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
};

#endif __PRINCESS_H__
