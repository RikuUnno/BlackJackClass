#pragma once
#include "Inheritance.h"

class Dealer :
	Inheritance
{
public:
	//�f�B���[�̃^�[���֐�
	void DealerTurn(int* deck, int& remainingNum, int* dealerHand, int& scoreTpm);
};