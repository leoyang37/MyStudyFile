#include "Player.h"
#include"Map.h"
#include<string.h>
#include"Func\func.h"
#include<conio.h>
#include<iostream>
#include<Windows.h>
#include"FrameUI.h"
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Green SetConsoleTextAttribute(h, 0x0a) // ��
#define _Blue SetConsoleTextAttribute(h, 0x0b) // ǳ��
#define _Blue2 SetConsoleTextAttribute(h, 0x09) // ǳ��
#define _Red SetConsoleTextAttribute(h, 0x0c) // ��
#define _Purple SetConsoleTextAttribute(h, 0x0d) // ��
#define _Yellow SetConsoleTextAttribute(h, 0x0e) // ��
#define _White SetConsoleTextAttribute(h, 0x07) // ��
#define _Red1 SetConsoleTextAttribute(h, 0x04) // ����
COORD coord;
Map map;

Player*Player::pPlayer = nullptr;//��̬����,ֻ�������ʼ��

//�������
void Player::takeTask(Task* task)
{
	pArrayT->takeTask(task);

}

//չʾ����
void Player::showTask()
{
	pArrayT->show();//���ö�̬�����show����
}

Player::Player()
{
	pArrayT = new ArrayTask;
}

Player::~Player()
{
	pPlayer = nullptr;
}

Player*Player::getPlayer()
{
	if (nullptr == pPlayer)//�ж�pPlayer�Ƿ�Ϊ��
	{
		pPlayer = new Player;//Ϊ��,����һ������
	}
	return pPlayer;//��Ϊ��,���ص�ַ
}

void Player::setPos(int x, int y)
{
	posX = x;
	posY = y;
}
void  Player::lvUpgrade()
{
	FrameUI::setPositionUI(0, 0);
	cout << "�Ƿ�ѡ������?����������1,�˳�������p/P" << endl;
	char choice = _getch();
	switch (choice)
	{
	case '1':
		if (exp >= 100)
		{
			exp -= 100;
			lv++;
			vit += 50;
			atk += 50;
			def += 50;
		}
		break;
	case 'p':case 'P':
		return;
		break;
	default:
		cout << "���벻�Ϸ�,�밴��ʾ��������." << endl;
		_getch();		
		break;
	}

}

//Ѱ�����λ��
void Player::findPlayer(Map&map)
{
	//��ȡ��ͼ��pMap
	int** pMap = map.getPmap();
	for (int i = 0; i < map.getRow(); i++)
	{
		for (int j = 0; j < map.getLine(); j++)
		{
			if (2 == pMap[i][j])
			{
				posX = i;
				posY = j;
			}
		}
	}
}

void Player::initPlayer()
{
	//string name;//����
	
	lv = 1;
	vit = 100;
	atk = 400;
	def = 50;
	money = 1000;
	exp = 0;
	posX = 10;
	posY = 5;
	
	
}


int Player::getMoney()
{
	return money;
}
void Player::setMoney(int mon)
{
	money = mon;
}
void Player::movePlayer(Map& map, Store store,Rival rival,Task task)
{

	//�Ȼ�ȡ����
	char key = _getch();
	int offsetX = 0, offsetY = 0;
	switch (key)
	{
	case 'W':case 'w':	case 72:
		offsetX = -1;
		break;
	case 'S':case 's':case 80:
		offsetX = 1;
		break;
	case 'A':case 'a':case 75:
		offsetY = -1;
		break;
	case'd':case'D':case 77:
		offsetY = 1;
		break;
	case 'B':case 'b':
		bag.showProp();
		_getch();
	case 'T':case 't':
		pArrayT->show();
		_getch();
		break;
	case 'Y':case 'y':
		tipsUI();//��ѧ���෨
		_getch();
		break;
	case 'F':case 'f':
		char saveMapName[40];
		for (int i = 0; i <= map.getCustoms(); i++)
		{
			sprintf(saveMapName, "Map/saveMap/map_%d.txt", i);
			saveMapFile(map.getPmap(), map.getRow(), map.getLine(), saveMapName);
		}

		saveCustoms(map.getCustoms(), "Customs/saveCust/cust.txt");
		savePlayerFile(this, "Player/savePlayer/player.txt");
		FrameUI::setPositionUI(0, 0);
		cout << "�浵�ɹ�!" << endl;
		_getch();
		break;
	case 'G':case 'g':
		char readMapName[40];
		for (int i = 0; i <= map.getCustoms(); i++)
		{
			sprintf(readMapName, "Map/saveMap/map_%d.txt", i);
			readMapFile(map.getPmap(), map.getRow(), map.getLine(), readMapName);
		}

		readCustoms(map.getCustoms(), "Customs/saveCust/cust.txt");
		readCustoms(map.getCustoms(), "Customs/saveCust/cust.txt");
		readPlayerFile(this, "Player/savePlayer/player.txt");
		FrameUI::setPositionUI(0, 0);
		cout << "�����ɹ�!" << endl;
		_getch();
		break;
		
	}
	//��ȡ��ͼ��pMap
	int** pMap = map.getPmap();
	//����Ϸ����
	if (posX + offsetX >= 0 && posX + offsetX < map.getRow() && posY + offsetY >= 0 && posY + offsetY < map.getLine())
	{
		//ǰ���ǿյ�
		if (0 == pMap[posX + offsetX][posY + offsetY])
		{
			pMap[posX + offsetX][posY + offsetY] = 2;
			pMap[posX][posY] = 0;
			posX += offsetX;
			posY += offsetY;
		}
		//ǰ����NPC //�������
		else if (-2 == pMap[posX + offsetX][posY + offsetY])
		{
			task.taskUI();
			task.taskChoice();
			
		}
		//ǰ������¥
		else if (3 == pMap[posX + offsetX][posY + offsetY])
		{
			int dir = 1;
			map.changeMap(dir);
		}
		//ǰ������¥
		else if (4 == pMap[posX + offsetX][posY + offsetY])
		{
			int dir = -1;
			map.changeMap(dir);
		}
		//ǰ�����̳� //�������Ʒ
		else if (-3 == pMap[posX + offsetX][posY + offsetY])
		{
			store.purchase();
		}
		//ǰ��������Ͱ
		else if (-6 == pMap[posX + offsetX][posY + offsetY])
		{
			lvUpgrade();
		}
		//ǰ���Ƕ���  //ʰȡ����
		else if (pMap[posX + offsetX][posY + offsetY] >= 20 && pMap[posX + offsetX][posY + offsetY]<30)
		{
			//pkFlag:�Ƿ�PK�ı��
			//winFlag:PK�Ƿ�ʤ��
			int pkFlag = 1,winFlag=1;
			//��̬���ɲ�������������
			rival.pk(pMap[posX + offsetX][posY + offsetY]-20,pkFlag,winFlag);
			//PKʤ��
			if (1 == winFlag)
			{
				pMap[posX + offsetX][posY + offsetY] = 2;
				pMap[posX][posY] = 0;
				posX += offsetX;
				posY += offsetY;
				//���������ȷ
				if (true == rival.sortingJudge())
				{
					//�жϷ����Ƿ��������Ҫ��	
					//������������ i<������
					for (int i = 0; i < pArrayT->getSize(); i++)
					{
						//��������Ƿ���� "С��ţ��"����
						if (0==(pArrayT[i].getTask(i).compare("С��ţ��")))
						{
							//ʵʱ����"������-����ɴ���"
							//1.�к�����
							//���㷽ʽ:  �ѷ��������-����Ҫ������� //ֵ>0ȡ0,<0���ֲ���
							int temp1 = (rival.sHaCount-pArrayT[i].getHaCount(i) >= 0) ? 0 : pArrayT[i].getHaCount(i);
							pArrayT[i].setHaCount(temp1,i);

							//2.�ɻ�������
							int temp2 = (rival.sReCount - pArrayT[i].getReCount(i) >= 0) ? 0 : pArrayT[i].getReCount(i);
							pArrayT[i].setReCount(temp2, i);

							//3.ʪ����
							int temp3 = (rival.sHFCount - pArrayT[i].getHFCount(i) >= 0) ? 0 : pArrayT[i].getHFCount(i);
							pArrayT[i].setHFCount(temp3, i);

							//4.������
							int temp4 = (rival.sRiCount - pArrayT[i].getRiCount(i) >= 0) ? 0 : pArrayT[i].getRiCount(i);
							pArrayT[i].setRiCount(temp4, i);
							
							//�ж��Ƿ�ﵽ����Ҫ��
							if (pArrayT[i].getHaCount(i) ==0&& pArrayT[i].getHFCount(i) ==0
								&& pArrayT[i].getReCount(i)==0 && pArrayT[i].getRiCount(i)==0)
							{
								//�޸������״̬(��ɶ�,״̬)
								pArrayT[i].setState(DONE, i);
							}
							break;
						}
						//�����Ƿ��� "�붬ʧ��"����
						 if (0 == (pArrayT[i].getTask(i).compare("�붬ʧ��")))
						{
							int temp3 = (rival.sHFCount - pArrayT[i].getHFCount(i) >= 0) ? 0 : pArrayT[i].getHFCount(i);
							pArrayT[i].setHFCount(temp3, i);

			
							//�ж��Ƿ�ﵽ����Ҫ��
							if (0 == pArrayT[i].getHFCount(i))
							{
								//�޸������״̬(��ɶ�,״̬)
								pArrayT[i].setState(DONE, i);
							}
							break;
						}
						//�����Ƿ��� "�����ʦ"����
						 if (0 == (pArrayT[i].getTask(i).compare("�����ʦ")))
						{
							//�ж��Ƿ�ﵽ����Ҫ��
							if (task.isAllDone(map))
							{
								//�޸������״̬(��ɶ�,״̬)
								pArrayT[i].setState(DONE, i);
							}
							break;
						}
						
					}
					
					
				}
			}
		}
	
	}
}

void Player::playerUI()
{
	coord.X = 31;
	coord.Y = 15;
	SetConsoleCursorPosition(h, coord);
	printf("������������������������������������������������������������\n");

	coord.Y = 16;
	SetConsoleCursorPosition(h, coord);
	cout << "��  ����������λ��-�������   ��" << endl;

	coord.Y = 17;
	SetConsoleCursorPosition(h, coord);
	cout << "��                            ��" << endl;
	
	
	
	
	coord.Y = 18;
	SetConsoleCursorPosition(h, coord);
	printf("�� ����:                   %-3d��\n", vit);
	/*cout << "�� ����:                   " << vit<< "��" << endl;*/

	coord.Y = 19;
	SetConsoleCursorPosition(h, coord);
	printf("�� ������:                 %-3d��\n", atk);
	/*cout << "�� ������:                 " << atk << "��" << endl;*/
	
	coord.Y = 20;
	SetConsoleCursorPosition(h, coord);
	printf("�� ������:                 %-3d��\n",def);
	/*cout << "�� ������:                  " << def << "��" << endl;*/

	coord.Y = 21;
	SetConsoleCursorPosition(h, coord);
	printf("�� ��Ǯ:                 %3d ��\n", money);
	/*cout << "�� ��Ǯ:                  " << money << "��" << endl;*/

	coord.Y = 22;
	SetConsoleCursorPosition(h, coord);
	cout << "�� �������ද������:       " << lv << "����" << endl;
	
	

	coord.Y = 23;
	SetConsoleCursorPosition(h, coord);
	cout << "�� ��������С����:           " << exp << "��" << endl;

	coord.Y = 24;
	SetConsoleCursorPosition(h, coord);
	printf("������������������������������������������������������������\n");
}



