#include "Person.h"
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

//コンストラクタ
Person::Person()
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

//デストラクタ
Person::~Person()
{
	if (m_hand != nullptr) {
		delete[] m_hand;
		m_hand = nullptr;
	}
}

//コピーコンストラクタと代入演算子のオーバーロードの追加
//コピーコンストラクタ
Person::Person(const Person& other)
{
	m_score = other.m_score;
	m_hand = new(nothrow) int[10];
	if (m_hand != nullptr)
	{
		copy(other.m_hand, other.m_hand + 10, m_hand);
	}
}

//代入演算子のオーバーロード
void Person::operator=(const Person& other)
{
	m_score = other.m_score;

	delete[] m_hand;
	m_hand = new(nothrow) int[10];
	if (m_hand != nullptr)
	{
		copy(other.m_hand, other.m_hand + 10, m_hand);
	}
}

//デッキクラスを参照してカードのドローに変更
//カードのドロー
int Person::DrawCard(Deck& deck)
{
	return deck.PullDeck();
}

//表示関数
void Person::ShowCard(int card) const
{
	int suit, rank;

	suit = card / 13;  // スートを計算
	rank = card % 13;  // ランクを計算
	cout << SUIT[suit] << " の " << RANKP_NUM[rank] << endl;
}

//スコアの計算
int Person::CalculatingPoints(int* handArray, int& handSize)
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
bool Person::BurstCheck() const
{
	if (m_score > 21)
	{
		return true;
	}
	return false;
}
