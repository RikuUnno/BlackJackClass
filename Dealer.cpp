#include <iostream>

#include "Dealer.h"

using namespace std;

//ディラーのターン関数
void Dealer::DealerTurn(Deck& deck)
{
	int card = 0; // 引いたトランプの一時的な保管用変数
	int handSize = 0;

	// 最初の2枚を引く
	for (int i = 0; i < 2; i++)
	{
		//引数をデッキクラスの参照渡しに変更
		card = DrawCard(deck);
		if (card != -1)
		{
			m_hand[handSize++] = card;
			ShowCard(card);
		}
	}

	// ディラーのターン
	int score = CalculatingPoints(handSize);
	cout << "ディラーの現在のスコア: " << score << endl;

	while (score < 21)
	{
		if (score < 17) // ヒットの場合
		{
			card = DrawCard(deck);
			// 上記の関数の戻り値を使ってエラーチェック
			if (card != -1)
			{
				m_hand[handSize++] = card;
				ShowCard(card);
				score = CalculatingPoints(handSize);
				cout << "ディラーの現在のスコア: " << score << endl;
			}
		}
		else // スタンドの場合
		{
			break;
		}
	}
}

//スコアゲッターの削除