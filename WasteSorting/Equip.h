#pragma once
#include "Prop.h"
#include"Player.h"
class Equip: public Prop
{
public:
	Equip(int ty, int pr, string na, string inr, int adv = 0, int ada = 0, int add = 0);
	virtual ~Equip();
	//获得价格
	int getPrice();
public:
	//使用 虚函数
	void use() override;
};

