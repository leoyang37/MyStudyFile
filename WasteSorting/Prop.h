#pragma once
#include <string>
using namespace std;
//Prop:抽象类商城道具
class Prop
{
public:
	Prop();
	Prop(int ty,int pr,string n, string in, int av , int aa , int ad );
	~Prop();
public:
	virtual void use() = 0;//使用//use:纯虚函数
	void show();//展示
protected:
	int type;
	int price;
	string name;//名字
	string intro;//介绍
	int addVit;//增加体力
	int addAtk;//增加攻击力
	int addDef;//增加防御力
};

