#include "FrameUI.h"
#include<Windows.h>
#include<iostream>
using namespace std;

using namespace std;
HANDLE h7 = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord7;

FrameUI::FrameUI()
{
}


FrameUI::~FrameUI()
{
}

//句柄:设置绘制坐标(x坐标,y坐标)
void FrameUI::setPositionUI(int fx,int fy)
{
	COORD pos = { fx, fy };
	SetConsoleCursorPosition(h7, pos);
}
//句柄:清理UI(开始坐标x,开始坐标y,结尾坐标x,结尾坐标y)
void FrameUI::clearUI(int startx, int straty, int endx, int endy)
{
	//循环填充空白
	for (int i = startx; i <= endx; i++)
	{
		for (int j = straty; j <= endy; j++)
		{
			COORD pos = { i, j };
			SetConsoleCursorPosition(h7, pos);
			cout << "                                 ";
		}
	}
}