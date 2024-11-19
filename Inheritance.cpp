#include "Inheritance.h"
#include "Deck.h"
#include <iostream>

using namespace std;

//�g�����v�̃X�[�g
const char* SUIT[] = {
	"�X�y�[�h", "�n�[�g", "�_�C��", "�N���u"
};

//�g�����v�̐���
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


//�J�[�h�̃h���[
int Inheritance::DrawCard(int* deck, int* remainingNum)
{
	int card = 0;

	// �J�[�h�̃G���[�`�F�b�N
	if (*remainingNum <= 0)
	{
		cout << "�J�[�h������܂��� " << endl;
		return -1;
	}

	// 
	card = deck[*remainingNum - 1]; //�c��̖����̍Ō�̃J�[�h������
	*remainingNum -= sizeof(remainingNum); //�J�[�h���ꖇ����
	return card;
}

//�\���֐�
void Inheritance::ShowCard(int card) const
{
	int suit, rank;

	suit = card / 13;  // �X�[�g���v�Z
	rank = card % 13;  // �����N���v�Z
	cout << SUIT[suit] << " �� " << RANKP_NUM[rank] << endl;
}

//�X�R�A�̌v�Z
int Inheritance::CalculatingPoints(int* handArray, int& handSize)
{
	int totalScore = 0;
	int aceCount = 0;
	int card = 0;
	int rank = 0;

	// �e�J�[�h�̃X�R�A�����Z
	for (int i = 0; i < handSize; i++) {
		card = handArray[i];
		rank = card % 13;  // �����N���v�Z

		if (rank == 0) {  // A�̏ꍇ
			totalScore += 11;
			aceCount++;
		}
		else if (rank >= 10) {  // J, Q, K�̏ꍇ
			totalScore += 10;
		}
		else {
			totalScore += (rank + 1);  // �����̏ꍇ
		}
	}

	// �G�[�X�̒l�𒲐�
	while (totalScore > 21 && aceCount > 0) {
		totalScore -= 10;  // �G�[�X��1�ɕύX
		aceCount--;
	}

	return totalScore;
}

//�o�[�X�g�`�F�b�N
bool Inheritance::BurstCheck() const
{
	if (m_score > 21)
	{
		return true;
	}
	return false;
}
