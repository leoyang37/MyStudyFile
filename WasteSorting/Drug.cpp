#include "Drug.h"
#include <iostream>
using namespace std;

Drug::Drug(int ty, int pr,string na, string inr, int adv, int ada, int add)
	:Prop(ty, pr,na, inr, adv, ada, add)
{
}
int Drug::getPrice()
{
	return price;
}

Drug::~Drug()
{
}
//药品的使用
void Drug::use()
{
	//string name;//名字
	//string intro;//介绍
	//int addVit;//增加体力
	//int addAtk;//增加攻击力
	//int addDef;//增加防御力
	cout << "英雄使用了" << name << endl;
	Player::getPlayer()->setchange(addVit, addAtk, addDef);
    
}
