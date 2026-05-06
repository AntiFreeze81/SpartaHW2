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

public:
	Monster(std::string n, int h, int p, int d, std::string din, int dip);

	//getter
	std::string getName();
	int getHp();
	int getPower();
	int getDefence();
	std::string getDropItemName();
	int getDropItemPrice();

	//setter
	void setName(std::string name);
	void setHp(int hp);
	void setPower(int power);
	void setDefence(int defence);
	void setDropItemName(std::string dropItemName);
	void setDropItemPrice(int dropItemPrice);


	void attack(Player* player);

	//가상 소멸자 (자식 클래스 상속 제외)
	//virtual ~Monster() {}
};


#endif