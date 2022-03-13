#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Object.h"

class Character : public df::Object {
private:
	int hp;	
	int turn_count;
	int current_moveset;
	std::string name;
	Character* target;

public:
	Character();
	virtual int eventHandler(const df::Event* p_e);
	virtual int draw();

	virtual int decideMove();
	virtual int moveSet(int choice);
	virtual int setMove(int choice);
	int getMove() const;

	int getHP();
	void setHP(int new_hp);
	void startTurnCount();

	void turnCountManage();
	int getTurnCount() const;

	std::string getName();
	void setName(std::string new_name);

	void setTarget(Character* the_enemy);
	Character* getTarget() const;

	void dealDamage(int damage, Character* recipient);
	void takeDamage(int damage);
	int drawHP(df::Color color, std::string name);
};

#endif __CHARACTER_H__
