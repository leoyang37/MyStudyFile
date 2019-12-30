#include "Prop.h"
#include <iostream>
using namespace std;
Prop::Prop()
{
}
Prop::Prop(int ty, int pr,string n, string in, int av, int aa, int ad)
	: type(ty),
	price(pr),
	name(n),
	intro(in),
	addVit(av),
	addAtk(aa),
	addDef(ad)
{
}


Prop::~Prop()
{
}

void Prop::show()
{
	//string name;//名字
	//string intro;//介绍
	//int addVit;//增加体力
	//int addAtk;//增加攻击力
	//int addDef;//增加防御力
	cout << "*********** *********" << endl;
	cout << "物品名字:" << name << endl;
	cout << "物品介绍:" << intro << endl;
	cout << "物品加体力:" << addVit << endl;
	cout << "物品加攻击力:" << addAtk << endl;
	cout << "物品加防御力:" << addDef << endl;
	cout << "*************************" << endl;

}
