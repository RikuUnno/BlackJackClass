#include <iostream>。

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Person.h"

using namespace std;

//勝敗
void Result(Player* player, Dealer *dealer)
{
	if (player->ScoreGetter() == dealer->ScoreGetter())
	{
		cout << "引き分け" << endl;
	}
	else if (player->ScoreGetter() < dealer->ScoreGetter())
	{
		cout << "ディラーの勝ち" << endl;
	}
	else if (player->ScoreGetter() > dealer->ScoreGetter())
	{
		cout << "プレイヤーの勝ち" << endl;
	}
}

int main()
{
	//乱数の初期化
	srand((unsigned int)time(NULL));

	//カードのシャッフルと各クラスの宣言
	Deck deck;
	Player player;
	Dealer dealer;

	//プレイヤーのターン
	player.PlayerTurn(deck.GetDeck(), deck.GetRemainingNum());
	
	//バーストチェック
	if (player.BurstCheck())
	{
		cout << "バーストしました。あなたの負けです。" << endl;
		return 0;
	}

	cout << endl;
	cout << "ディラーのターン" << endl;
	
	// ディラーのターン
	dealer.DealerTurn(deck.GetDeck(), deck.GetRemainingNum());

	//バーストチェック
	if (dealer.BurstCheck())
	{
		cout << "バーストしました。ディラーの負けです。" << endl;
		return 0;
	}

	//勝敗
	Result(&player, &dealer);

}
