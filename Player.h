#pragma once
#include "Inheritance.h"

class Player:
	Inheritance	
{
public:
	//�v���C���[�̃^�[���֐�
	void PlayerTurn(int* deck, int& remainingNum, int* playerHand, int& scoreTpm);
};