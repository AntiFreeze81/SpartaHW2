#include "Thief.h"

#include <iostream>

Thief::Thief(std::string n, int h, int m, int p, int d) :
	Player(n, h, m, p, d) {
	power += 30;
	setJob("도적");
}

void Thief::attack() {
	std::cout << "더블 슬래시!" << std::endl;
}