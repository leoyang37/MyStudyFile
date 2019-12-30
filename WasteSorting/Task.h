#pragma once
#include <string>
#include"Map.h"

using namespace std;
enum TaskState
{
	UNSTART=0,//δ��ʼ
	GOING,//������
	DONE//���
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
	void taskUI();//������
	void taskChoice();//ѡ��
	Task* creatTask(int index);//��̬��������
	void showTask(int index);//չʾ����
	//����Ŀ����
	void setSortingCount(int sC)
	{
		sortingCount = sC;
	}
	//�ж������Ƿ����
	bool taskDone();
	void setState(TaskState sets)
	{
		tState = sets;
	}
	bool isAllDone(Map&map);
	TaskState tState;//���������״̬
	int targetCount;//Ŀ������
	int sortingCount;//�Ѿ����������

public:
	//��������ɹ�������
	int HaCount;//�к�����
	int ReCount;//�ɻ�������
	int HFCount;//ʪ����
	int RiCount;//������
private:
	string name;//����
	string intro;//����
	int expTask;//���齱��
};

