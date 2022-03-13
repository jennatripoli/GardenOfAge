#ifndef __PRINCESS_H__
#define __PRINCESS_H__

#include "Character.h"

class Princess : public Character {
private:
	bool iron_fast; 
	bool brave_hearty;
	bool kindered_spirit;
	bool rightful_heir;
	bool true_ruler;
	bool victor;
	
public:
	Princess();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int moveSet(int choice) override;
	void setVictory(bool state);

	bool getIronFast() const;
	bool getBraveHearty() const;
	bool getKinderedSprit() const; 
	bool getRightfulHeir() const;
	void setTrueRuler(bool state);

	void attackCaliburn();
	void attackGildedShield();
	void attackHonorless();
	void attackHolyLight();
};

#endif __PRINCESS_H__
