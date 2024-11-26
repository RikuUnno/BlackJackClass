#pragma once
#include "Deck.h"

class Person
{
public:
	//コンストラクタ
	Person();

	//デストラクタ
	~Person();

	//コピーコンストラクタと代入演算子のオーバーロードの追加
	//コピーコンストラクタ
	Person(const Person& other);

	//代入演算子のオーバーロード
	void operator=(const Person& other);

public:
	//デッキクラスを参照してカードのドローに変更
	//カードのドロー
	int DrawCard(Deck& deck);

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