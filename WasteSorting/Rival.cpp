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
#define _Green SetConsoleTextAttribute(h4, 0x0a) // ��
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
	 sHaCount=0;//�к�����
	 sReCount = 0;//�ɻ�������
	 sHFCount = 0;//ʪ����
	 sRiCount = 0;//������
}

Rival::~Rival()
{
}
Rival*Rival::creatRival(int index)
{
	//ʪ����
	if (0 == index)
	{
	
		Rival* rival = new Rival;
		initRival("С��Ϻ��", "С��Ϻ",120, 200, 30,500, 100, HFWaste);
		return rival;
	}
	else if (1 == index)
	{
		Rival* rival = new Rival;
		initRival("�̲�֥֥��","��֥ʿ�������̲�", 100, 30, 200, 500, 50, RiWaste);
		return rival;
	}
	else if (2 == index)
	{
		Rival* rival = new Rival;
		initRival("���������", "������", 2000, 100, 200, 500, 50, HFWaste);
		return rival;
	}
	else if (3 == index)
	{
		Rival* rival = new Rival;
		initRival("±ζ��","±ζ", 90, 90, 90, 500, 45, HFWaste);
		return rival;
	}
	//�к�����
	else if (4 == index)
	{
		Rival* rival = new Rival;
		initRival("�ڷ�Һ�Ҷ���","�ڷ�Һƿ", 50, 50, 50, 500, 50, HaWaste);
		return rival;
	}
	else if (5 == index)
	{
		Rival* rival = new Rival;
		initRival("����","���", 50, 50, 50, 500, 50, ReWaste);
		return rival;
	}
	//�ɻ�������
	else if (6==index)
	{
		Rival* rival = new Rival;
		initRival("��ĭ���Ϲ�","��ĭ����", 60, 60, 60, 500, 60, ReWaste);
		return rival;
	}
	else if (7 == index)
	{
		Rival* rival = new Rival;
		initRival("���̹�","���̹�", 60, 60, 60, 500, 60, ReWaste);
		return rival;
	}
	//������:ש���մɣ�����������Ⱦ������ֽ/ֽ�����Ի����Լ����޻������ü�ֵ�ķ������
	else if (8 == index)
	{
		Rival* rival = new Rival;
		initRival("������", "������",70, 70, 70, 500, 70, ReWaste);
		return rival;
	}
	else if (9 == index)
	{
		Rival* rival = new Rival;
		initRival("�Ѿ�����Ⱦ��ֽ���Ҷ���","����Ⱦ��ֽ��", 7, 70, 70, 500, 70, ReWaste);
		return rival;
	}
}

void Rival::pk(int index, int& pkFlag,int& winFlag)
{
	Rival* rival = creatRival(index);
	//������ʱ�洢����
	int tempVit = Player::getPlayer()->getVit();
	int tempAtk = Player::getPlayer()->getAtk();
	int tempDef = Player::getPlayer()->getDef();
	//�ж��ܲ��ܴ�
	if (tempAtk <= def)
	{
		pkFlag = 0;
		winFlag = 0;
		return;
	}

	while (tempVit > 0 && vit>0)//ģ��pk
	{
		FrameUI::setPositionUI(0, 0);
		vit -= (tempAtk - def > 0) ? (tempAtk - def) : 0;
		vit = vit > 0 ? vit : 0;
		cout << "��:ʹ�ÿ���ȭ" <<endl;
		Sleep(100);
		cout << name << "�ܵ�" << ((tempAtk - def > 0) ? tempAtk - def : 0) << "���˺�" << endl << endl;
		Sleep(100);
		tempVit -= (atk - tempDef > 0) ? (atk - tempDef) : 0;
		tempVit = tempVit > 0 ? tempVit : 0;
		cout << name << ":ʹ����ͨ����" <<  endl;
		Sleep(100);
		cout << "��:����ֵ-" << ((atk - tempDef > 0) ? atk - tempDef : 0) << endl<<endl;
		Sleep(100);
	}
	FrameUI::clearUI(0, 0, 1, 7);
	//��������
	if (tempVit>0&&0 == vit)
	{
		cout << endl;
		cout << name << "��������" << endl;
		cout << "������Ta��----" << foodName << endl;
	}
	
	//1.������
	if (0 == tempVit)
	{
		int pkFlag = 0;
		failedUI();	
		winFlag = 0;
	}
	//PK�������ֵ�ı�
	Player::getPlayer()->setVit(tempVit);
	
	//2.ʤ����,������������
	//2.1��������ʧ��
	
	if (sortingJudge() == false)
	{
		
		FrameUI::setPositionUI(60, 9);
		cout << " ������ʧ�ܡ��" << endl;
		_getch();
		//2.1.1�ж��Ƿ��н�Ǯ
		//��Ǯ����
		int tMoney = Player::getPlayer()->getMoney();
		if (tMoney <= 0)
		{
			Player::getPlayer()->playerUI();
			FrameUI::setPositionUI(60, 9);
			cout << "������������ʧ��!" << endl;
			_getch();
			failedUI();
			return;
		}
	}
	//2.2��������ɹ�
	else
	{
		FrameUI::setPositionUI(60, 9);
		cout << "����ɹ�!" << endl;
		_getch();
		//��ȡ�������ྭ��
		Player::getPlayer()->addExp(exp);
	}
	//ָ��ɾ���ÿ�
	delete rival;
	rival = nullptr;
}

void Rival::failedUI()
{
	//�����һ��UI
	FrameUI::clearUI(60, 3, 80, 10);
	
	FrameUI::setPositionUI(62, 3);
	printf("����������������������������������������������������\n");
	FrameUI::setPositionUI(62, 4);
	printf("��                    - �� X\n");
	FrameUI::setPositionUI(62, 5);
	printf("��   ��������ʧ��\n"                                   );
	FrameUI::setPositionUI(62, 6);
	printf("��   O������Ϸ  X�˳���Ϸ                            \n");
	FrameUI::setPositionUI(62, 7);
	printf("����������������������������������������������������\n");
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
			cout << "������~" << endl;
			exit(1);
			break;
		}
	}
}
bool Rival::sortingJudge()
{
	//HaWaste,//�к�����Hazardous Waste
	//ReWaste,//�ɻ�������Recyclable Waste
	//HFWaste,//ʪ����Household Food Waste
	//RiWaste //������Residual Waste
	
	bool judegFlag = true;
	Player::getPlayer()->playerUI();
	FrameUI::setPositionUI(60, 3);
	printf("������������������������������������������������������������������������������������������������������");
	FrameUI::setPositionUI(60, 4);
	printf("��                                        - �� X");
	FrameUI::setPositionUI(60, 5);
	printf("��   ����ܵ���:");
	cout << name;
	FrameUI::setPositionUI(60, 6);
	printf("��  ������Ta���������з���,���ķ���ѡ����(�������):");
	FrameUI::setPositionUI(60, 7);
	printf("��  ���к�����  �ڿɻ�������  ��ʪ����  �ܸ�����");
	FrameUI::setPositionUI(60, 8);
	printf("������������������������������������������������������������������������������������������������������\n");


	//������ʱ�����洢��Ǯ 
	int tempMoney = Player::getPlayer()->getMoney();
	//��������
	FrameUI::setPositionUI(0, 1);
	char choiceSorting = _getch();
	switch (choiceSorting)
	{
	case '1':
		//����ɹ� ����switch
		if (ws == HaWaste)
		{
			sHaCount++;
			break;
		}

		//�������ʧ��,�۳�����
		tempMoney -= fine;
		//�޸ı��
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
	//���øı��Ľ�Ǯ
	Player::getPlayer()->setMoney(tempMoney);
	return judegFlag;
}

