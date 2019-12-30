#include "Task.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"FrameUI.h"
#include"Player.h"
HANDLE h3 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Green SetConsoleTextAttribute(h3, 0x0a) // ��
COORD coord3;
using namespace std;
Task::Task()
{
}
//
////��������ɹ�������
//int HaCount;//�к�����
//int ReCount;//�ɻ�������
//int HFCount;//ʪ����
//int RiCount;//������

//���� ���� �������� �к��������� �ɻ�������  ʪ���� ������ ������� Ŀ���� ״̬ ����
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
	//��
	const int taskRow =15;
	//�� 
	const int taskLine = 15;
    //�����ͼ
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
	
	//����
	for (int i = 0; i < taskRow; i++)
	{
		//���û��Ƶ�����
		coord3.Y = i+3;
		coord3.X = 70;
		for (int j = 0; j < taskLine; j++)
		{
			coord3.X = 70 + j;
			SetConsoleCursorPosition(h3, coord3);
			switch (taskMap[i][j])
			{
			case -5:
				cout << "��";
				break;
			case -4:
				cout << "��";
				break;
			case -3:
				cout << "��";
				break;
			case -2:
				cout << "��";
				break;
			case -1:
				cout << "��";
				break;
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "��";
				break;

			case 9:
				cout << "*������*";
				break;
			case 10:
				cout << "��С��ţ��";
				break;
			
			case 20:
				cout << "���붬ʧ��";
				break;
		
			/*case 30:
				cout << "�۷����ʦ";
				break;*/
				

			}
		}
		cout << endl;
	}
	FrameUI::setPositionUI(1, 1);
	cout << "���ѡ������Ҫ�ӵ�����,����p/P�˳�������." << endl;
	_getch();
	
	
}
void Task::taskChoice()
{
	
	char choice=_getch();
	switch (choice)
	{
		//����1��ʱ�� ��������1������
		//�����->����̬������->��������(��̬��������)
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
	cout << "�ѽ�������!" << endl;
	_getch();
	

}
Task* Task::creatTask(int choice)
{
	//���ѡ�����1������
	if (1 == choice)
	{
		//���� ����  �к����� �ɻ�������  ʪ���� ������ ������� Ŀ���� ״̬ ����
		Task* firstTask = new Task("С��ţ��", "��������������һ��", 1,1,1,1, 0, GOING, 200);
		return firstTask;
	}
	//���ѡ�����2������
	if (2 == choice)
	{
		Task* SecondTask = new Task("�붬ʧ��", "��������,ʪ�����ٲ������Ҫ����",0,0,3,0, 0, GOING,50);
		return SecondTask;
	}
	/*if (3== choice)
	{
		Task* masterTask = new Task("�����ʦ", "��������е�����������øɸɾ���",0,1, GOING,500);
		return masterTask;
	}*/
	
}
void Task::showTask(int index)
{

	FrameUI::setPositionUI(61, 5 + index);
	cout << "������:" << name;
	FrameUI::setPositionUI(61, 6 + index);
	cout << "�����:" << intro;
	FrameUI::setPositionUI(61, 7 + index);
	cout << "�����ɴ���:" ;
	FrameUI::setPositionUI(61, 8 + index);
	cout << "  �к�����(" << HaCount << ")^�ɻ�������(" << ReCount << ")^ʪ����(" << HFCount << ")^������("<<RiCount<<")" ;
	FrameUI::setPositionUI(61, 9 + index);
	cout << "������״̬:";
	if (0 == tState)
	{
		cout << "δ���" << endl;
	}
	else if (1 == tState)
	{
		cout << "������" << endl;
	}
	else if (2 == tState)
	{
		cout << "�����" << endl;
	}
	FrameUI::setPositionUI(61, 10 + index);
	cout << "����:" << "����÷��ྭ��Ϊ:" << expTask;
}
bool Task::isAllDone(Map&map)
{
	//��ȡ��ͼ��pMap
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
