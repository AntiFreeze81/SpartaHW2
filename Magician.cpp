#include "Magician.h"

#include <iostream>

Magician::Magician(std::string n, int h, int m, int p, int d) :
	Player(n, h, m, p, d) {
	mp += 30;
	setJob("마법사");
}

void Magician::attack() {
	std::cout << "썬더 볼트!" << std::endl;
}