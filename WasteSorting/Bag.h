#pragma once
class Array;

class Prop;
class Bag
{
public:
	Bag();
	~Bag();
public:
	//1.拾取物品
	void getProp(Prop* Prop);
	//2.使用物品
	void useProp(int index);
	//3.展示物品
	void showProp();

	
private:
	Array* pArray;//背包动态数组
	
};

