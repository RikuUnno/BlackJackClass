#pragma once

class Inheritance
{
public:
	//コンストラクタ
	Inheritance();

	//カードのドロー
	int DrawCard(int* deck, int& remainingNum);

	//表示関数
	void ShowCard(int card);

	//スコアの計算
	int CalculatingPoints(int* handArray, int& handSize);
protected:

};