#pragma once
class DrawUI
{
public:
	static DrawUI& getUI()
	{
		static DrawUI ui;
		return ui;
	}
	int getOrder();
	void drawBoarder();
	void clearBoarder(int startX,int startY,int endX,int endY);
	void SetPosition2(int x, int y, const char* n, int line = 0);
	void strBoarder(int startX, int startY,const char* str,int maxsize = 120);
	~DrawUI();
private:
	DrawUI();
};

