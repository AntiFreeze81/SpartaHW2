#ifndef THIEF_H_
#define THIEF_H_

#include <string>

#include "Player.h"

class Thief : public Player {
public:
	Thief(std::string n, int h, int m, int p, int d);

	//공격하는 함수 오버라이딩
	void attack() override;
};

#endif