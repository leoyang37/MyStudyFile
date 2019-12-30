#include "ArrayTask.h"
#include "Task.h"
#include <string.h>
#include<conio.h>
#include <windows.h>
#include<iostream>
#include"FrameUI.h"
#include"Rival.h"
using namespace std;

ArrayTask::ArrayTask(int _size)
	:size(0),
	maxSize(_size),
	pTask(new Task*[_size])
{
	
}

ArrayTask::ArrayTask(const ArrayTask& ref)
	:size(ref.size),
	maxSize(ref.maxSize),
	pTask(new Task*[maxSize])
{
	//重新申请内存
	//将ref.pTask指向的内容拷贝到pTask中
	memcpy(pTask, ref.pTask, sizeof(Task*) * size);
}

ArrayTask::~ArrayTask()
{
	//释放内存
	delete[] pTask;
	//指针置空
	pTask = nullptr;
}

void ArrayTask::takeTask(Task* Task)
{
	if (isFull())//如果满
	{
		resize();//扩容
	}
	//添加元素
	pTask[size] = Task;
	size++;
}

string ArrayTask::getTask(int i)
{
	return pTask[i]->getName();
}
void ArrayTask::setState(TaskState ts,int i)
{
	pTask[i]->tState = ts;
}
void ArrayTask::setSortingCount(int s, int i)
{
	pTask[i]->sortingCount = s;
}
bool ArrayTask::isFull() const
{
	return size == maxSize;
}

void ArrayTask::resize()
{
	//1.申请原先大小2倍的内存,用新指针保存
	Task** pNew = new Task*[maxSize * 2];
	//2.将旧内存中的内容拷贝到新内存中
	memcpy(pNew, pTask, sizeof(Task*) * size);
	//3.释放旧内存
	delete[] pTask;
	//4.pTask指向新内存
	pTask = pNew;
	//5.maxSize*=2;
	maxSize *= 2;
}

//遍历
void ArrayTask::show()
{

	FrameUI::setPositionUI(61, 3);
	cout << "------已接受的任务-------" << endl;
	//展示物品
	for (int i = 0; i < size; i++)
	{
		int index = i*8;
		FrameUI::setPositionUI(61, 4 + index);
		cout <<"◎序号:"<< i + 1 << endl;
		pTask[i]->showTask(index);//每一个物品的show方法
		cout << endl;
	}

}
