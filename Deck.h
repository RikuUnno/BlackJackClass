#pragma once

class Deck
{
private:
	int m_totalCards;

	// �ϐ��̏�����
	void InitDeck(int* deck);

	// �f�b�L�̃V���b�t��
	void ShuffleDeck(int* deck);
public:
	//�R���X�g���N�^
	Deck(const int TOTAL_CARDS, int* deck);

};