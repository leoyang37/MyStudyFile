#pragma once
#include "Prop.h"
#include"Player.h"
class Equip: public Prop
{
public:
	Equip(int ty, int pr, string na, string inr, int adv = 0, int ada = 0, int add = 0);
	virtual ~Equip();
	//��ü۸�
	int getPrice();
public:
	//ʹ�� �麯��
	void use() override;
};

