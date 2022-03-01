#ifndef __SISTER_H__
#define __SISTER_H__

#include "Character.h"

class Sister : public Character {
public:
	Sister();
	~Sister();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
};

#endif __SISTER_H__
