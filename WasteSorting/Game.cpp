#include "Game.h"
#include<conio.h>



Game::Game()
{
}


Game::~Game()
{
}
void Game::init()//��ʼ��
{
	//�����������ʼ��
	rival.initRivalCount();
	//Ӣ�۳�ʼ��
	player->initPlayer();
	//��ͼ��ʼ��
	map.init();
	
}

void Game::update()//����
{
	//����ƶ�
	player->movePlayer(map, store, rival,task);
	//�������
	player->findPlayer(map);
	
	
}

void Game::draw()//����
{
	system("cls");
	//���õ�ͼ�Ļ���
	map.draw();
	//������Ի���
	Player::getPlayer()->playerUI();
	//��ʾ������
	map.hintUI();
	
	
}
