#include "Inheritance.h"
#include "Deck.h"
#include <iostream>

using namespace std;

//トランプのスート
const char* SUIT[] = {
	"スペード", "ハート", "ダイヤ", "クラブ"
};

//トランプの数字
const char* RANKP_NUM[] = {
	"1", "2", "3", "4","5", "6", "7", "8", "9", "10", "11", "12", "13"
};

Inheritance::Inheritance()
{
	m_score = 10;
	m_hand = new(nothrow) int[10];
	if (m_hand != nullptr) {
		for (int i = 0; i < 10; i++)
		{
			m_hand[i] = 0;
		}
	}
}

Inheritance::~Inheritance()
{
	if (m_hand != nullptr) {
		delete[] m_hand;
		m_hand = nullptr;
	}
}


//カードのドロー
int Inheritance::DrawCard(int* deck, int* remainingNum)
{
	int card = 0;

	// カードのエラーチェック
	if (*remainingNum <= 0)
	{
		cout << "カードがありません " << endl;
		return -1;
	}

	// 
	card = deck[*remainingNum - 1]; //残りの枚数の最後のカードを引く
	*remainingNum -= sizeof(remainingNum); //カードを一枚引く
	return card;
}

//表示関数
void Inheritance::ShowCard(int card) const
{
	int suit, rank;

	suit = card / 13;  // スートを計算
	rank = card % 13;  // ランクを計算
	cout << SUIT[suit] << " の " << RANKP_NUM[rank] << endl;
}

//スコアの計算
int Inheritance::CalculatingPoints(int* handArray, int& handSize)
{
	int totalScore = 0;
	int aceCount = 0;
	int card = 0;
	int rank = 0;

	// 各カードのスコアを加算
	for (int i = 0; i < handSize; i++) {
		card = handArray[i];
		rank = card % 13;  // ランクを計算

		if (rank == 0) {  // Aの場合
			totalScore += 11;
			aceCount++;
		}
		else if (rank >= 10) {  // J, Q, Kの場合
			totalScore += 10;
		}
		else {
			totalScore += (rank + 1);  // 数字の場合
		}
	}

	// エースの値を調整
	while (totalScore > 21 && aceCount > 0) {
		totalScore -= 10;  // エースを1に変更
		aceCount--;
	}

	return totalScore;
}

//バーストチェック
bool Inheritance::BurstCheck() const
{
	if (m_score > 21)
	{
		return true;
	}
	return false;
}
