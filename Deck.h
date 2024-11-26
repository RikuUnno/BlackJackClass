#pragma once

class Deck
{
private:
	// �ϐ��̏�����
	void InitDeck();

	// �f�b�L�̃V���b�t��
	void ShuffleDeck();
public:
	//�R���X�g���N�^
	Deck();
	//�f�X�g���N�^
	~Deck();

	//�R�s�[�R���X�g���N�^�Ƒ�����Z�q�̃I�[�o�[���[�h�̒ǉ�
	//�R�s�[�R���X�g���N�^
	Deck(const Deck& other);

	//������Z�q�̃I�[�o�[���[�h
	void operator=(const Deck& other);

public:
	//m__remainingNum�Q�b�^�[�EDeck�Q�b�^�[�̍폜
	
	//�J�[�h�̃h���[��Deck�N���X���łł���悤�ɕύX
	//�J�[�h�h���[
	int PullDeck();

private:
	int* m_deck; // �g�����v�̕ۊǔz��
	int m_remainingNum; //�c��̖���
	//int* p_remainingNum�̍폜
};