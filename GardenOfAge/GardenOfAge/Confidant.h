#ifndef __CONFIDANT_H__
#define __CONFIDANT_H__

#include "Character.h"

class Confidant : public Character {
public:
	Confidant();
	~Confidant();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int moveSet(int choice) override;
};

#endif __CONFIDANT_H__
