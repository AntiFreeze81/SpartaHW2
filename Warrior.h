#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <string>

#include "Player.h"

class Warrior : public Player {
public:
	Warrior(std::string n, int h, int m, int p, int d);
	
	//공격하는 함수 오버라이딩
	void attack() override;
};

#endif