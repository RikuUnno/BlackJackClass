#include <iostream>�B

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//���s
void Result(Player* player, Dealer *dealer)
{
	if (player->GetScore() == dealer->GetScore())
	{
		cout << "��������" << endl;
	}
	else if (player->GetScore() < dealer->GetScore())
	{
		cout << "�f�B���[�̏���" << endl;
	}
	else if (player->GetScore() > dealer->GetScore())
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

	Person& p_person = player;
	Person& d_person = dealer;

	//�v���C���[�̃^�[��
	player.PlayerTurn(deck);
	
	//�o�[�X�g�`�F�b�N
	if (p_person.BurstCheck())
	{
		cout << "�o�[�X�g���܂����B���Ȃ��̕����ł��B" << endl;
		return 0;
	}

	cout << endl;
	cout << "�f�B���[�̃^�[��" << endl;
	
	// �f�B���[�̃^�[��
	dealer.DealerTurn(deck);

	//�o�[�X�g�`�F�b�N
	if (d_person.BurstCheck())
	{
		cout << "�o�[�X�g���܂����B�f�B���[�̕����ł��B" << endl;
		return 0;
	}

	//���s
	Result(&player, &dealer);

}