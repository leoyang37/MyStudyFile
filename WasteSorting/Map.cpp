
#include"Player.h"
#include <iostream>
#include"Func\func.h"
#include <Windows.h>
#include<string.h>
#include"FrameUI.h"
using namespace std;

//   0 = 黑色      8 = 灰色
//   1 = 蓝色      9 = 淡蓝色
//   2 = 绿色      A = 淡绿色
//   3 = 浅绿色    B = 淡浅绿色
//   4 = 红色      C = 淡红色
//   5 = 紫色      D = 淡紫色
//   6 = 黄色      E = 淡黄色
//   7 = 白色      F = 亮白色
HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Green SetConsoleTextAttribute(h1, 0x0a) // 绿
#define _Blue SetConsoleTextAttribute(h1, 0x0b) // 浅蓝
#define _Blue2 SetConsoleTextAttribute(h1, 0x09) // 浅蓝
#define _Red SetConsoleTextAttribute(h1, 0x0c) // 红
#define _Purple SetConsoleTextAttribute(h1, 0x0d) // 紫
#define _Yellow SetConsoleTextAttribute(h1, 0x0e) // 黄

#define _Red1 SetConsoleTextAttribute(h1, 0x04) // 暗红
#define _Pink SetConsoleTextAttribute(h1,FOREGROUND_BLUE |FOREGROUND_RED); // 暗红
#define _White SetConsoleTextAttribute(h1, 0x07) // 白
#define _HighWhite SetConsoleTextAttribute(h1, 0x0f); // 亮白色
#define _Gray SetConsoleTextAttribute(h1, 0x08); // 灰色
COORD coord1;

Map::Map(int r, int l, int c)
	:row(r), line(l), customs(c)
{
	//申请内存
	getMemory();
	//给地图初始化
	init();

	
}


Map::~Map()
{
}

//动态申请内存 pMap[row][line]
void Map::getMemory()
{
	pMap = new int*[row];
	for (int i = 0; i < row; i++)
	{
		pMap[i] = new int[line];
	}
}

//获得地图指针
int**Map::getPmap()
{
	return pMap;
}
//获得地图-行
int Map::getRow()
{
	return row;
}
//获得地图-列
int Map::getLine()
{
	return line;
}
//获得地图关卡数
int Map::getCustoms()
{
	return customs;
}
//改变地图关卡数
void Map::setCustoms(int c)
{
	customs = c;
}
//改变关卡
void Map::changeMap(int dir)
{
	//
	int customsCount = customs;
	//定义一个游戏地图
	int gameMap[12][12];
	//将定义的地图一一赋值给游戏地图
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			gameMap[i][j] = pMap[i][j];
		}
	}
	
	//存储文件名的数组
	char filename[40];
	//将后面的字符串输入到一个字符数组中
	sprintf(filename, "Map/GameMap/map_%d.txt", customsCount);
	//保存当前层的地图
	saveFile(gameMap, 12, 12, filename);
	//更改关卡数
	customsCount+=dir;
	//读取下一层的地图
	sprintf(filename, "Map/GameMap/map_%d.txt", customsCount);
	//将更新后的关卡赋值
	customs = customsCount;
	//读取地图
	readFile(gameMap, 12, 12, filename);
	//将游戏地图赋值一一赋值
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			pMap[i][j] = gameMap[i][j];
		}
	}
}
void Map::init()
{
	int map[12][12];
	//将原始地图给游戏地图赋值
	for (int level = 0; level <=2; level++)
	{
		//原始地图数组
		char OriName[40];
		sprintf(OriName, "Map/OriMap/map_%d.txt", level);
		readFile(map, 12, 12, OriName);
		//游戏地图
		char gameName[40];
		sprintf(gameName, "Map/GameMap/map_%d.txt", level);
		saveFile(map, 12, 12, gameName);
	}
	//读取第一关的地图
	readFile(map, 12, 12, "Map/OriMap/map_0.txt");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < line; j++)
		{
			pMap[i][j] = map[i][j];
		}
	}
}

Map::Map(const Map&ref)//深拷贝
	:row(ref.row), line(ref.line)//重新赋值
{
	//重新申请内存
	getMemory();
	//将ref.pMap指向的内容一一拷贝给pMap指向的内存
	for (int i = 0; i < row; i++)
	{
		//参数:目的,源,字节数
		memcpy(pMap[i], ref.pMap[i], sizeof(int)*line);
	}
}

void Map::draw()
{
	cout << endl << endl << endl ;
	//根据 数组 绘制地图
	for (int i = 0; i < row; i++)
	{
		cout << '\t' << '\t' << '\t' << "    ";
		cout << '\t' <<"  ";
		for (int j = 0; j < line; j++)
		{
			switch (pMap[i][j])
			{
			case -6:
				cout << "□";//垃圾分类
				break;
			case 1:
				cout << "■";//外墙
				break;
			case -1:
				_Gray;
				cout << "■";//内墙
				_White;
				break;
			case -3:
				_HighWhite;
				cout << "☆";//商城
				break;
			case -2:
				cout << "⊙";//NPC
				break;
			case 0:
				cout << "  ";
				break;
			case 2:
				cout << "◎";//玩家
				break;
			case 3:
				 cout << "▲"; //上楼
				break;
			case 4:
				 cout << "▼"; //下楼
				break;
			case 20:
				cout << "虾";//小龙虾
				break;
			case 21:
				cout << "茶";//奶茶
				break;
			case 22:
				cout << "臭";//臭豆腐
				break;
			case 23:
				cout << "卤";//卤味
				break;
			case 24:
				cout << "液";//口服液
				break;
			case 25:
				cout << "膏";//软膏
				break;
			case 26:
				cout << "塑";//泡沫塑料
				break;
			case 27:
				cout << "盘";//托盘
				break;
			case 28:
				cout << "土";//尘土
				break;
			case 29:
				cout << "巾";//被污染的毛巾
				break;
				_White;
			
			}	
		}
		cout << endl;
	}
}

//提示菜单
void Map::hintUI()
{
	FrameUI::setPositionUI(20, 25);
	cout << "\t" << " ┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┑" ;
	FrameUI::setPositionUI(20, 26);
	cout << "\t" << " ┆ ↑上 ↓下  ←左  →右                   ┆";
	FrameUI::setPositionUI(20, 27);
	cout << "\t" << " ┆ F存档  G读档  B/b背包  T/t任务  P/p退出 ┆" ;
	FrameUI::setPositionUI(20, 28);
	cout << "\t" << " ┆ Y/y猪学分类法 当前关卡:第" << customs + 1 <<"关            ┆";
	FrameUI::setPositionUI(20, 29);
	cout << "\t" << " ┆ RPG项目答辩:<<垃圾分类大挑战>> 杨凌锋   ┆";
	FrameUI::setPositionUI(20, 30);
	cout << "\t" << " ┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┙"; 





}
