#pragma once
#include <string>
#include"Map.h"

using namespace std;
enum TaskState
{
	UNSTART=0,//未开始
	GOING,//进行中
	DONE//完成
};

class Task
{
public:
	Task();
	Task(string na, string ir, int HaC, int ReC, int HFC, int RiC,int tC, TaskState tS, int eT);
	~Task();
public:
	string  getName()
	{
		return name;
	}

public:
	void taskUI();//任务栏
	void taskChoice();//选择
	Task* creatTask(int index);//动态创建任务
	void showTask(int index);//展示任务
	//设置目标数
	void setSortingCount(int sC)
	{
		sortingCount = sC;
	}
	//判断任务是否完成
	bool taskDone();
	void setState(TaskState sets)
	{
		tState = sets;
	}
	bool isAllDone(Map&map);
	TaskState tState;//任务的三种状态
	int targetCount;//目标数量
	int sortingCount;//已经分类的数量

public:
	//垃圾分类成功计数器
	int HaCount;//有害垃圾
	int ReCount;//可回收垃圾
	int HFCount;//湿垃圾
	int RiCount;//干垃圾
private:
	string name;//名字
	string intro;//介绍
	int expTask;//经验奖励
};

