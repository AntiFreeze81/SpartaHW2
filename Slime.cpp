#include "Slime.h"

#include <iostream>
#include <algorithm>

Slime::Slime(std::string n, int h, int p, int d, std::string din, int dip) :
	Monster(n, h, p, d, din, dip){}

/*
void Slime::attack(Player* player) {
	std::cout << name << "의 공격!" << std::endl;
	std::cout << player->getName() << "에게 " << std::max(1, power - player->getDefence()) << "의 데미지!" << std::endl;
	std::cout << player->getName() << " HP: " << player->getHp() << " -> " << player->getHp() - std::max(1, power - player->getDefence());
	player->setHp(player->getHp() - std::max(1, power - player->getDefence()));
}
*/