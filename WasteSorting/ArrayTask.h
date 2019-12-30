#pragma once
#include<string>
using namespace std;
#include"Task.h"
/*
ArrayTask:����̬����
*/
const int defaultNum = 3;//Ĭ�ϴ�С
class ArrayTask
{
public:
	ArrayTask(int size = defaultNum);
	ArrayTask(const ArrayTask& ref);
	~ArrayTask();
	//�������
	void takeTask(Task* Task);
	//����
	void show();
	string getTask(int i);
	void setState(TaskState ts,int i);
	void setSortingCount(int s, int i);
	int getSize()
	{
		return size;
	}
public:
	//int HaCount;//�к�����
	//int ReCount;//�ɻ�������
	//int HFCount;//ʪ����
	//int RiCount;//������
	//��ü�����
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

	//�ı����
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
	bool isFull() const;//�ж��Ƿ�����
	void resize();//����
private:
	Task** pTask;//�����ڵ�Ԫ��ΪTask*,ÿһ��Ԫ��ָ�������Task
	int size;//��Ÿ���
	int maxSize;//������С
};

