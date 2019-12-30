#pragma once
//默认大小
const int defaultRow = 12;
const int defaultLine = 12;
class Map
{
public:
	Map(int r = defaultRow, int l = defaultLine, int customs=0);
	Map(const Map&ref);//深拷贝
	~Map();
public:
	void getMemory();//动态申请内存
	void init();//初始化
	void draw();//绘制
	int**getPmap();//得到地图指针
	int getRow();//得到行
	int getLine();//得到列
	int getCustoms();//获得关卡
	void setCustoms(int c);//设置关卡
	void hintUI();//提示UI+关卡信息
	void changeMap(int dir);//上下楼
private:
	int row;//行
	int line;//列
	int**pMap;
	int customs;//关卡

};

