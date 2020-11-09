#pragma once
class POKER {
private:
	int iPoker[52];
	char iPokerStyle[4];
	char iPokerNum[13];
public:
	POKER();
	void showPoker() const; //≈„•‹µP
	void setShuffle(); //¨~µP 
	void depolyPoker(int pieceForEachPerson = 13);	//µoµP 

};