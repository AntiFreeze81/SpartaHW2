#include <iostream>
#include <string>

using namespace std;

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

	//1-5 printStatsu 함수 작성 후 호출
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
			break;
		case 3: stat[2] *= 2; break; //3-7 공격력 2배 
 		case 4: stat[3] *= 2; break; //3-8 방어력 2배
		case 5: printStatus(name, stat); break; //3-9 현재 능력치 출력
		}
	}
		
	return 0;
}