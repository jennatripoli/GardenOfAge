#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Character.h"

class Knight : public Character {
public:
	Knight();
	~Knight();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
};

#endif __KNIGHT_H__
