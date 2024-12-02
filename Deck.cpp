#include "Deck.h"
#include <iostream>
using namespace std;

const int TOTAL_CARDS = 52;

//コンストラクタ
Deck::Deck()
{
	m_remainingNum = TOTAL_CARDS;

	m_deck = new(nothrow) int[TOTAL_CARDS];

	if (m_deck != nullptr)
	{
		InitDeck();

		ShuffleDeck();
	}
}

//デストラクタ
Deck::~Deck()
{
	if (m_deck != nullptr)
	{
		delete[] m_deck;
		m_deck = nullptr;
	}
}

//コピーコンストラクタと代入演算子のオーバーロードの追加
//コピーコンストラクタ
Deck::Deck(const Deck& other)
{
	m_remainingNum = other.m_remainingNum;

	m_deck = new(nothrow) int[TOTAL_CARDS];

	if (m_deck != nullptr)
	{
		copy(other.m_deck, other.m_deck + TOTAL_CARDS, m_deck);
	}
}

//代入演算子のオーバーロード
void Deck::operator=(const Deck& other)
{
	m_remainingNum = other.m_remainingNum;

	delete[] m_deck;
	m_deck = new(nothrow) int[TOTAL_CARDS];
	if (m_deck != nullptr)
	{
		copy(other.m_deck, other.m_deck + TOTAL_CARDS, m_deck);
	}
}

//カードのドロー
int Deck::PullDeck()
{
	int card = 0;

	// カードのエラーチェック
	if (m_remainingNum <= 0)
	{
		cout << "カードがありません " << endl;
		return -1;
	}

	card = m_deck[m_remainingNum - 1]; //残りの枚数の最後のカードを引く
	m_remainingNum--; //カードを一枚引く
	return card;
}

// 変数の初期化
void Deck::InitDeck()
{
	for (int i = 0; i < TOTAL_CARDS; i++)
	{
		m_deck[i] = i;
	}
}

//シャッフルメソッドのアルゴリズム変更
// デッキのシャッフル
void Deck::ShuffleDeck()
{
	int randomIndex = 0;

	for (int i = TOTAL_CARDS - 1; i > 0; i--) {
		randomIndex = rand() % i;
		swap(m_deck[i], m_deck[randomIndex]);
	}
}