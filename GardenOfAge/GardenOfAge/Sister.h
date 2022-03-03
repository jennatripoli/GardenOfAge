#ifndef __SISTER_H__
#define __SISTER_H__

#include "Character.h"

class Sister : public Character {
private:
	bool power_track;
public:
	Sister();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
	int decideMove() override;

	//moves

	void gatheringMagic();	
	void Taunt();
	void eleusiveStrike(); 
	
};

#endif __SISTER_H__
