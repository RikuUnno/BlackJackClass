#include "Deck.h"
#include <iostream>
using namespace std;

const int TOTAL_CARDS = 52;

Deck::Deck()
{
	m_remainingNum = TOTAL_CARDS;

	p_remainingNum = &m_remainingNum;

	m_deck = new(nothrow) int[TOTAL_CARDS];

	if (m_deck != nullptr)
	{
		InitDeck(&m_deck[0]);

		ShuffleDeck(&m_deck[0]);
	}
}

int* Deck::GetDeck()
{
	if (m_deck != nullptr)
	{
		return m_deck;
	}
}

int* Deck::GetRemainingNum()
{
	
	return p_remainingNum;
}

// 変数の初期化
void Deck::InitDeck(int* deck)
{
	for (int i = 0; i < TOTAL_CARDS; i++)
	{
		deck[i] = i;
	}
}

// デッキのシャッフル
void Deck::ShuffleDeck(int* deck)
{
	int randomIndex = 0;

	for (int i = 0; i < TOTAL_CARDS; i++) {
		randomIndex = rand() % TOTAL_CARDS;
		swap(deck[i], deck[randomIndex]);
	}
}

