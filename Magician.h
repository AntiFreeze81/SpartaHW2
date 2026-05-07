#ifndef MAGICIAN_H_
#define MAGICIAN_H_

#include <string>

#include "Player.h"

class Magician : public Player {
public:
	Magician(std::string n, int h, int m, int p, int d);

	//공격하는 함수 오버라이딩
	void attack(Monster* monster) override;
};

#endif