#pragma once
#include"Map.h"
#include"Store.h"
#include<string>
#include"Bag.h"
#include"Rival.h"
#include"Task.h"
#include"ArrayTask.h"
class Task;
class Store;
using namespace std;
//单例化玩家
class Player
{
public:
	static Player*getPlayer();//静态函数:创建对象
	~Player();
private:
	Player();
	static Player*pPlayer;//定义静态指针,记录对象地址

public:
	void initPlayer();
	void findPlayer(Map&map);//寻找玩家位置
	void movePlayer(Map& map, Store store,Rival rival,Task task);//玩家移动函数
	void playerUI();
	void readPlayer();//读取玩家信息
	void savePlayer();//保存玩家信息
public:
	void setPos(int x, int y);//设置玩家位置
	//获取金钱 改变金钱
	int getMoney();
	void setMoney(int mon);
	//增加垃圾分类经验 判断是否升级
	void addExp(int ex)
	{
		exp += ex;
		//如果>200则进行升级 属性强化
		if (exp >= 200)
		{
			exp -= 200;
			lv++;
			vit += 25;
			atk += 25;
			def += 25;
		}
	}
	//获取体力 改变体力
	int getVit()
	{
		return vit;
	}
	void setVit(int v)
	{
		vit = v;
	}
	//获取攻击力
	int getAtk()
	{
		return atk;
	}
	//获取防御力
	int getDef()
	{
		return def;
	}
	//使用食物/装备改变英雄属性
	void setchange(int l,int a,int d)
	{
		vit += l;
		atk += a;
		def += d;
	}
	Bag bag;//玩家背包
	ArrayTask* pArrayT;//任务动态数组
public:
	
	//1.接受任务
	void takeTask(Task* Task);
	//2.展示任务
	void showTask();
	//3.获得任务名字
	string getTaskName(Task* task);
	//4.玩家升级
	void lvUpgrade();
private:
	string name;//名字
	int lv;//等级
	int vit;//体力值
	int atk;//攻击力
	int def;//防御力
	int money;//金钱
	int exp;//经验
	int posX;//玩家坐标
	int posY;
	

};

