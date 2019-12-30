#include "DrawUI.h"
#include<conio.h>
#include<Windows.h>
#include<iostream>
using namespace std;
#define Cyan_ SetConsoleTextAttribute(h8, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define White_ SetConsoleTextAttribute(h8, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define Green_ SetConsoleTextAttribute(h8, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define Yellow_ SetConsoleTextAttribute(h8, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define Purple_ SetConsoleTextAttribute(h8, FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_INTENSITY);
#define Red_ SetConsoleTextAttribute(h8, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define None_ SetConsoleTextAttribute(h8,FOREGROUND_INTENSITY);
#define Blue_ SetConsoleTextAttribute(h8, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#define BigYellow_ SetConsoleTextAttribute(h8, FOREGROUND_RED | FOREGROUND_GREEN);
#define BgYellow_ SetConsoleTextAttribute(h8,/*BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY |*/ FOREGROUND_RED /*| FOREGROUND_GREEN | FOREGROUND_INTENSITY*/);
#define BgBlack_ SetConsoleTextAttribute(h8);
#define Grey_ SetConsoleTextAttribute(h8, FOREGROUND_INTENSITY);
#define NoneBorder_ SetConsoleTextAttribute(h8,0x00);

#define borderSytle_ SetConsoleTextAttribute(h8, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//边框颜色
#define textStyle_ SetConsoleTextAttribute(h8, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//文本颜色

HANDLE h8 = GetStdHandle(STD_OUTPUT_HANDLE);



DrawUI::DrawUI()
{
}


DrawUI::~DrawUI()
{
}
int DrawUI::getOrder()
{
	char order[10];
	int length = 0;
	bool flag = true;
	/*cout << "请输入要提交的选项，按0退出  ";*/
	order[length] = _getch();
	flag = (order[length] == '0');
	while (order[length] != '\r' && !flag)
	{
		Red_
			cout << order[length];
		if (order[length] > '9' || order[length] < '0')
		{

			Cyan_
				SetPosition2(50-17, 28, "■■■■■■■■■■■■■■■■■■■■■■");
			SetPosition2(50 - 17, 29, "■");
			SetPosition2(92 - 17, 29, "■");
			SetPosition2(50 - 17, 30, "■");
			BigYellow_
				cout << "输入中有非法字符请重新输入,按0退出      ";
			Cyan_
				SetPosition2(92 - 17, 30, "■");
			SetPosition2(50 - 17, 31, "■");
			SetPosition2(92 - 17, 31, "■");
			Cyan_
				SetPosition2(50 - 17, 32, "■■■■■■■■■■■■■■■■■■■■■■");
			BigYellow_
				SetPosition2(52 - 17, 31, "                                      ");
			SetPosition2(52 - 17, 31, "");
			length = 0;
		}
		else
		{
			length++;
		}
		if (length >= 9)
		{
			length = 0;
			cout << "输入的数过大";
			BigYellow_
				SetPosition2(52 - 17, 31, "                                      ");
			SetPosition2(52 - 17, 31, "");
		}
		order[length] = _getch();
	}
	White_
	return atoi(order);
}
void DrawUI::drawBoarder()
{
	int clientX = 0;
	int clientY = 0;
	None_
		SetPosition2(0, 0, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	for (int i = 0; i < 34; i++)
	{
		SetPosition2(0, i, "■");
		SetPosition2(26, i, "■");
		SetPosition2(80, i, "■");
		SetPosition2(116, i, "■");
	}
	SetPosition2(0, 34, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	for (int i = 0; i < 80; i+=2)
	{
		SetPosition2(i, 25, "■");
	}
	Blue_
	SetPosition2(8, 27, "WASD移动");
	SetPosition2(8, 29, "R打开任务栏");
	SetPosition2(3, 31, "I打开背包 回车确认选项");
	SetPosition2(8, 33, "O存档 P读档");
	White_
}
void DrawUI::clearBoarder(int startX, int startY, int endX, int endY)
{
	for (int i = startY; i < endY; i++)
	{
		
		for (int j = startX; j < endX; j++)
			SetPosition2(j, i, " ");
	}
}

void DrawUI::strBoarder(int startX, int startY, const char* str,int maxsize)
{
	int length = strlen(str);
	char a[3] = "◆";//边框样式
	int size = length / maxsize;
	char* text = new char[maxsize+1];
	length%maxsize != 0 ? size++ : 0;
	int last = 2 + size;
	clearBoarder(startX, startY, startX + length, startY + 5);
	for (int i = startY; i < startY+5; i++)
	{
		borderSytle_
		SetPosition2(startX, i, "");
		if (i == startY + 2)
		{
			for (int j = 0; j < size; j++)
			{
				memcpy(text, str + j * maxsize,length>maxsize*j?maxsize:maxsize*j-length);
				text[maxsize] = '\0';
				borderSytle_
				SetPosition2(startX, i+j, "");
				cout << a << "";//文字左边边框
				textStyle_
				SetPosition2(startX + 4, i+j, "");
				cout << text;
				borderSytle_
				SetPosition2(startX + (maxsize > length ? length : maxsize) + 6, i+j, "");
				cout << a;//文字右边边框
			}

		}
		for (int j = 0; j < 4 + (maxsize>length?length:maxsize)/2; j++)
		{
			if (!(i != startY + 1 || i != startY + 4 || i!= startY+3 || i != startY))
			{
				break;
			}
			if (i == startY)
			{
				cout << a;
			}
			else if (i == startY + 4)
			{
				SetPosition2(startX+(j*2), startY+last+1, "");
				cout << a;
			}
			else if (i == startY+1)
			{

				if (j == 0 || j == 4 + (maxsize > length ? length : maxsize) / 2 - 1)
				{

					SetPosition2(startX + (j * 2), startY + 1, "");
					cout << a;
				}
				else
				{
					cout << "  ";
				}
			}
			else if(i == startY+3)
			{
				if (j == 0 || j == 4 + (maxsize > length ? length : maxsize) / 2 - 1)
				{

					SetPosition2(startX + (j * 2), startY + last, "");
					cout << a;
				}
				else
				{
					cout << "  ";
				}
			}
		}
	}
	SetPosition2(startX, startY + 5, "");
	White_
}
void DrawUI::SetPosition2(int x, int y, const char* n, int line)
//在指定地方输出字符串
//n表示要在指定位置输出的字符串
//line表示清除行数，默认为0
{
	int length = strlen(n);
	if (line >= 0)
	{
		clearBoarder(x, y, length + x, line + y);//预先清除位置给目标
	}
	HANDLE winHandle;//句柄
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置 
	SetConsoleCursorPosition(winHandle, pos);

	cout << n;
}