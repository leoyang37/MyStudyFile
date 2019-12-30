#include "Game.h"
#include<conio.h>



Game::Game()
{
}


Game::~Game()
{
}
void Game::init()//初始化
{
	//怪物计数器初始化
	rival.initRivalCount();
	//英雄初始化
	player->initPlayer();
	//地图初始化
	map.init();
	
}

void Game::update()//更新
{
	//玩家移动
	player->movePlayer(map, store, rival,task);
	//查找玩家
	player->findPlayer(map);
	
	
}

void Game::draw()//绘制
{
	system("cls");
	//调用地图的绘制
	map.draw();
	//玩家属性绘制
	Player::getPlayer()->playerUI();
	//提示栏绘制
	map.hintUI();
	
	
}
