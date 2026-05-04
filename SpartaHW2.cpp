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
		
	return 0;
}