#pragma once
#include "Person.h"
#include "Deck.h"

class Dealer :
	public Person
{
public:
	//�������f�b�L�N���X�̎Q�Ɠn���ɕύX
	//�f�B���[�̃^�[���֐�
	void DealerTurn(Deck& deck);

	//�X�R�A�Q�b�^�[
	int ScoreGetter() const;
};