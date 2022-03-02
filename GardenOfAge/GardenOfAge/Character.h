#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Object.h"

class Character : public df::Object {
private:
	int m_hp;
	std::string m_name;
	int currentMoveset;
	Character* target;

public:
	Character();
	virtual int eventHandler(const df::Event* p_e);
	virtual int draw();
	virtual int characterMoveSet(int choice);
	virtual int setCharacterMove(int choice);
	int getCharacterMove() const;

	int getHP();
	void setHP(int new_hp);
	std::string getName();
	void setName(std::string new_name);

	
	void setTartget(Character* the_enemy);

	Character* getTarget() const;

	void dealDamage(int damage, Character* recipient);
	void takeDamage(int damage);
	int drawHP(df::Color color, std::string name);
};
#endif __CHARACTER_H__
