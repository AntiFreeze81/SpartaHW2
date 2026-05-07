#include "Archer.h"

#include <iostream>
#include <algorithm>

#include "Monster.h"

Archer::Archer(std::string n, int h, int m, int p, int d) :
	Player(n, h, m, p, d) {
	power += 30;
	setJob("궁수");
}

void Archer::attack(Monster* monster) {
	std::cout << "화살 발사! -> " << monster->getName() << "에게 " << std::max(1, (power - monster->getDefence()) / 3) << " 데미지! (x3)" << std::endl;
	std::cout << monster->getName() << " HP: " << monster->getHp() << " -> " << monster->getHp() - std::max(1, (power - monster->getDefence())/3) * 3 << std::endl;
	monster->setHp(monster->getHp() - std::max(1, (power - monster->getDefence()) / 3) * 3);
}