#pragma once
class FrameUI
{
public:
	FrameUI();
	~FrameUI();
	//句柄:设置绘制坐标(x坐标,y坐标)
	static void setPositionUI(int fx, int fy);
	//句柄:清理UI
	static void clearUI(int startx, int straty, int endx, int endy);
};

