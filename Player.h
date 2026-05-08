#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

class Monster; //순환 참조 방지를 위한 Monster클래스 전방참조

class Player {
protected:
	std::string name;
	std::string job = "None";
	int hp;
	int mp;
	int power;
	int defence;
	int level = 1;
	int exp = 0;
	int maxExp = 100;
	int maxHp;
	int maxMp;


public:
	Player(std::string n, int h, int m, int p, int d);

	//getter
	std::string getName();
	std::string getJob();
	int getLevel();
	int getHp();
	int getMp();
	int getPower();
	int getDefence();
	int getExp();
	int getMaxExp();
	int getMaxHp();
	int getMaxMp();

	//setter
	void setName(std::string name);
	void setJob(std::string job);
	void setLevel(int level);
	void setHp(int hp);
	void setMp(int mp);
	void setPower(int power);
	void setDefence(int defence);
	void setExp(int exp);
	void setMaxExp(int maxExp);
	void setMaxHp(int maxHp);
	void setMaxMp(int maxMp);

	//공격하는 함수
	virtual void attack(Monster* monster) = 0; //4-6

	//플레이어 스테이터스 출력
	void printPlayerStatus();

	//가상 소멸자
	virtual ~Player() {} //4-7
};
#endif