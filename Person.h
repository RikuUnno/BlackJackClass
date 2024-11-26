#pragma once

class Person
{
public:
	//�R���X�g���N�^
	Person();

	//�f�X�g���N�^
	~Person();

public:
	//�J�[�h�̃h���[
	int DrawCard(int* deck, int* remainingNum);

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