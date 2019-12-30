#pragma once
#include "Map.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
public:
	void init();//初始化
	void update();//更新
	void draw();//绘制
private:
	//地图
	Map map;
	//玩家
	Player* player =Player::getPlayer();
	//超市
	Store store;
	//对手
	Rival rival;
	//任务
	Task task;
};

