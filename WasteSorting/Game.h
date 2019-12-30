#pragma once
#include "Map.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
public:
	void init();//��ʼ��
	void update();//����
	void draw();//����
private:
	//��ͼ
	Map map;
	//���
	Player* player =Player::getPlayer();
	//����
	Store store;
	//����
	Rival rival;
	//����
	Task task;
};

