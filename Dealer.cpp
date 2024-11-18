#include <iostream>

#include "Dealer.h"

using namespace std;

//�f�B���[�̃^�[���֐�
void Dealer::DealerTurn(int* deck, int& remainingNum, int* dealerHand, int& scoreTpm)
{
	int card = 0; // �������g�����v�̈ꎞ�I�ȕۊǗp�ϐ�
	int handSize = 0;

	// �ŏ���2��������
	for (int i = 0; i < 2; i++)
	{
		card = DrawCard(deck, remainingNum);
		if (card != -1)
		{
			dealerHand[handSize++] = card;
			ShowCard(card);
		}
	}

	// �f�B���[�̃^�[��
	int score = CalculatingPoints(dealerHand, handSize);
	cout << "�f�B���[�̌��݂̃X�R�A: " << score << endl;

	while (score < 21)
	{
		if (score < 17) // �q�b�g�̏ꍇ
		{
			card = DrawCard(deck, remainingNum);
			// ��L�̊֐��̖߂�l���g���ăG���[�`�F�b�N
			if (card != -1)
			{
				dealerHand[handSize++] = card;
				ShowCard(card);
				score = CalculatingPoints(dealerHand, handSize);
				cout << "�f�B���[�̌��݂̃X�R�A: " << score << endl;
			}
		}
		else // �X�^���h�̏ꍇ
		{
			break;
		}
	}

	scoreTpm = score;
}