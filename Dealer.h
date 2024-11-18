#pragma once
#include "Inheritance.h"

class Dealer :
	Inheritance
{
public:
	//ディラーのターン関数
	void DealerTurn(int* deck, int& remainingNum, int* dealerHand, int& scoreTpm);
};