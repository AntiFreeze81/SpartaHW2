#ifndef MONSTER_H_
#define MONSTER_H_

#include <string>

#include "Player.h"

class Monster {
protected:
	std::string name;
	int hp;
	int power;
	int defence;
	std::string dropItemName;
	int dropItemPrice;
	int expReward; //경험치를 위한 변수

public:
	Monster(std::string n, int h, int p, int d, std::string din, int dip, int exp);

	//getter
	std::string getName();
	int getHp();
	int getPower();
	int getDefence();
	std::string getDropItemName();
	int getDropItemPrice();
	int getExpReward();

	//setter
	void setName(std::string name);
	void setHp(int hp);
	void setPower(int power);
	void setDefence(int defence);
	void setDropItemName(std::string dropItemName);
	void setDropItemPrice(int dropItemPrice);
	void setExpReward(int expReward);

	void attack(Player* player);
};


#endif