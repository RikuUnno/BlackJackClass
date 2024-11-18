#pragma once
#include "Inheritance.h"

class Player:
	Inheritance	
{
public:
	//プレイヤーのターン関数
	void PlayerTurn(int* deck, int& remainingNum, int* playerHand, int& scoreTpm);
};