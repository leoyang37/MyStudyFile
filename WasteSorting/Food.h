#pragma once
#include<string>
using namespace std;
class Food
{
public:
	Food();
	~Food();
	//virtual void eat();//不同吃法
private:
	string name;//食物名
	int vol;//占胃的毫升
	int cal;//卡路里
	int punDe;//辣度 //减少胃容量
	int iceDe;//冰度 //减少胃容量
	int price;//价格
	int exp;//成长值 
};

