#pragma once
#include "Inheritance.h"

class Dealer :
	public Inheritance
{
public:
	//ディラーのターン関数
	void DealerTurn(int* deck, int* remainingNum);

	//スコアゲッター
	int ScoreGetter() const;
};