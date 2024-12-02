#include "Deck.h"
#include <iostream>
using namespace std;

const int TOTAL_CARDS = 52;

//�R���X�g���N�^
Deck::Deck()
{
	m_remainingNum = TOTAL_CARDS;

	m_deck = new(nothrow) int[TOTAL_CARDS];

	if (m_deck != nullptr)
	{
		InitDeck();

		ShuffleDeck();
	}
}

//�f�X�g���N�^
Deck::~Deck()
{
	if (m_deck != nullptr)
	{
		delete[] m_deck;
		m_deck = nullptr;
	}
}

//�R�s�[�R���X�g���N�^�Ƒ�����Z�q�̃I�[�o�[���[�h�̒ǉ�
//�R�s�[�R���X�g���N�^
Deck::Deck(const Deck& other)
{
	m_remainingNum = other.m_remainingNum;

	m_deck = new(nothrow) int[TOTAL_CARDS];

	if (m_deck != nullptr)
	{
		copy(other.m_deck, other.m_deck + TOTAL_CARDS, m_deck);
	}
}

//������Z�q�̃I�[�o�[���[�h
void Deck::operator=(const Deck& other)
{
	m_remainingNum = other.m_remainingNum;

	delete[] m_deck;
	m_deck = new(nothrow) int[TOTAL_CARDS];
	if (m_deck != nullptr)
	{
		copy(other.m_deck, other.m_deck + TOTAL_CARDS, m_deck);
	}
}

//�J�[�h�̃h���[
int Deck::PullDeck()
{
	int card = 0;

	// �J�[�h�̃G���[�`�F�b�N
	if (m_remainingNum <= 0)
	{
		cout << "�J�[�h������܂��� " << endl;
		return -1;
	}

	card = m_deck[m_remainingNum - 1]; //�c��̖����̍Ō�̃J�[�h������
	m_remainingNum--; //�J�[�h���ꖇ����
	return card;
}

// �ϐ��̏�����
void Deck::InitDeck()
{
	for (int i = 0; i < TOTAL_CARDS; i++)
	{
		m_deck[i] = i;
	}
}

//�V���b�t�����\�b�h�̃A���S���Y���ύX
// �f�b�L�̃V���b�t��
void Deck::ShuffleDeck()
{
	int randomIndex = 0;

	for (int i = TOTAL_CARDS - 1; i > 0; i--) {
		randomIndex = rand() % i;
		swap(m_deck[i], m_deck[randomIndex]);
	}
}