#include <iostream>
#include <conio.h>

#include "Player.h"

using namespace std;

//�v���C���[�̃^�[���֐�
void Player::PlayerTurn(int* deck, int& remainingNum, int* playerHand, int& scoreTpm)
{
	char keyCh; // �L�[�̓��͗p
	int card = 0; // �������g�����v�̈ꎞ�I�ȕۊǗp�ϐ�
	int handSize = 0;

	// �ŏ���2��������
	for (int i = 0; i < 2; i++)
	{
		card = DrawCard(deck, remainingNum);
		if (card != -1)
		{
			playerHand[handSize++] = card;
			ShowCard(card);
		}
	}

	// �v���C���[�̃^�[��
	int score = CalculatingPoints(playerHand, handSize);
	cout << "���Ȃ��̌��݂̃X�R�A: " << score << endl;

	while (score < 21)
	{
		cout << "����ɃJ�[�h�������܂����H (h: �q�b�g / s: �X�^���h): ";
		keyCh = _getch(); // �L�[���͂��󂯎��
		cout << keyCh << endl;

		if (keyCh == 'h' || keyCh == 'H') // �q�b�g�̏ꍇ
		{
			card = DrawCard(deck, remainingNum);
			// ��L�̊֐��̖߂�l���g���ăG���[�`�F�b�N
			if (card != -1)
			{
				playerHand[handSize++] = card;
				ShowCard(card);
				score = CalculatingPoints(playerHand, handSize);
				cout << "���Ȃ��̌��݂̃X�R�A: " << score << endl;
			}
		}
		else if (keyCh == 's' || keyCh == 'S') // �X�^���h�̏ꍇ
		{
			break;
		}
	}

	scoreTpm = score;
}