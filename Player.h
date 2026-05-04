#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

class Player {
protected:
	std::string name;
	std::string job = "None";
	int level = 1;
	int hp;
	int mp;
	int power;
	int defence;

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

	//setter
	void setName(std::string name);
	void setJob(std::string job);
	void setLevel(int level);
	void setHp(int hp);
	void setMp(int mp);
	void setPower(int power);
	void setDefence(int defence);

	//공격하는 함수
	virtual void attack() = 0; //4-6

	//플레이어 스테이터스 출력
	void printPlayerStatus();

	//가상 소멸자
	virtual ~Player() {} //4-7
};
#endif