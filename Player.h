#pragma once
#include "Person.h"
#include "Deck.h"

class Player:
	public Person
{
public:
	//プレイヤーのターン関数
	void PlayerTurn(int* Deck, int* remainingNum);

	//スコアゲッター
	int ScoreGetter() const;

};