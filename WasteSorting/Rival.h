#pragma once
#include<string>
#include"Map.h"
using namespace std;
enum WasteSorting
{
	HaWaste,//有害垃圾Hazardous Waste
	ReWaste,//可回收垃圾Recyclable Waste
	HFWaste,//湿垃圾Household Food Waste
	RiWaste //干垃圾Residual Waste
};
class Rival
{
public:
	
	Rival();
	void initRivalCount();
	~Rival();
	//初始化
	void initRival(string rn, string fn,int rv, int ra, int rd, int rf,int re, WasteSorting rws);
	//pk函数
	void pk(int index,int& pkFlag,int& winFlag);
	//失败界面
	void failedUI();
	//动态创建不垃圾分类的人
	Rival*creatRival(int index);
	//判断分类是否正确
	bool sortingJudge();
public:
	string getRivalName()
	{
		return name;
	}
	int sHaCount;//有害垃圾
	int sReCount;//可回收垃圾
	int sHFCount;//湿垃圾
	int sRiCount;//干垃圾
private:
	string name;//名字
	string foodName;//食物名字
	int vit;//体力值
	int atk;//攻击力
	int def;//防御力
	int fine;//罚金
	int exp;//经验
	int posx;
	int posy;
	WasteSorting ws;


};

