#include "Warrior.h"

#include <iostream>
#include <algorithm>

#include "Monster.h"

Warrior::Warrior(std::string n, int h, int m, int p, int d) :
	Player(n, h, m, p, d) {
	hp += 30;
	setJob("전사");
}

void Warrior::attack(Monster* monster) {
	std::cout << "파워 어택! -> " << monster->getName() << "에게 " << std::max(1, power - monster->getDefence()) << " 데미지!" << std::endl;
	std::cout << monster->getName() << " HP: " << monster->getHp() << " -> " << monster->getHp() - std::max(1, power - monster->getDefence()) << std::endl;
	monster->setHp(monster->getHp() - std::max(1, power - monster->getDefence()));
}