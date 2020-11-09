#include "POKER.h"
#include <iostream>

using namespace std;

POKER::POKER() {
	for (int i = 0; i < 52; ++i) {
		iPoker[i] = i;
	}
	//���
	iPokerStyle[0] = 'S';
	iPokerStyle[1] = 'H';
	iPokerStyle[2] = 'D';
	iPokerStyle[3] = 'C';
	//�ƭ�
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
			iPokerNum[i] = '0' + i + 1; //�Ni�ন�r��
			//iPokerNum[i] = '1' + i;
			break;
		}
	}
}

void POKER::showPoker() const {
	for (int i = 0; i < 52; ++i) {
		cout << iPokerStyle[iPoker[i] / 13] <<
			iPokerNum[iPoker[i] % 13] << '\0'; //�Q��mod div �ƾǹB��hmapping
	}
	cout << endl;
}

void POKER::setShuffle() {
	for (int i = 51; i > 0; --i) {
		int idx = rand() % i; //�q�᭱�~ idx�T�w��@
		//�̫�@�i�P��51 �P�e��0~50���@�H��idx�洫
		int tmp = iPoker[i];
		iPoker[i] = iPoker[idx];
		iPoker[idx] = tmp;
	}
}

void POKER::depolyPoker(int pieceForEachPerson) {
	static int idx = 0; //�{�b�o��ĴX�i�P
	if (idx == 52) {
		cout << "�P�w���Ƶo��! �Ы�'n'�����o�P�{��..." << endl;
		return;
	}
	if (idx + pieceForEachPerson > 52) {
		cout << "\n�W�L�ѤU���J�P���ƶq!";
		return;
	}
	for (int i = 0; i < pieceForEachPerson; ++i) {
		cout << iPokerStyle[iPoker[idx] / 13] << iPokerNum[iPoker[idx] % 13] << '\0';
		idx++;
	}
}