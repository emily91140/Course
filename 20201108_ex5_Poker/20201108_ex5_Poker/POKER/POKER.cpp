#include "POKER.h"
#include <iostream>

using namespace std;

POKER::POKER() {
	for (int i = 0; i < 52; ++i) {
		iPoker[i] = i;
	}
	//花色
	iPokerStyle[0] = 'S';
	iPokerStyle[1] = 'H';
	iPokerStyle[2] = 'D';
	iPokerStyle[3] = 'C';
	//數值
	for (int i = 0; i < 13; ++i) {
		switch (i) {
		case 0:
			iPokerNum[i] = 'A';
			break;
		case 9:
			iPokerNum[i] = 'T';
			break;
		case 10:
			iPokerNum[i] = 'J';
			break;
		case 11:
			iPokerNum[i] = 'Q';
			break;
		case 12:
			iPokerNum[i] = 'K';
			break;
		default:
			iPokerNum[i] = '0' + i + 1; //將i轉成字元
			//iPokerNum[i] = '1' + i;
			break;
		}
	}
}

void POKER::showPoker() const {
	for (int i = 0; i < 52; ++i) {
		cout << iPokerStyle[iPoker[i] / 13] <<
			iPokerNum[iPoker[i] % 13] << '\0'; //利用mod div 數學運算去mapping
	}
	cout << endl;
}

void POKER::setShuffle() {
	for (int i = 51; i > 0; --i) {
		int idx = rand() % i; //從後面洗 idx固定單一
		//最後一張牌第51 與前面0~50任一隨機idx交換
		int tmp = iPoker[i];
		iPoker[i] = iPoker[idx];
		iPoker[idx] = tmp;
	}
}

void POKER::depolyPoker(int pieceForEachPerson) {
	static int idx = 0; //現在發到第幾張牌
	if (idx == 52) {
		cout << "牌已全數發完! 請按'n'結束發牌程式..." << endl;
		return;
	}
	if (idx + pieceForEachPerson > 52) {
		cout << "\n超過剩下撲克牌的數量!";
		return;
	}
	for (int i = 0; i < pieceForEachPerson; ++i) {
		cout << iPokerStyle[iPoker[idx] / 13] << iPokerNum[iPoker[idx] % 13] << '\0';
		idx++;
	}
}