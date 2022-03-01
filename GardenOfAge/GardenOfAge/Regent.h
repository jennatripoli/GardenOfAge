#ifndef __REGENT_H__
#define __REGENT_H__

#include "Character.h"

class Regent : public Character {
public:
	Regent();
	~Regent();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int moveSet(int choice) override;
};

#endif __REGENT_H__
