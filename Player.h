#pragma once
#include "Person.h"
#include "Deck.h"

class Player:
	public Person
{
public:
	//�������f�b�L�N���X�̎Q�Ɠn���ɕύX
	//�v���C���[�̃^�[���֐�
	void PlayerTurn(Deck& deck);

	//�X�R�A�Q�b�^�[
	int ScoreGetter() const;

};