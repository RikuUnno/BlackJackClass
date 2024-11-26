#pragma once

class Deck
{
private:
	// 変数の初期化
	void InitDeck(int* deck);

	// デッキのシャッフル
	void ShuffleDeck(int* deck);
public:
	//コンストラクタ
	Deck();

public:
	//Deckのゲッター
	int* GetDeck();
	//m__remainingNumのゲッター
	int* GetRemainingNum();

private:
	int* m_deck; // トランプの保管配列
	int m_remainingNum; //残りの枚数
	int* p_remainingNum; //m_remainingNumのポインタ
};