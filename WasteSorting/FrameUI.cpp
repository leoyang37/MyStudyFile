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

//���:���û�������(x����,y����)
void FrameUI::setPositionUI(int fx,int fy)
{
	COORD pos = { fx, fy };
	SetConsoleCursorPosition(h7, pos);
}
//���:����UI(��ʼ����x,��ʼ����y,��β����x,��β����y)
void FrameUI::clearUI(int startx, int straty, int endx, int endy)
{
	//ѭ�����հ�
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