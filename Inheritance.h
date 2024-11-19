#pragma once

class Inheritance
{
public:
	//コンストラクタ
	Inheritance();

	//デストラクタ
	~Inheritance();

public:
	//カードのドロー
	int DrawCard(int* deck, int* remainingNum);

	//バーストチェック
	bool BurstCheck() const;

protected:
	//表示関数
	void ShowCard(int card) const;

	//スコアの計算
	int CalculatingPoints(int* handArray, int& handSize);

protected:
	int* m_hand; //プレイヤーとディーラーのカードを保管する変数
	int m_score; //プレイヤーとディーラーの点数を保管する変数

};