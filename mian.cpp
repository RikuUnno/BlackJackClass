#include <iostream>

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//カードの総枚数
const int TOTAL_CARDS = 52;

//バーストチェック
bool BurstCheck(int scoreTpm)
{
	if (scoreTpm > 21)
	{
		return true;
	}
	return false;
}

//勝敗
void Result(int playerScore, int dealerScore)
{
	if (playerScore == dealerScore)
	{
		cout << "引き分け" << endl;
	}
	else if (playerScore < dealerScore)
	{
		cout << "ディラーの勝ち" << endl;
	}
	else if (dealerScore < playerScore)
	{
		cout << "プレイヤーの勝ち" << endl;
	}
}

int main()
{
	//乱数の初期化
	srand((unsigned int)time(NULL));

	int deck[TOTAL_CARDS]; // トランプの保管配列
	int remainingNum = TOTAL_CARDS; //残りの枚数
	int playerHand[10], dealerHand[10]; //プレイヤーとディーラーのカードを保管する変数
	int playerScore = 0, dealerScore = 0; //プレイヤーとディーラーの点数を保管する変数

	//カードのシャッフルと各クラスの宣言
	Deck deckClass(TOTAL_CARDS, deck);
	Player player;
	Dealer dealer;


	//プレイヤーのターン
	player.PlayerTurn(deck, remainingNum, playerHand, playerScore);
	
	//scoreTpmがバーストしていれば
	if (BurstCheck(playerScore))
	{
		cout << "バーストしました。あなたの負けです。" << endl;
		return 0;
	}

	cout << endl;
	cout << "ディラーのターン" << endl;
	
	// ディラーのターン
	dealer.DealerTurn(deck, remainingNum, dealerHand, dealerScore);

	//scoreTpmがバーストしていれば
	if (BurstCheck(dealerScore))
	{
		cout << "バーストしました。ディラーの負けです。" << endl;
		return 0;
	}

	//勝敗
	Result(playerScore, dealerScore);

}
