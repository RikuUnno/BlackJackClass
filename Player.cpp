#include <iostream>
#include <conio.h>

#include "Player.h"

using namespace std;

//プレイヤーのターン関数
void Player::PlayerTurn(int* deck, int& remainingNum, int* playerHand, int& scoreTpm)
{
	char keyCh; // キーの入力用
	int card = 0; // 引いたトランプの一時的な保管用変数
	int handSize = 0;

	// 最初の2枚を引く
	for (int i = 0; i < 2; i++)
	{
		card = DrawCard(deck, remainingNum);
		if (card != -1)
		{
			playerHand[handSize++] = card;
			ShowCard(card);
		}
	}

	// プレイヤーのターン
	int score = CalculatingPoints(playerHand, handSize);
	cout << "あなたの現在のスコア: " << score << endl;

	while (score < 21)
	{
		cout << "さらにカードを引きますか？ (h: ヒット / s: スタンド): ";
		keyCh = _getch(); // キー入力を受け取る
		cout << keyCh << endl;

		if (keyCh == 'h' || keyCh == 'H') // ヒットの場合
		{
			card = DrawCard(deck, remainingNum);
			// 上記の関数の戻り値を使ってエラーチェック
			if (card != -1)
			{
				playerHand[handSize++] = card;
				ShowCard(card);
				score = CalculatingPoints(playerHand, handSize);
				cout << "あなたの現在のスコア: " << score << endl;
			}
		}
		else if (keyCh == 's' || keyCh == 'S') // スタンドの場合
		{
			break;
		}
	}

	scoreTpm = score;
}