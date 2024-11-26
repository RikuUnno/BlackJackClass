#pragma once
#include "Deck.h"

class Person
{
public:
	//�R���X�g���N�^
	Person();

	//�f�X�g���N�^
	~Person();

	//�R�s�[�R���X�g���N�^�Ƒ�����Z�q�̃I�[�o�[���[�h�̒ǉ�
	//�R�s�[�R���X�g���N�^
	Person(const Person& other);

	//������Z�q�̃I�[�o�[���[�h
	void operator=(const Person& other);

public:
	//�f�b�L�N���X���Q�Ƃ��ăJ�[�h�̃h���[�ɕύX
	//�J�[�h�̃h���[
	int DrawCard(Deck& deck);

	//�o�[�X�g�`�F�b�N
	bool BurstCheck() const;

protected:
	//�\���֐�
	void ShowCard(int card) const;

	//�X�R�A�̌v�Z
	int CalculatingPoints(int* handArray, int& handSize);

protected:
	int* m_hand; //�v���C���[�ƃf�B�[���[�̃J�[�h��ۊǂ���ϐ�
	int m_score; //�v���C���[�ƃf�B�[���[�̓_����ۊǂ���ϐ�

};