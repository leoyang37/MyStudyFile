#pragma once
#include<string>
using namespace std;
#include"Task.h"
/*
ArrayTask:任务动态数组
*/
const int defaultNum = 3;//默认大小
class ArrayTask
{
public:
	ArrayTask(int size = defaultNum);
	ArrayTask(const ArrayTask& ref);
	~ArrayTask();
	//添加任务
	void takeTask(Task* Task);
	//遍历
	void show();
	string getTask(int i);
	void setState(TaskState ts,int i);
	void setSortingCount(int s, int i);
	int getSize()
	{
		return size;
	}
public:
	//int HaCount;//有害垃圾
	//int ReCount;//可回收垃圾
	//int HFCount;//湿垃圾
	//int RiCount;//干垃圾
	//获得计数器
	int getHaCount(int i)
	{
		return pTask[i]->HaCount;
	}
	int getReCount(int i)
	{
		return pTask[i]->ReCount;
	}
	int getHFCount(int i)
	{
		return pTask[i]->HFCount;
	}
	int getRiCount(int i)
	{
		return pTask[i]->RiCount;
	}

	//改变计数
	void setHaCount(int s,int i)
	{
		pTask[i]->HaCount = s;
	}
	void setReCount(int s, int i)
	{
		pTask[i]->ReCount = s;
	}
	void setHFCount(int s, int i)
	{
		pTask[i]->HFCount = s;
	}
	void setRiCount(int s, int i)
	{
		pTask[i]->RiCount = s;
	}

	
private:
	bool isFull() const;//判断是否满了
	void resize();//扩容
private:
	Task** pTask;//数组内的元素为Task*,每一个元素指向堆区的Task
	int size;//存放个数
	int maxSize;//容器大小
};

