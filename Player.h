#pragma once
#include "Inheritance.h"
#include "Deck.h"

class Player:
	public Inheritance	
{

public:
	//プレイヤーのターン関数
	void PlayerTurn(int* Deck, int* remainingNum);

	//スコアゲッター
	int ScoreGetter() const;

};