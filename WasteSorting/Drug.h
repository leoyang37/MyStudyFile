#pragma once
#include "Prop.h"
#include"Player.h"
#include<string>
using namespace std;

class Drug : public Prop
{
public:
	Drug(int ty, int pr,string na, string inr, int adv = 0, int ada = 0, int add = 0);
	virtual ~Drug();
	//获得价格
	int getPrice();
public:
	void use() override;


};

