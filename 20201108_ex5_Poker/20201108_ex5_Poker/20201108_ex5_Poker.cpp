// 20201108_ex5_Poker.cpp: 主要專案檔。

#include <iostream>
#include "./POKER/POKER.h"
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(NULL)); //用到系統時間
	char cUserInput;
	POKER myPoker;
	myPoker.showPoker();

	myPoker.setShuffle();
	myPoker.showPoker();
	cout << "\n請輸入需要的發牌張數 : ";
	while (cin >> cUserInput) {//若Input為真 發牌
		if (cUserInput == 'n') { break; }
		myPoker.depolyPoker(cUserInput - '0'); //char - '0' 將字元轉回int
		cout << "\n請輸入需要的發牌張數 : ";
	}
	system("pause");
	return 0;
}
