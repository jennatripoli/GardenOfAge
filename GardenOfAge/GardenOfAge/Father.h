#ifndef __FATHER_H__
#define __FATHER_H__

#include "Character.h"

class Father : public Character {
public:
	Father();
	~Father();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int moveSet(int choice) override;
};

#endif __FATHER_H__