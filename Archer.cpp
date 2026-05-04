#include "Archer.h"

#include <iostream>

Archer::Archer(std::string n, int h, int m, int p, int d) :
	Player::Player(n, h, m, p, d) {
	power += 30;
	setJob("궁수");
}

void Archer::attack() {
	std::cout << "화살 발사!" << std::endl;
}