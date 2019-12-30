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
	//���������ڴ�
	//��ref.pTaskָ������ݿ�����pTask��
	memcpy(pTask, ref.pTask, sizeof(Task*) * size);
}

ArrayTask::~ArrayTask()
{
	//�ͷ��ڴ�
	delete[] pTask;
	//ָ���ÿ�
	pTask = nullptr;
}

void ArrayTask::takeTask(Task* Task)
{
	if (isFull())//�����
	{
		resize();//����
	}
	//���Ԫ��
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
	//1.����ԭ�ȴ�С2�����ڴ�,����ָ�뱣��
	Task** pNew = new Task*[maxSize * 2];
	//2.�����ڴ��е����ݿ��������ڴ���
	memcpy(pNew, pTask, sizeof(Task*) * size);
	//3.�ͷž��ڴ�
	delete[] pTask;
	//4.pTaskָ�����ڴ�
	pTask = pNew;
	//5.maxSize*=2;
	maxSize *= 2;
}

//����
void ArrayTask::show()
{

	FrameUI::setPositionUI(61, 3);
	cout << "------�ѽ��ܵ�����-------" << endl;
	//չʾ��Ʒ
	for (int i = 0; i < size; i++)
	{
		int index = i*8;
		FrameUI::setPositionUI(61, 4 + index);
		cout <<"�����:"<< i + 1 << endl;
		pTask[i]->showTask(index);//ÿһ����Ʒ��show����
		cout << endl;
	}

}
