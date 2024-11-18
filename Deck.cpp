#include "Deck.h"
#include <iostream>
using namespace std;

Deck::Deck(const int TOTAL_CARDS, int* deck)
{
	m_totalCards = TOTAL_CARDS; 

	InitDeck(deck);

	ShuffleDeck(deck);
}

// �ϐ��̏�����
void Deck::InitDeck(int* deck)
{
	for (int i = 0; i < m_totalCards; i++)
	{
		deck[i] = i;
	}
}

// �f�b�L�̃V���b�t��
void Deck::ShuffleDeck(int* deck)
{
	int randomIndex = 0;

	for (int i = 0; i < m_totalCards; i++) {
		randomIndex = rand() % m_totalCards;
		swap(deck[i], deck[randomIndex]);
	}
}