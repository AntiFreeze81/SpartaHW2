#ifndef SLIME_H_
#define SLIME_H_

#include "Monster.h"

#include <string>

class Slime : public Monster {
public:
	Slime(std::string n, int h, int p, int d, std::string din, int dip);
	
	//void attack(Player* player) override;
};



#endif
