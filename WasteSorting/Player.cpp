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
#define _Green SetConsoleTextAttribute(h, 0x0a) // 绿
#define _Blue SetConsoleTextAttribute(h, 0x0b) // 浅蓝
#define _Blue2 SetConsoleTextAttribute(h, 0x09) // 浅蓝
#define _Red SetConsoleTextAttribute(h, 0x0c) // 红
#define _Purple SetConsoleTextAttribute(h, 0x0d) // 紫
#define _Yellow SetConsoleTextAttribute(h, 0x0e) // 黄
#define _White SetConsoleTextAttribute(h, 0x07) // 白
#define _Red1 SetConsoleTextAttribute(h, 0x04) // 暗红
COORD coord;
Map map;

Player*Player::pPlayer = nullptr;//静态变量,只能类外初始化

//添加任务
void Player::takeTask(Task* task)
{
	pArrayT->takeTask(task);

}

//展示任务
void Player::showTask()
{
	pArrayT->show();//调用动态数组的show方法
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
	if (nullptr == pPlayer)//判断pPlayer是否为空
	{
		pPlayer = new Player;//为空,创建一个对象
	}
	return pPlayer;//不为空,返回地址
}

void Player::setPos(int x, int y)
{
	posX = x;
	posY = y;
}
void  Player::lvUpgrade()
{
	FrameUI::setPositionUI(0, 0);
	cout << "是否选择升级?升级请输入1,退出请输入p/P" << endl;
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
		cout << "输入不合法,请按提示输入内容." << endl;
		_getch();		
		break;
	}

}

//寻找玩家位置
void Player::findPlayer(Map&map)
{
	//获取地图的pMap
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
	//string name;//名字
	
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

	//先获取按键
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
		tipsUI();//猪学分类法
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
		cout << "存档成功!" << endl;
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
		cout << "读档成功!" << endl;
		_getch();
		break;
		
	}
	//获取地图的pMap
	int** pMap = map.getPmap();
	//在游戏区内
	if (posX + offsetX >= 0 && posX + offsetX < map.getRow() && posY + offsetY >= 0 && posY + offsetY < map.getLine())
	{
		//前面是空地
		if (0 == pMap[posX + offsetX][posY + offsetY])
		{
			pMap[posX + offsetX][posY + offsetY] = 2;
			pMap[posX][posY] = 0;
			posX += offsetX;
			posY += offsetY;
		}
		//前面是NPC //任务界面
		else if (-2 == pMap[posX + offsetX][posY + offsetY])
		{
			task.taskUI();
			task.taskChoice();
			
		}
		//前面是上楼
		else if (3 == pMap[posX + offsetX][posY + offsetY])
		{
			int dir = 1;
			map.changeMap(dir);
		}
		//前面是下楼
		else if (4 == pMap[posX + offsetX][posY + offsetY])
		{
			int dir = -1;
			map.changeMap(dir);
		}
		//前面是商城 //买道具商品
		else if (-3 == pMap[posX + offsetX][posY + offsetY])
		{
			store.purchase();
		}
		//前面是垃圾桶
		else if (-6 == pMap[posX + offsetX][posY + offsetY])
		{
			lvUpgrade();
		}
		//前面是对手  //拾取垃圾
		else if (pMap[posX + offsetX][posY + offsetY] >= 20 && pMap[posX + offsetX][posY + offsetY]<30)
		{
			//pkFlag:是否PK的标记
			//winFlag:PK是否胜利
			int pkFlag = 1,winFlag=1;
			//动态生成不分类垃圾的人
			rival.pk(pMap[posX + offsetX][posY + offsetY]-20,pkFlag,winFlag);
			//PK胜利
			if (1 == winFlag)
			{
				pMap[posX + offsetX][posY + offsetY] = 2;
				pMap[posX][posY] = 0;
				posX += offsetX;
				posY += offsetY;
				//如果分类正确
				if (true == rival.sortingJudge())
				{
					//判断分类是否符合任务要求	
					//遍历任务数组 i<任务数
					for (int i = 0; i < pArrayT->getSize(); i++)
					{
						//查找玩家是否接受 "小试牛刀"任务
						if (0==(pArrayT[i].getTask(i).compare("小试牛刀")))
						{
							//实时更改"任务栏-待完成次数"
							//1.有害垃圾
							//计算方式:  已分类的垃圾-任务要求的垃圾 //值>0取0,<0保持不变
							int temp1 = (rival.sHaCount-pArrayT[i].getHaCount(i) >= 0) ? 0 : pArrayT[i].getHaCount(i);
							pArrayT[i].setHaCount(temp1,i);

							//2.可回收垃圾
							int temp2 = (rival.sReCount - pArrayT[i].getReCount(i) >= 0) ? 0 : pArrayT[i].getReCount(i);
							pArrayT[i].setReCount(temp2, i);

							//3.湿垃圾
							int temp3 = (rival.sHFCount - pArrayT[i].getHFCount(i) >= 0) ? 0 : pArrayT[i].getHFCount(i);
							pArrayT[i].setHFCount(temp3, i);

							//4.干垃圾
							int temp4 = (rival.sRiCount - pArrayT[i].getRiCount(i) >= 0) ? 0 : pArrayT[i].getRiCount(i);
							pArrayT[i].setRiCount(temp4, i);
							
							//判断是否达到任务要求
							if (pArrayT[i].getHaCount(i) ==0&& pArrayT[i].getHFCount(i) ==0
								&& pArrayT[i].getReCount(i)==0 && pArrayT[i].getRiCount(i)==0)
							{
								//修改任务的状态(完成度,状态)
								pArrayT[i].setState(DONE, i);
							}
							break;
						}
						//查找是否有 "入冬失败"任务
						 if (0 == (pArrayT[i].getTask(i).compare("入冬失败")))
						{
							int temp3 = (rival.sHFCount - pArrayT[i].getHFCount(i) >= 0) ? 0 : pArrayT[i].getHFCount(i);
							pArrayT[i].setHFCount(temp3, i);

			
							//判断是否达到任务要求
							if (0 == pArrayT[i].getHFCount(i))
							{
								//修改任务的状态(完成度,状态)
								pArrayT[i].setState(DONE, i);
							}
							break;
						}
						//查找是否有 "分类大师"任务
						 if (0 == (pArrayT[i].getTask(i).compare("分类大师")))
						{
							//判断是否达到任务要求
							if (task.isAllDone(map))
							{
								//修改任务的状态(完成度,状态)
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
	printf("┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┑\n");

	coord.Y = 16;
	SetConsoleCursorPosition(h, coord);
	cout << "┆  垃圾分类排位赛-玩家属性   ┆" << endl;

	coord.Y = 17;
	SetConsoleCursorPosition(h, coord);
	cout << "┆                            ┆" << endl;
	
	
	
	
	coord.Y = 18;
	SetConsoleCursorPosition(h, coord);
	printf("┆ 体力:                   %-3d┆\n", vit);
	/*cout << "┆ 体力:                   " << vit<< "┆" << endl;*/

	coord.Y = 19;
	SetConsoleCursorPosition(h, coord);
	printf("┆ 攻击力:                 %-3d┆\n", atk);
	/*cout << "┆ 攻击力:                 " << atk << "┆" << endl;*/
	
	coord.Y = 20;
	SetConsoleCursorPosition(h, coord);
	printf("┆ 防御力:                 %-3d┆\n",def);
	/*cout << "┆ 防御力:                  " << def << "┆" << endl;*/

	coord.Y = 21;
	SetConsoleCursorPosition(h, coord);
	printf("┆ 金钱:                 %3d ┆\n", money);
	/*cout << "┆ 金钱:                  " << money << "┆" << endl;*/

	coord.Y = 22;
	SetConsoleCursorPosition(h, coord);
	cout << "┆ 垃圾分类动手能力:       " << lv << "级┆" << endl;
	
	

	coord.Y = 23;
	SetConsoleCursorPosition(h, coord);
	cout << "┆ 垃圾分类小经验:           " << exp << "┆" << endl;

	coord.Y = 24;
	SetConsoleCursorPosition(h, coord);
	printf("┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┙\n");
}



