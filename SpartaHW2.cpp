#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include "Slime.h"

using namespace std;

struct Item{
	string name;
	int price;
	//아이템 정보 출력용 상수 멤버 함수
	void PrintInfo() const {
		cout << name << " (" << price << "G)" << endl;
	}
};



/*
class Player { //4-1 Player클래스 생성
protected:
	string name;
	string job = "None";
	int level = 1;
	int hp;
	int mp;
	int power;
	int defence;

public:
	Player(string n, int h, int m, int p, int d) : name(n), hp(h), mp(m), power(p), defence(d) {} //4-2, 4-3
	
	//4-5 getter
	string getName() {
		return name;
	}
	string getJob() {
		return job;
	}
	int getLevel() {
		return level;
	}
	int getHp() {
		return hp;
	}
	int getMp() {
		return mp;
	}
	int getPower() {
		return power;
	}
	int getDefence() {
		return defence;
	}

	//4-5 setter
	void setName(string name) {
		this->name = name;
	}
	void setJob(string job) {
		this->job = job; 
	} 
	void setLevel(int level) {
		this->level = level;
	}
	void setHp(int hp) {
		this->hp = hp;
	}
	void setMp(int mp) {
		this->mp = mp;
	}
	void setPower(int power) {
		this->power = power;
	}
	void setDefence(int defence) {
		this->defence = defence;
	}

	virtual void attack() = 0; //4-6
	
	void printStatus() {
		cout << "======================================================" << endl;
		cout << "     " << name << "의 현재 능력치" << endl;
		cout << "======================================================" << endl;
		cout << "HP: " << hp << "     " << "MP: " << mp << endl;
		cout << "공격력: " << power << "    " << "방어력: " << defence << endl;
		cout << "======================================================" << endl;
	}

	virtual ~Player() {} //4-7
};

class Warrior : public Player {
public:
	Warrior(string n, int h, int m, int p, int d) : Player(n, h, m, p, d) {
		hp += 30;
		setJob("Warrior");
	}

	void attack() override {
		cout << "파워 어택!" << endl;
	}
};

class Magician : public Player {
public:
	Magician(string n, int h, int m, int p, int d) : Player(n, h, m, p, d) {
		mp += 30;
		setJob("Magician");
	}

	void attack() override {
		cout << "썬더 볼트!" << endl;
	}
};

class Thief : public Player {
public:
	Thief(string n, int h, int m, int p, int d) : Player(n, h, m, p, d) {
		p += 30;
		setJob("Thief");
	}

	void attack() override {
		cout << "더블 슬래시!" << endl;
	}
};

class Archer : public Player {
public:
	Archer(string n, int h, int m, int p, int d) : Player(n, h, m, p, d) {
		p += 30;
		setJob("Archer");
	}

	void attack() override {
		cout << "화살 발사!" << endl;
	}
};

*/

//1-5 printStatus 함수 작성 후 호출
void printStatus(string name, int stat[]) {
	cout << "======================================================" << endl;
	cout << "     " << name << "의 현재 능력치" << endl;
	cout << "======================================================" << endl;
	cout << "HP: " << stat[0] << "     " << "MP: " << stat[1] << endl;
	cout << "공격력: " << stat[2] << "    " << "방어력: " << stat[3] << endl;
	cout << "======================================================" << endl;
}


int main() {
	cout << "======================================================" << endl;
	cout << "    [던전 탈출 텍스트 RPG]" << endl;
	cout << "======================================================" << endl;

	//1-1 string 타입으로 이름 입력 받기
	string name;
	cout << "용사의 이름을 입력해주세요: ";
	getline(cin, name);
	cout << '\n';

	//1-2, 1-3 stat 배열선언
	const int SIZE = 4;
	int stat[SIZE] = { 0 }; //스탯 순서 HP, MP, 공격력, 방어력

	//1-3, 1-4 cin으로 스탯 2개씩 입력받기, 2-1, 2-2
	while (true) {
		cout << "HP와 MP를 입력해주세요: ";
		cin >> stat[0] >> stat[1];
		if (stat[0] > 50 && stat[1] > 50) {
			break;
		}
		else {
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
		}
	}

	//2-3, 2-4
	while(true){
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> stat[2] >> stat[3]; 
		if (stat[2] > 50 && stat[3] > 50) {
			break;
		}
		else {
			cout << "공격력이나 방어력이 너무 작습니다. 다시 입력해주세요." << endl;
		}
	}
	cout << '\n';

	printStatus(name, stat);

	//3-1
	int hpPotion = 5, mpPotion = 5;
	cout << "* HP포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;

	cout << "======================================================" << endl;

	//3-2
	bool isGameStart = false;

	//3-3
	int choice;
	while (!isGameStart) {
		cout << "< 캐릭터 강화 >" << endl;
		cout << "1. HP UP   2. MP UP   3. 공격력 2배" << endl;
		cout << "4. 방어력 2배   5. 현재 능력치    0. 게임시작" << endl;
		cout << "======================================================" << endl;
		cout << "번호를 선택해주세요: ";
		cin >> choice;

		switch (choice) {
		case 0: //3-10 게임 시작
			cout << "게임을 시작합니다!" << endl;
			isGameStart = true;
			break;
		case 1: //3-4 HP포션 사용 (20 회복) + 3-6
			if (hpPotion > 0) {
				--hpPotion;
				stat[0] += 20;
			}
			else {
				cout << "포션 부족" << endl;
			}
			break;
		case 2: //3-5 MP포션 사용 (20 회복) + 3-6
			if (mpPotion > 0) {
				--mpPotion;
				stat[1] += 20;
			}
			else {
				cout << "포션 부족" << endl;
			}
			break;
		case 3: stat[2] *= 2; break; //3-7 공격력 2배 
 		case 4: stat[3] *= 2; break; //3-8 방어력 2배
		case 5: printStatus(name, stat); break; //3-9 현재 능력치 출력
		}
	}

	cout << "======================================================" << endl;

	//player 생성
	Player* player = nullptr;
	
	//직업 입력 받기 
	cout << name << "님, 직업을 선택해주세요!" << endl;
	cout << "1. 전사  2. 마법사  3. 도적  4. 궁수" << endl;
	cout << "선택: ";
	cin >> choice; //선택값 저장 변수

	//입력 받은 값으로 직업 선택
	switch (choice) {
	case 1:	player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]); break;
	case 2:	player = new Magician(name, stat[0], stat[1], stat[2], stat[3]); break;
	case 3:	player = new Thief(name, stat[0], stat[1], stat[2], stat[3]); break;
	case 4:	player = new Archer(name, stat[0], stat[1], stat[2], stat[3]); break;
	}

	//전직한 직업명 출력
	cout << "======================================================" << endl;
	cout << player->getName() << "님이 " << player->getJob() << "(으)로 전직하셨습니다." << endl;
	cout << "======================================================" << endl;

	//인벤토리 생성
	vector<Item> inventory;

	//게임 상태 확인 플래그
	bool isGameOver = false;

	//메인메뉴 생성 1.던전 2.인벤토리 0.종료
	do {
		cout << "=== 메인 메뉴 ===" << endl;
		cout << "1. 던전 입장" << endl;
		cout << "2. 인벤토리 확인" << endl;
		cout << "0. 게임 종료" << endl << endl;
		cout << "선택: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			//기본 몬스터(슬라임) 생성 기본값(HP 30, 공격력 20, 방어력 10)
			Monster* slime = new Slime("더러운 슬라임", 3000, 51, 49, "끈적이는 젤리", 120);

			//임시 몬스터 출현 출력
			cout << "야생의 " << slime->getName() << "이 나타났다!" << endl;
			cout << "======================================================";

			//플레이어턴 판별을 위한 플래그 생성
			bool isPlayerTurn = true;

			//전투를 위한 반복문
			while (player->getHp() > 0 && slime->getHp() > 0) {
				cout << endl;
				if (isPlayerTurn) {
					cout << "--- 플레이어 턴 ---" << endl;
					player->attack();
					cout << slime->getName() << "에게 " << max(1, player->getPower() - slime->getDefence()) << " 데미지!" << endl;
					cout << slime->getName() << " HP: " << slime->getHp() << " -> " << slime->getHp() - max(1, player->getPower() - slime->getDefence());
					slime->setHp(slime->getHp() - max(1, player->getPower() - slime->getDefence()));
					isPlayerTurn = false;
				}
				else {
					cout << "--- " << slime->getName() << " 턴 ---" << endl;
					slime->attack(player);

					isPlayerTurn = true;
				}
			}

			if (player->getHp() > 0) {
				cout << " (사망)" << endl << endl;
				cout << "★ 전투 승리!" << endl;
				cout << " -> 슬라임의 끈적한 젤리 획득!" << endl;

				Item droppedItem;
				droppedItem.name = slime->getDropItemName();
				droppedItem.price = slime->getDropItemPrice();
				inventory.push_back(droppedItem);
			}
			else {
				cout << " (사망)" << endl << endl;
				cout << "전투 패배..." << endl;
				cout << slime->getName() << "과(와)의 전투에서 패배하였습니다." << endl;
			}


			delete slime;
		}
			break;
		case 2: //인벤토리 선택
		{
			int i = 1;
			for (Item item : inventory) {
				cout << i << ". ";
				item.PrintInfo();
			}
			break;
		}
		case 0:
			isGameOver = true;
		}
	} while (!isGameOver);


	delete player;

	return 0;
}