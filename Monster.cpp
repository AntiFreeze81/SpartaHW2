#include "Monster.h"

Monster::Monster(std::string n, int h, int p, int d, std::string din, int dip) :
	name(n), hp(h), power(p), defence(d), dropItemName(din), dropItemPrice(dip) {}

//getter
std::string Monster::getName() {
	return name;
}

int Monster::getHp() {
	return hp;
}

int Monster::getPower() {
	return power;
}

int Monster::getDefence() {
	return defence;
}

std::string Monster::getDropItemName() {
	return dropItemName;
}

int Monster::getDropItemPrice() {
	return dropItemPrice;
}

//setter
void Monster::setName(std::string name) {
	this->name = name;
}

void Monster::setHp(int hp) {
	this->hp = hp;
}

void Monster::setPower(int power) {
	this->power = power;
}

void Monster::setDefence(int defence) {
	this->defence = defence;
}

void Monster::setDropItemName(std::string dropItemName) {
	this->dropItemName = dropItemName;
}

void Monster::setDropItemPrice(int dropItemPrice) {
	this->dropItemPrice = dropItemPrice;
}