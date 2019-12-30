#include<iostream>
#include<conio.h>
#include"func.h"
#include"../Player.h"
#include"../FrameUI.h"
#include"../Map.h"
#include<Windows.h>
using namespace std;
//   6 = 黄色      E = 淡黄色
HANDLE h5 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Gold SetConsoleTextAttribute(h5, 0x06) // 绿
#define _White SetConsoleTextAttribute(h5, 0x07) // 白


using namespace std;
// 保存文件
void saveFile(int(*pMap)[12], int row, int line, char* filename)
{
	//1.打开文件:如果没有该文件,自动创建一个文件
	FILE* pfile = fopen(filename, "wb+");
	//2.写入文件:1.首地址(写入内容的首地址) 2.每一个的大小 3.个数 4.FILE*
	//写入连续内存的内容;
	fwrite(pMap, sizeof(int), row*line, pfile);
	//3.关闭文件
	fclose(pfile);
}
// 读取文件
void readFile(int(*pMap)[12], int row, int line, char* filename)
{
	//1.打开文件
	FILE* pfile = fopen(filename, "rb+");
	//2.读取文件:
	//1.首地址(读取的内容存入内存的首地址)
	//2.每一个的大小
	//3.个数
	//4.FILE*
	fread(pMap, sizeof(int), row*line, pfile);
	//3.关闭文件
	fclose(pfile);
}
void savePlayer(Player* player, char* filename)
{
	//1.打开文件:如果没有该文件,自动创建一个文件
	FILE* pfile = fopen(filename, "wb+");
	//2.写入文件:1.首地址(写入内容的首地址) 2.每一个的大小 3.个数 4.FILE*
	//写入连续内存的内容;
	fwrite(player, sizeof(Player), 1, pfile);
	//3.关闭文件
	fclose(pfile);
}
// 读取文件
void readPlayer(Player* player, char* filename)
{
	//1.打开文件
	FILE* pfile = fopen(filename, "rb+");
	//2.读取文件:
	//1.首地址(读取的内容存入内存的首地址)
	//2.每一个的大小
	//3.个数
	//4.FILE*
	fread(player, sizeof(Player), 1, pfile);
	//3.关闭文件
	fclose(pfile);
}

void savePlayerFile(Player*player, char* filename)
{
	//1.打开文件:如果没有该文件,自动创建一个文件
	FILE* pfile = fopen(filename, "wb+");
	//2.写入文件:1.首地址(写入内容的首地址) 2.每一个的大小 3.个数 4.FILE*
	//写入连续内存的内容;
	fwrite(player, sizeof(int), 1, pfile);
	//3.关闭文件
	fclose(pfile);

}

void readPlayerFile(Player*player, char* filename)
{
	//1.打开文件
	FILE* pfile = fopen(filename, "rb+");
	//2.读取文件:
	//1.首地址(读取的内容存入内存的首地址)
	//2.每一个的大小
	//3.个数
	//4.FILE*
	fread(player, sizeof(int), 1, pfile);
	//3.关闭文件
	fclose(pfile);
}
//存储地图信息
void saveMapFile(int** pMap, int row, int line, char* filename)
{
	//1.打开文件:如果没有该文件,自动创建一个文件
	FILE* pfile = fopen(filename, "wb+");
	for (int i=0; i < row; i++)
	{
		//2.写入文件:1.首地址(写入内容的首地址) 2.每一个的大小 3.个数 4.FILE*
		//写入连续内存的内容;
		fwrite(pMap[i], sizeof(int), line, pfile);
	}
	//3.关闭文件
	fclose(pfile);
}
//读取地图信息
void readMapFile(int** pMap, int row, int line, char* filename)
{
	//1.打开文件
	FILE* pfile = fopen(filename, "rb+");
	for (int i = 0; i < row; i++)
	{
		//2.读取文件:
		//1.首地址(读取的内容存入内存的首地址)
		//2.每一个的大小
		//3.个数
		//4.FILE*
		fread(pMap[i], sizeof(int), line, pfile);
	}
	//3.关闭文件
	fclose(pfile);
}
//保存关卡数
void saveCustoms(int cust,char* filename)
{
	//1.打开文件:如果没有该文件,自动创建一个文件
	FILE* pfile = fopen(filename, "wb+");
    //2.写入文件:1.首地址(写入内容的首地址) 2.每一个的大小 3.个数 4.FILE*
	//写入连续内存的内容;
	fwrite(&cust, sizeof(int), 1, pfile);
	//3.关闭文件
	fclose(pfile);
}
//读取关卡数
void readCustoms(int cust, char* filename)
{
	//1.打开文件
	FILE* pfile = fopen(filename, "rb+");
	//2.读取文件:
	//1.首地址(读取的内容存入内存的首地址)
	//2.每一个的大小
	//3.个数
	//4.FILE*
	fread(&cust, sizeof(int), 1, pfile);
	//3.关闭文件
	fclose(pfile);
}

// 渲染主界面
void menuUI(int(*p)[20])
{
	
	for (int i = 0; i < 16; i++)
	{
		cout << "\t";
		for (int j = 0; j < 20; j++)
		{
			switch (p[i][j])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "●";
				break;
			case 2:
				cout << "<<垃圾分类大挑战>>";
				break;
			case 3:
				cout << "开始游戏    ";
				break;
			case 4:
				 cout << "游戏介绍    ";
				break;
			case 7:
				cout << "◎";
				break;
			case 8:
				cout << "退出游戏    ";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "\t" << " ┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┑" << endl;
	cout << "\t" << " ┆    ↑上移    ↓下移    回车选择  ┆" << endl;
	cout << "\t" << " ┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┙" << endl; 
}
// 主界面的选择活动
void menuAction(int(*p)[20], int size) // 数组 行数 上下移动的值
{
	for (int i = 8; i <= 12; i += 2)
	{
		if (7 == p[i][6]) // 遍历数组找到选择的图标
		{
			if (((8 == i) && (size < 0)) || ((12 == i) && (size > 0)))
			{
				p[i][6] = 0;
				p[i - 2 * size][6] = 7;
				break; // 改变指向后后跳出循环
			}
			else
			{
				p[i][6] = 0;
				p[i + size][6] = 7;
				break; // 改变指向后后跳出循环
			}
		}
	}
}

void menu()
{
	// 主界面地图
	int menuUIMap[16][20] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 2, 0, 0, 0, 9,9, 9, 9, 9, 9, 9, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 7, 3, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	do
	{
		// 主界面
		int size; // 上下移动的格数
		bool start = false; // 循环条件
		do
		{
			system("cls");
			menuUI(menuUIMap); // 渲染主界面地图
			char action1 = getch(); // 获取输入的字符
			switch (action1)
			{
			case 72:  // 上移两格
				size = -2;
				menuAction(menuUIMap, size);
				break;
			case 80: // 下移两格
				size = 2;
				menuAction(menuUIMap, size);
				break;
			case 13:
				if (7 == menuUIMap[8][6]) // 开始游戏
				{
					return;
				}
				else if (7 == menuUIMap[10][6]) // 游戏介绍
				{
					gameInfoUI();
				}
				else if (7 == menuUIMap[12][6]) // 退出游戏
				{
					exit(1);
				}
				start = true;
				break;
			}
		} while (!start);
	} while (1);

}

void gameInfoUI()
{
	FrameUI::setPositionUI(3, 20);
	cout << "\t" << " ┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┑";
	FrameUI::setPositionUI(3, 21);
	_Gold;
	cout << "\t" << "  ☆游戏介绍:    ";
	_White;
	FrameUI::setPositionUI(3, 22);
	cout << "\t" << "  一、简介：把不愿意垃圾分类的人打败,把他们的垃圾拿去分类。"; 
	FrameUI::setPositionUI(3, 23);
	cout << "\t" << "  二、胜利：将所有任务完成，挑战成功。 ";
	FrameUI::setPositionUI(3, 24);
	cout << "\t" << "  三、失败：①分类失败将会收取罚金，当玩家金币<=0时，挑战失败                         ";
	FrameUI::setPositionUI(3, 25);
	cout << "\t" << "            ②垃圾分类是个体力活，当玩家体力值<=0，挑战失败 ";
	FrameUI::setPositionUI(3, 26);
	cout << "\t" << "  四、其他： ①当垃圾分类经验>=100时候:";
	FrameUI::setPositionUI(3, 27);
	cout << "\t" << "             可以去垃圾桶处进行升级，将提升玩家体力值，攻击值，防御值。";
	FrameUI::setPositionUI(3, 28);
	cout << "\t" << "             可以根据自身需求:";
	FrameUI::setPositionUI(3, 29);
	cout << "\t" << "             在超市购买水果吃，购买美术作品提升内在修养和购买小商品改变体力值，攻击值，防御值。";
	FrameUI::setPositionUI(3, 30);
	cout << "\t" << " ┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┙";
	_getch();
}

//猪学分类法
void tipsUI()
{
	FrameUI::setPositionUI(60, 5);
	cout << "\t" << " ┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┑";
	FrameUI::setPositionUI(60, 6);
	_Gold;
	cout << "\t" << "  ☆猪学分类法:    ";
	_White;
	FrameUI::setPositionUI(60, 7);
	cout << "\t" << "  ①猪能吃的是湿垃圾垃圾";
	FrameUI::setPositionUI(60, 8);
	cout << "\t" << "  ②猪不能吃的是干垃圾 ";
	FrameUI::setPositionUI(60, 9);
	cout << "\t" << "  ③猪吃了会死的是有害垃圾                         ";
	FrameUI::setPositionUI(60, 10);
	cout << "\t" << "  ④卖了能换猪的是可回收垃圾 ";
	FrameUI::setPositionUI(60, 11);
	cout << "\t" << "  但出门不能牵头猪";
	FrameUI::setPositionUI(60, 12);
	cout << "\t" << " ┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┙";
	_getch();
}