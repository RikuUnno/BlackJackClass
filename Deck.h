#pragma once

class Deck
{
private:
	// 変数の初期化
	void InitDeck();

	// デッキのシャッフル
	void ShuffleDeck();
public:
	//コンストラクタ
	Deck();
	//デストラクタ
	~Deck();

	//コピーコンストラクタと代入演算子のオーバーロードの追加
	//コピーコンストラクタ
	Deck(const Deck& other);

	//代入演算子のオーバーロード
	void operator=(const Deck& other);

public:
	//m__remainingNumゲッター・Deckゲッターの削除
	
	//カードのドローをDeckクラス内でできるように変更
	//カードドロー
	int PullDeck();

private:
	int* m_deck; // トランプの保管配列
	int m_remainingNum; //残りの枚数
	//int* p_remainingNumの削除
};