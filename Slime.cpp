#include "Slime.h"

#include <iostream>

Slime::Slime(std::string n, int h, int p, int d, std::string din, int dip) :
	Monster(n, h, p, d, din, dip){}

void Slime::attack(Player* player) {
	std::cout << name << "의 공격!" << std::endl;
	std::cout << player->getName() << "에게 " << (((power - player->getDefence()) >= 0) ? power - player->getDefence() : 1) << "의 데미지!" << std::endl;
	std::cout << player->getName() << " HP: " << player->getHp() << " -> " << (player->getHp() + player->getDefence()) - power;
	player->setHp(player->getHp() + player->getDefence() - power);
}