#pragma once
#include "Person.h"

class Dealer :
	public Person
{
public:
	//ディラーのターン関数
	void DealerTurn(int* deck, int* remainingNum);

	//スコアゲッター
	int ScoreGetter() const;
};