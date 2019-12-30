#include "Task.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"FrameUI.h"
#include"Player.h"
HANDLE h3 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Green SetConsoleTextAttribute(h3, 0x0a) // 绿
COORD coord3;
using namespace std;
Task::Task()
{
}
//
////垃圾分类成功计数器
//int HaCount;//有害垃圾
//int ReCount;//可回收垃圾
//int HFCount;//湿垃圾
//int RiCount;//干垃圾

//名字 介绍 垃圾名字 有害垃圾数量 可回收垃圾  湿垃圾 干垃圾 已完成数 目标数 状态 经验
Task::Task(string na, string ir, int HaC, int ReC, int HFC, int RiC,  int tC, TaskState tS, int eT)
{
	name = na;
	intro = ir;
	HaCount = HaC;
	ReCount = ReC;
	HFCount = HFC;
	RiCount = RiC;
	targetCount = tC;
	tState = tS;
	expTask = eT;
}


Task::~Task()
{
}

void Task::taskUI()
{
	//行
	const int taskRow =15;
	//列 
	const int taskLine = 15;
    //任务地图
	int taskMap[taskRow][taskLine] =
	{
		{ -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -5 },
		{ -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3 },
		{ -3, 0, 0, 0, 9, 7, 7, 7, 7, 7, 7, 7, 7,7, - 3 },
		{ -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3 },
		{ -3, 7, 7, 10, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, -3 },
		{ -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3 },
		{ -3, 0, 0, 20, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, -3 },
		{ -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3 },
		{ -3, 0, 0, 30, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, -3 },
		{ -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3 },
		{ -2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -4 },

	};
	
	//绘制
	for (int i = 0; i < taskRow; i++)
	{
		//设置绘制的坐标
		coord3.Y = i+3;
		coord3.X = 70;
		for (int j = 0; j < taskLine; j++)
		{
			coord3.X = 70 + j;
			SetConsoleCursorPosition(h3, coord3);
			switch (taskMap[i][j])
			{
			case -5:
				cout << "┑";
				break;
			case -4:
				cout << "┙";
				break;
			case -3:
				cout << "┆";
				break;
			case -2:
				cout << "┕";
				break;
			case -1:
				cout << "┍";
				break;
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "┄";
				break;

			case 9:
				cout << "*任务栏*";
				break;
			case 10:
				cout << "①小试牛刀";
				break;
			
			case 20:
				cout << "②入冬失败";
				break;
		
			/*case 30:
				cout << "③分类大师";
				break;*/
				

			}
		}
		cout << endl;
	}
	FrameUI::setPositionUI(1, 1);
	cout << "如果选择您想要接的任务,输入p/P退出任务栏." << endl;
	_getch();
	
	
}
void Task::taskChoice()
{
	
	char choice=_getch();
	switch (choice)
	{
		//输入1的时候 将获得序号1的任务
		//玩家类->任务动态数组类->接受任务(动态创建任务)
	case '1':
		Player::getPlayer()->pArrayT->takeTask(creatTask(1));
		break;
	case '2':
		Player::getPlayer()->pArrayT->takeTask(creatTask(2));
		break;
	case '3':
		Player::getPlayer()->pArrayT->takeTask(creatTask(3));
		break;
	case 'p':case'P':
		return;
		break;
	}
	cout << "已接受任务!" << endl;
	_getch();
	

}
Task* Task::creatTask(int choice)
{
	//如果选择序号1的任务
	if (1 == choice)
	{
		//名字 介绍  有害垃圾 可回收垃圾  湿垃圾 干垃圾 已完成数 目标数 状态 经验
		Task* firstTask = new Task("小试牛刀", "四种垃圾都分类一次", 1,1,1,1, 0, GOING, 200);
		return firstTask;
	}
	//如果选择序号2的任务
	if (2 == choice)
	{
		Task* SecondTask = new Task("入冬失败", "天气热了,湿垃圾再不分类就要臭了",0,0,3,0, 0, GOING,50);
		return SecondTask;
	}
	/*if (3== choice)
	{
		Task* masterTask = new Task("分类大师", "将这个所有的垃圾都分类得干干净净",0,1, GOING,500);
		return masterTask;
	}*/
	
}
void Task::showTask(int index)
{

	FrameUI::setPositionUI(61, 5 + index);
	cout << "◎名字:" << name;
	FrameUI::setPositionUI(61, 6 + index);
	cout << "◎介绍:" << intro;
	FrameUI::setPositionUI(61, 7 + index);
	cout << "◎待完成次数:" ;
	FrameUI::setPositionUI(61, 8 + index);
	cout << "  有害垃圾(" << HaCount << ")^可回收垃圾(" << ReCount << ")^湿垃圾(" << HFCount << ")^干垃圾("<<RiCount<<")" ;
	FrameUI::setPositionUI(61, 9 + index);
	cout << "◎任务状态:";
	if (0 == tState)
	{
		cout << "未完成" << endl;
	}
	else if (1 == tState)
	{
		cout << "进行中" << endl;
	}
	else if (2 == tState)
	{
		cout << "已完成" << endl;
	}
	FrameUI::setPositionUI(61, 10 + index);
	cout << "◎奖励:" << "将获得分类经验为:" << expTask;
}
bool Task::isAllDone(Map&map)
{
	//获取地图的pMap
	int** pMap = map.getPmap();
	for (int i = 0; i < map.getRow(); i++)
	{
		for (int j = 0; j < map.getLine(); j++)
		{
			if (pMap[i][j] >= 20&&pMap[i][j]<= 29)
			{
				return false;
			}
		}
	}
	return true;
}
