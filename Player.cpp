#include "Player.h"

#include <iostream>

Player::Player(std::string n, int h, int m, int p, int d) : name(n), hp(h), mp(m), power(p), defence(d) {
	maxHp = hp;
	maxMp = mp;
}

std::string Player::getName() {
	return name;
}
std::string Player::getJob() {
	return job;
}
int Player::getLevel() {
	return level;
}
int Player::getHp() {
	return hp;
}
int Player::getMp() {
	return mp;
}
int Player::getPower() {
	return power;
}
int Player::getDefence() {
	return defence;
}
int Player::getExp() {
	return exp;
}
int Player::getMaxExp() {
	return maxExp;
}
int Player::getMaxHp() {
	return maxHp;
}
int Player::getMaxMp() {
	return maxMp;
}

void Player::setName(std::string name) {
	this->name = name;
}
void Player::setJob(std::string job) {
	this->job = job;
}
void Player::setLevel(int level) {
	this->level = level;
}
void Player::setHp(int hp) {
	this->hp = hp;
}
void Player::setMp(int mp) {
	this->mp = mp;
}
void Player::setPower(int power) {
	this->power = power;
}
void Player::setDefence(int defence) {
	this->defence = defence;
}
void Player::setExp(int exp) {
	this->exp = exp;
}
void Player::setMaxExp(int maxExp) {
	this->maxExp = maxExp;
}
void Player::setMaxHp(int maxHp) {
	this->maxHp = maxHp;
}
void Player::setMaxMp(int maxMp) {
	this->maxMp = maxMp;
}



void Player::printPlayerStatus() {
	std::cout << "닉네임: " << name << " | 직업: " << job << " | Lv." << level << " | 경험치: " << exp << std::endl;
	std::cout << "HP: " << hp << " | MP: " << mp << " | 공격력: " << power << " | 방어력: " << defence << std::endl;
}