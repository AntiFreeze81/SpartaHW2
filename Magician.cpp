#include "Magician.h"

#include <iostream>

Magician::Magician(std::string n, int h, int m, int p, int d) :
	Player::Player(n, h, m, p, d) {
	mp += 30;
	setJob("Magician");
}

void Magician::attack() {
	std::cout << "½ã´õ º¼Æ®!" << std::endl;
}