#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>


#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
//#include "Slime.h"

using namespace std;

struct Item{
	string name;
	int price;
	//아이템 정보 출력용 상수 멤버 함수
	void PrintInfo() const {
		cout << name << " (" << price << "G)" << endl;
	}
};

struct PotionRecipe {
	string name;
	pair<string, int> ingredient1;
	pair<string, int> ingredient2;
};



//전역변수 아이템레시피
//포션 레시피 생성
vector<PotionRecipe> potionRecipes;

//1-5 printStatus 함수 작성 후 호출
void printStatus(string name, int stat[]) {
	cout << "======================================================" << endl;
	cout << "     " << name << "의 현재 능력치" << endl;
	cout << "======================================================" << endl;
	cout << "HP: " << stat[0] << "     " << "MP: " << stat[1] << endl;
	cout << "공격력: " << stat[2] << "    " << "방어력: " << stat[3] << endl;
	cout << "======================================================" << endl;
}

void ShowAllRecipes() {
	for (PotionRecipe rp : potionRecipes) {
		cout << "-> " << rp.name << " (" << rp.ingredient1.first << " x" << rp.ingredient1.second;
		if (rp.ingredient2.second != 0) {
			cout << ", " << rp.ingredient2.first << " x" << rp.ingredient2.second;
		}
		cout << ")" << endl;
	}
}

void SearchByName(string name) {
	for (PotionRecipe rp : potionRecipes) {
		if (rp.name == name) {
			cout << "-> " << rp.name << " (" << rp.ingredient1.first << " x" << rp.ingredient1.second;
			if (rp.ingredient2.second != 0) {
				cout << ", " << rp.ingredient2.first << " x" << rp.ingredient2.second;
			}
			cout << ")" << endl;
			cout << endl;
			return;
		}
	}
	cout << "찾을 수 없습니다." << endl;
	cout << endl;
}

void SearchByIngredient(string ingredient) {
	bool isSearched = false; //찾았는지 못찾았는지 판단하는 플래그

	for (PotionRecipe rp : potionRecipes) {
		if (rp.ingredient1.first == ingredient || rp.ingredient2.first == ingredient) {
			cout << "-> " << rp.name << " (" << rp.ingredient1.first << " x" << rp.ingredient1.second;
			if (rp.ingredient2.second != 0) {
				cout << ", " << rp.ingredient2.first << " x" << rp.ingredient2.second;
			}
			cout << ")" << endl;
			isSearched = true;
		}
	}
	if(!isSearched) cout << "찾을 수 없습니다." << endl;
	cout << endl;
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

	//포션 레시피 추가
	potionRecipes.push_back(PotionRecipe{ "HP포션", make_pair("허브", 1), make_pair("맑은물", 1) });
	potionRecipes.push_back(PotionRecipe{ "스태미나포션", make_pair("허브", 1), make_pair("베리", 1) });
	potionRecipes.push_back(PotionRecipe{ "쓸모없는 잡템", make_pair("끈적이는 액체", 2), make_pair("None", 0) });

	//게임 상태 확인 플래그
	bool isGameOver = false;

	//메인메뉴 생성 1.던전 2.인벤토리 0.종료
	do {
		cout << "=== 메인 메뉴 ===" << endl;
		cout << "1. 던전 입장" << endl;
		cout << "2. 인벤토리 확인" << endl;
		cout << "3. 포션 제작소" << endl;
		cout << "0. 게임 종료" << endl << endl;
		cout << "선택: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			//기본 몬스터(슬라임) 생성 기본값(HP 30, 공격력 20, 방어력 10)
			Monster* encounteredMonster = nullptr;
			//랜덤한 몬스터 출현을 위한 몬스터 랜덤
			srand(time(NULL));
			int randMonster = rand() % 5 + 1;

			switch (randMonster) {
			//Monster(std::string n, int h, int p, int d, std::string din, int dip)
			case 1: encounteredMonster = new Monster("더러운 슬라임", 30, 20, 10, "끈적이는 젤리", 120); break;
			case 2: encounteredMonster = new Monster("냄새나는 고블린", 40, 25, 20, "은화", 300); break;
			case 3: encounteredMonster = new Monster("이상한 다크엘프", 70, 40, 33, "맑은물", 150); break;
			case 4: encounteredMonster = new Monster("덩치 큰 오우거", 100, 55, 60, "허브", 170); break;
			case 5: encounteredMonster = new Monster("작은 요들", 40, 30, 10, "베리", 100); break;
			}

			//임시 몬스터 출현 출력
			cout << "야생의 " << encounteredMonster->getName() << "이 나타났다!" << endl;
			cout << "======================================================";

			//플레이어턴 판별을 위한 플래그 생성
			bool isPlayerTurn = true;

			//전투를 위한 반복문
			while (player->getHp() > 0 && encounteredMonster->getHp() > 0) {
				cout << endl;
				if (isPlayerTurn) {
					cout << "--- 플레이어 턴 ---" << endl;
					player->attack();
					cout << encounteredMonster->getName() << "에게 " << max(1, player->getPower() - encounteredMonster->getDefence()) << " 데미지!" << endl;
					cout << encounteredMonster->getName() << " HP: " << encounteredMonster->getHp() << " -> " << encounteredMonster->getHp() - max(1, player->getPower() - encounteredMonster->getDefence());
					encounteredMonster->setHp(encounteredMonster->getHp() - max(1, player->getPower() - encounteredMonster->getDefence()));
					isPlayerTurn = false;
				}
				else {
					cout << "--- " << encounteredMonster->getName() << " 턴 ---" << endl;
					encounteredMonster->attack(player);

					isPlayerTurn = true;
				}
			}

			if (player->getHp() > 0) {
				cout << " (사망)" << endl << endl;
				cout << "★ 전투 승리!" << endl;
				cout << " -> " << encounteredMonster->getName() << "의 " << encounteredMonster->getDropItemName() << " 획득!" << endl;

				Item droppedItem = {encounteredMonster->getDropItemName(), encounteredMonster->getDropItemPrice()};
				//droppedItem.name = encounteredMonster->getDropItemName();
				//droppedItem.price = encounteredMonster->getDropItemPrice();
				inventory.push_back(droppedItem);
			}
			else {
				cout << " (사망)" << endl << endl;
				cout << "전투 패배..." << endl;
				cout << encounteredMonster->getName() << "과(와)의 전투에서 패배하였습니다." << endl;
			}


			delete encounteredMonster;
		}
			break;
		case 2: //인벤토리 선택
		{
			int i = 1;
			for (Item item : inventory) {
				cout << i << ". ";
				item.PrintInfo();
				++i;
			}
			i = 1;
			break;
		}
		case 3: //포션 제작소
		{
			int choicePotionMenu; //포션 제작소를 위한 선택 변수
			bool isMakePotion = true;
			do {
				cout << "=== 포션 제작소 ===" << endl;
				cout << "1. 전체 레시피 보기" << endl;
				cout << "2. 포션 이름으로 검색" << endl;
				cout << "3. 재료로 검색" << endl;
				cout << "0. 돌아가기" << endl << endl;
				cout << "선택: ";

				cin >> choicePotionMenu;

				switch (choicePotionMenu) {
				case 1: ShowAllRecipes(); break; //모든 포션 레시피 출력
				case 2: //이름으로 포션레시피 검색
				{
					cout << "검색할 포션 이름: ";
					string tmpRecipe;

					//입력버퍼 비우기
					cin.ignore();

					getline(cin, tmpRecipe);
					SearchByName(tmpRecipe);
					break;
				}
				case 3: //재료로 포션레시피 검색
				{
					cout << "검색할 재료: ";
					string tmpIngredient;

					//입력버퍼 비우기
					cin.ignore();

					getline(cin, tmpIngredient);
					SearchByIngredient(tmpIngredient);
					break;
				}
				case 0:
				{
					isMakePotion = false;
					break;
				}
				}
			} while (isMakePotion);
			break;
		}
		case 0:
			isGameOver = true;
			cout << "게임을 즐겨주셔서 감사합니다!" << endl;
			cout << "made by AntiFreeze81" << endl;
			break;
		}
	} while (!isGameOver);


	delete player;

	return 0;
}