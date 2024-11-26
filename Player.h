#pragma once
#include "Person.h"
#include "Deck.h"

class Player:
	public Person
{
public:
	//引数をデッキクラスの参照渡しに変更
	//プレイヤーのターン関数
	void PlayerTurn(Deck& deck);

	//スコアゲッター
	int ScoreGetter() const;

};