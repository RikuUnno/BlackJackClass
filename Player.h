#pragma once
#include "Person.h"
#include "Deck.h"

class Player:
	public Person
{
public:
	//�v���C���[�̃^�[���֐�
	void PlayerTurn(int* Deck, int* remainingNum);

	//�X�R�A�Q�b�^�[
	int ScoreGetter() const;

};