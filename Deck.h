#pragma once

class Deck
{
private:
	int m_totalCards;

	// 変数の初期化
	void InitDeck(int* deck);

	// デッキのシャッフル
	void ShuffleDeck(int* deck);
public:
	//コンストラクタ
	Deck(const int TOTAL_CARDS, int* deck);

};