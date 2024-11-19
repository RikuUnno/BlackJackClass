#include <iostream>

#include "Dealer.h"

using namespace std;

//ディラーのターン関数
void Dealer::DealerTurn(int* deck, int* remainingNum)
{
	int card = 0; // 引いたトランプの一時的な保管用変数
	int handSize = 0;

	// 最初の2枚を引く
	for (int i = 0; i < 2; i++)
	{
		card = DrawCard(deck, remainingNum);
		if (card != -1)
		{
			m_hand[handSize++] = card;
			ShowCard(card);
		}
	}

	// ディラーのターン
	int score = CalculatingPoints(m_hand, handSize);
	cout << "ディラーの現在のスコア: " << score << endl;

	while (score < 21)
	{
		if (score < 17) // ヒットの場合
		{
			card = DrawCard(deck, remainingNum);
			// 上記の関数の戻り値を使ってエラーチェック
			if (card != -1)
			{
				m_hand[handSize++] = card;
				ShowCard(card);
				score = CalculatingPoints(m_hand, handSize);
				cout << "ディラーの現在のスコア: " << score << endl;
			}
		}
		else // スタンドの場合
		{
			break;
		}
	}

	m_score = score;
}

//スコアゲッター
int Dealer::ScoreGetter() const
{
	return m_score;
}