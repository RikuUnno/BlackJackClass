#pragma once

class Deck
{
private:
	// �ϐ��̏�����
	void InitDeck(int* deck);

	// �f�b�L�̃V���b�t��
	void ShuffleDeck(int* deck);
public:
	//�R���X�g���N�^
	Deck();

public:
	int* GetDeck();
	int* GetRemainingNum();

private:
	int* m_deck; // �g�����v�̕ۊǔz��
	int m_remainingNum; //�c��̖���
	int* p_remainingNum; //m_remainingNum�̃|�C���^
};