#include <iostream>

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//�J�[�h�̑�����
const int TOTAL_CARDS = 52;

//�o�[�X�g�`�F�b�N
bool BurstCheck(int scoreTpm)
{
	if (scoreTpm > 21)
	{
		return true;
	}
	return false;
}

//���s
void Result(int playerScore, int dealerScore)
{
	if (playerScore == dealerScore)
	{
		cout << "��������" << endl;
	}
	else if (playerScore < dealerScore)
	{
		cout << "�f�B���[�̏���" << endl;
	}
	else if (dealerScore < playerScore)
	{
		cout << "�v���C���[�̏���" << endl;
	}
}

int main()
{
	//�����̏�����
	srand((unsigned int)time(NULL));

	int deck[TOTAL_CARDS]; // �g�����v�̕ۊǔz��
	int remainingNum = TOTAL_CARDS; //�c��̖���
	int playerHand[10], dealerHand[10]; //�v���C���[�ƃf�B�[���[�̃J�[�h��ۊǂ���ϐ�
	int playerScore = 0, dealerScore = 0; //�v���C���[�ƃf�B�[���[�̓_����ۊǂ���ϐ�

	//�J�[�h�̃V���b�t���Ɗe�N���X�̐錾
	Deck deckClass(TOTAL_CARDS, deck);
	Player player;
	Dealer dealer;


	//�v���C���[�̃^�[��
	player.PlayerTurn(deck, remainingNum, playerHand, playerScore);
	
	//scoreTpm���o�[�X�g���Ă����
	if (BurstCheck(playerScore))
	{
		cout << "�o�[�X�g���܂����B���Ȃ��̕����ł��B" << endl;
		return 0;
	}

	cout << endl;
	cout << "�f�B���[�̃^�[��" << endl;
	
	// �f�B���[�̃^�[��
	dealer.DealerTurn(deck, remainingNum, dealerHand, dealerScore);

	//scoreTpm���o�[�X�g���Ă����
	if (BurstCheck(dealerScore))
	{
		cout << "�o�[�X�g���܂����B�f�B���[�̕����ł��B" << endl;
		return 0;
	}

	//���s
	Result(playerScore, dealerScore);

}
