#include "Magician.h"

#include <iostream>
#include <algorithm>

#include "Monster.h"

Magician::Magician(std::string n, int h, int m, int p, int d) :
	Player(n, h, m, p, d) {
	mp += 30;
	setJob("마법사");
}

void Magician::attack(Monster* monster) {
	std::cout << "썬더 볼트!! -> " << monster->getName() << "에게 " << std::max(1, power - monster->getDefence()) << " 데미지!" << std::endl;
	std::cout << monster->getName() << " HP: " << monster->getHp() << " -> " << monster->getHp() - std::max(1, power - monster->getDefence()) << std::endl;
	monster->setHp(monster->getHp() - std::max(1, power - monster->getDefence()));
}