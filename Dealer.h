#pragma once
#include "Inheritance.h"

class Dealer :
	public Inheritance
{
public:
	//�f�B���[�̃^�[���֐�
	void DealerTurn(int* deck, int* remainingNum);

	//�X�R�A�Q�b�^�[
	int ScoreGetter() const;
};