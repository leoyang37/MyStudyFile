#pragma once
class FrameUI
{
public:
	FrameUI();
	~FrameUI();
	//���:���û�������(x����,y����)
	static void setPositionUI(int fx, int fy);
	//���:����UI
	static void clearUI(int startx, int straty, int endx, int endy);
};

