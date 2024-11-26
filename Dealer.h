#pragma once
#include "Person.h"
#include "Deck.h"

class Dealer :
	public Person
{
public:
	//引数をデッキクラスの参照渡しに変更
	//ディラーのターン関数
	void DealerTurn(Deck& deck);

	//スコアゲッター
	int ScoreGetter() const;
};