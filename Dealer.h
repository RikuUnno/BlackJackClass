#pragma once
#include "Person.h"

class Dealer :
	public Person
{
public:
	//�f�B���[�̃^�[���֐�
	void DealerTurn(int* deck, int* remainingNum);

	//�X�R�A�Q�b�^�[
	int ScoreGetter() const;
};