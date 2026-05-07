#ifndef ARCHER_H_
#define ARCHER_H_

#include <string>

#include "Player.h"

class Archer : public Player {
public:
	Archer(std::string n, int h, int m, int p, int d);

	//공격하는 함수 오버라이딩
	void attack(Monster* monster) override;
};

#endif