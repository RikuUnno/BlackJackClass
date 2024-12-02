#include <iostream>
#include <conio.h>

#include "Player.h"

using namespace std;

//プレイヤーのターン関数
void Player::PlayerTurn(Deck& deck)
{
	char keyCh; // キーの入力用
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

	// プレイヤーのターン
	int score = CalculatingPoints(handSize);
	cout << "あなたの現在のスコア: " << score << endl;

	while (score < 21)
	{
		cout << "さらにカードを引きますか？ (h: ヒット / s: スタンド): ";
		keyCh = _getch(); // キー入力を受け取る
		cout << keyCh << endl;

		if (keyCh == 'h' || keyCh == 'H') // ヒットの場合
		{
			//引数をデッキクラスの参照渡しに変更
			card = DrawCard(deck);
			// 上記の関数の戻り値を使ってエラーチェック
			if (card != -1)
			{
				m_hand[handSize++] = card;
				ShowCard(card);
				score = CalculatingPoints(handSize);
				cout << "あなたの現在のスコア: " << score << endl;
			}
		}
		else if (keyCh == 's' || keyCh == 'S') // スタンドの場合
		{
			break;
		}
	}
}

//スコアゲッタ―の削除