#ifndef GOBLIN_H_
#define GOBLIN_H_

#include "Monster.h"

#include <string>

class Goblin : Monster {
public:
	Goblin(std::string, int h, int p, int d, std::string din, int dip);

	void attack(Player* player) override;
};



#endif