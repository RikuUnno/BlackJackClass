#pragma once
#include "Inheritance.h"
#include "Deck.h"

class Player:
	public Inheritance	
{

public:
	//�v���C���[�̃^�[���֐�
	void PlayerTurn(int* Deck, int* remainingNum);

	//�X�R�A�Q�b�^�[
	int ScoreGetter() const;

};