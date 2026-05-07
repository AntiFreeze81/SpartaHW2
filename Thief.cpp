#include "Thief.h"

#include <iostream>

#include "Monster.h"

Thief::Thief(std::string n, int h, int m, int p, int d) :
	Player(n, h, m, p, d) {
	power += 30;
	setJob("도적");
}

void Thief::attack(Monster* monster) {
	std::cout << "펜타 슬래시! -> " << monster->getName() << "에게 " << std::max(1, (power - monster->getDefence()) / 5) << " 데미지! (x5)" << std::endl;
	std::cout << monster->getName() << " HP: " << monster->getHp() << " -> " << monster->getHp() - std::max(1, (power - monster->getDefence()) / 5) * 5 << std::endl;
	monster->setHp(monster->getHp() - std::max(1, (power - monster->getDefence()) / 5) * 5);
}