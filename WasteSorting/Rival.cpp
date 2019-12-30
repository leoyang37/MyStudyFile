#include "Rival.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"Player.h"
#include"Func\func.h"
#include<Windows.h>
#include "FrameUI.h"
#include"Bag.h"
#include<string.h>
#include"ArrayTask.h"
using namespace std;
HANDLE h4 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Green SetConsoleTextAttribute(h4, 0x0a) // 绿
COORD coord4;
using namespace std;



void Rival::initRival(string rn, string fn,int rv, int ra, int rd, int rf, int re, WasteSorting rws)
{	
	name = rn;
	foodName = fn;
	vit = rv;
	atk = ra;
	def = rd;
	fine = rf;
	exp = re;
	ws = rws;

}
Rival::Rival()
{
	
}
void Rival::initRivalCount()
	
{
	 sHaCount=0;//有害垃圾
	 sReCount = 0;//可回收垃圾
	 sHFCount = 0;//湿垃圾
	 sRiCount = 0;//干垃圾
}

Rival::~Rival()
{
}
Rival*Rival::creatRival(int index)
{
	//湿垃圾
	if (0 == index)
	{
	
		Rival* rival = new Rival;
		initRival("小龙虾怪", "小龙虾",120, 200, 30,500, 100, HFWaste);
		return rival;
	}
	else if (1 == index)
	{
		Rival* rival = new Rival;
		initRival("奶茶芝芝怪","加芝士的珍珠奶茶", 100, 30, 200, 500, 50, RiWaste);
		return rival;
	}
	else if (2 == index)
	{
		Rival* rival = new Rival;
		initRival("臭豆腐丑怪", "臭豆腐", 2000, 100, 200, 500, 50, HFWaste);
		return rival;
	}
	else if (3 == index)
	{
		Rival* rival = new Rival;
		initRival("卤味怪","卤味", 90, 90, 90, 500, 45, HFWaste);
		return rival;
	}
	//有害垃圾
	else if (4 == index)
	{
		Rival* rival = new Rival;
		initRival("口服液乱丢怪","口服液瓶", 50, 50, 50, 500, 50, HaWaste);
		return rival;
	}
	else if (5 == index)
	{
		Rival* rival = new Rival;
		initRival("软膏怪","软膏", 50, 50, 50, 500, 50, ReWaste);
		return rival;
	}
	//可回收垃圾
	else if (6==index)
	{
		Rival* rival = new Rival;
		initRival("泡沫塑料怪","泡沫塑料", 60, 60, 60, 500, 60, ReWaste);
		return rival;
	}
	else if (7 == index)
	{
		Rival* rival = new Rival;
		initRival("托盘怪","托盘怪", 60, 60, 60, 500, 60, ReWaste);
		return rival;
	}
	//干垃圾:砖瓦陶瓷，尘土，已污染的卫生纸/纸巾、难以回收以及暂无回收利用价值的废弃物等
	else if (8 == index)
	{
		Rival* rival = new Rival;
		initRival("尘土怪", "尘土怪",70, 70, 70, 500, 70, ReWaste);
		return rival;
	}
	else if (9 == index)
	{
		Rival* rival = new Rival;
		initRival("已经被污染的纸巾乱丢怪","被污染的纸巾", 7, 70, 70, 500, 70, ReWaste);
		return rival;
	}
}

void Rival::pk(int index, int& pkFlag,int& winFlag)
{
	Rival* rival = creatRival(index);
	//定义临时存储体力
	int tempVit = Player::getPlayer()->getVit();
	int tempAtk = Player::getPlayer()->getAtk();
	int tempDef = Player::getPlayer()->getDef();
	//判断能不能打
	if (tempAtk <= def)
	{
		pkFlag = 0;
		winFlag = 0;
		return;
	}

	while (tempVit > 0 && vit>0)//模拟pk
	{
		FrameUI::setPositionUI(0, 0);
		vit -= (tempAtk - def > 0) ? (tempAtk - def) : 0;
		vit = vit > 0 ? vit : 0;
		cout << "你:使用空气拳" <<endl;
		Sleep(100);
		cout << name << "受到" << ((tempAtk - def > 0) ? tempAtk - def : 0) << "点伤害" << endl << endl;
		Sleep(100);
		tempVit -= (atk - tempDef > 0) ? (atk - tempDef) : 0;
		tempVit = tempVit > 0 ? tempVit : 0;
		cout << name << ":使用普通攻击" <<  endl;
		Sleep(100);
		cout << "你:体力值-" << ((atk - tempDef > 0) ? atk - tempDef : 0) << endl<<endl;
		Sleep(100);
	}
	FrameUI::clearUI(0, 0, 1, 7);
	//怪物死了
	if (tempVit>0&&0 == vit)
	{
		cout << endl;
		cout << name << "被你打败了" << endl;
		cout << "交出了Ta的----" << foodName << endl;
	}
	
	//1.打输了
	if (0 == tempVit)
	{
		int pkFlag = 0;
		failedUI();	
		winFlag = 0;
	}
	//PK后的体力值改变
	Player::getPlayer()->setVit(tempVit);
	
	//2.胜利了,进行垃圾分类
	//2.1垃圾分类失败
	
	if (sortingJudge() == false)
	{
		
		FrameUI::setPositionUI(60, 9);
		cout << " ●●分类失败●●" << endl;
		_getch();
		//2.1.1判断是否还有金钱
		//金钱不足
		int tMoney = Player::getPlayer()->getMoney();
		if (tMoney <= 0)
		{
			Player::getPlayer()->playerUI();
			FrameUI::setPositionUI(60, 9);
			cout << "垃圾分类任务失败!" << endl;
			_getch();
			failedUI();
			return;
		}
	}
	//2.2垃圾分类成功
	else
	{
		FrameUI::setPositionUI(60, 9);
		cout << "分类成功!" << endl;
		_getch();
		//获取垃圾分类经验
		Player::getPlayer()->addExp(exp);
	}
	//指针删除置空
	delete rival;
	rival = nullptr;
}

void Rival::failedUI()
{
	//清除上一次UI
	FrameUI::clearUI(60, 3, 80, 10);
	
	FrameUI::setPositionUI(62, 3);
	printf("┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
	FrameUI::setPositionUI(62, 4);
	printf("┆                    - □ X\n");
	FrameUI::setPositionUI(62, 5);
	printf("┆   垃圾分类失败\n"                                   );
	FrameUI::setPositionUI(62, 6);
	printf("┆   O重新游戏  X退出游戏                            \n");
	FrameUI::setPositionUI(62, 7);
	printf("┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
	FrameUI::setPositionUI(0, 1);
	char choice = _getch();
	while (1)
	{
		switch (choice)
		{
		case'o':case'O':
			menu();
			break;
		case 'x':case'X':
			cout << "退游中~" << endl;
			exit(1);
			break;
		}
	}
}
bool Rival::sortingJudge()
{
	//HaWaste,//有害垃圾Hazardous Waste
	//ReWaste,//可回收垃圾Recyclable Waste
	//HFWaste,//湿垃圾Household Food Waste
	//RiWaste //干垃圾Residual Waste
	
	bool judegFlag = true;
	Player::getPlayer()->playerUI();
	FrameUI::setPositionUI(60, 3);
	printf("┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄");
	FrameUI::setPositionUI(60, 4);
	printf("┆                                        - □ X");
	FrameUI::setPositionUI(60, 5);
	printf("┆   你击败的是:");
	cout << name;
	FrameUI::setPositionUI(60, 6);
	printf("┆  请您对Ta的垃圾进行分类,您的分类选择是(输入序号):");
	FrameUI::setPositionUI(60, 7);
	printf("┆  ①有害垃圾  ②可回收垃圾  ③湿垃圾  ④干垃圾");
	FrameUI::setPositionUI(60, 8);
	printf("┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");


	//定义临时变量存储金钱 
	int tempMoney = Player::getPlayer()->getMoney();
	//分类输入
	FrameUI::setPositionUI(0, 1);
	char choiceSorting = _getch();
	switch (choiceSorting)
	{
	case '1':
		//分类成功 跳出switch
		if (ws == HaWaste)
		{
			sHaCount++;
			break;
		}

		//如果分类失败,扣除罚金
		tempMoney -= fine;
		//修改标记
		judegFlag = false;
		break;
	case '2':
		if (ws == ReWaste)
		{
			sReCount++;
			break;
		}
		tempMoney -= fine;
		judegFlag = false;
		break;
	case '3':
		if (ws == HFWaste)
		{
			sHFCount++;
			break;
		}
		tempMoney -= fine;
		judegFlag = false;
		break;
	case '4':
		if (ws == RiWaste)
		{
			sRiCount++;
			break;
		}
		tempMoney -= fine;
		judegFlag = false;
		break;
	}
	//设置改变后的金钱
	Player::getPlayer()->setMoney(tempMoney);
	return judegFlag;
}

