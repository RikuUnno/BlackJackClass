#include <iostream>�B

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//���s
void Result(Player* player, Dealer *dealer)
{
	if (player->ScoreGetter() == dealer->ScoreGetter())
	{
		cout << "��������" << endl;
	}
	else if (player->ScoreGetter() < dealer->ScoreGetter())
	{
		cout << "�f�B���[�̏���" << endl;
	}
	else if (player->ScoreGetter() > dealer->ScoreGetter())
	{
		cout << "�v���C���[�̏���" << endl;
	}
}

int main()
{
	//�����̏�����
	srand((unsigned int)time(NULL));

	//�J�[�h�̃V���b�t���Ɗe�N���X�̐錾
	Deck deck;
	Player player;
	Dealer dealer;

	//�v���C���[�̃^�[��
	player.PlayerTurn(deck);
	
	//�o�[�X�g�`�F�b�N
	if (player.BurstCheck())
	{
		cout << "�o�[�X�g���܂����B���Ȃ��̕����ł��B" << endl;
		return 0;
	}

	cout << endl;
	cout << "�f�B���[�̃^�[��" << endl;
	
	// �f�B���[�̃^�[��
	dealer.DealerTurn(deck);

	//�o�[�X�g�`�F�b�N
	if (dealer.BurstCheck())
	{
		cout << "�o�[�X�g���܂����B�f�B���[�̕����ł��B" << endl;
		return 0;
	}

	//���s
	Result(&player, &dealer);

}
