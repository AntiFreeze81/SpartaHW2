#include "Warrior.h"

#include <iostream>

Warrior::Warrior(std::string n, int h, int m, int p, int d) :
	Player::Player(n, h, m, p, d) {
	hp += 30;
	setJob("전사");
}

void Warrior::attack() {
	std::cout << "파워 어택!" << std::endl;
}