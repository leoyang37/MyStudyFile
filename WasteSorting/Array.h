#pragma once
class Prop;
/*
Array:物品动态数组
*/
const int defaultSize = 6;//默认大小
class Array
{
public:
	Array(int size = defaultSize);
	Array(const Array& ref);
	~Array();
	//添加
	void add(Prop* Prop);
	//删除
	void remove(int index)
	{
	}
	//遍历
	void show();
	//排序(整理)
	void sort();
	//通过下标获取道具
	Prop* getProp(int index)
	{
		return pData[index];
	}
private:
	bool isFull() const;//判断是否满了
	void resize();//扩容
private:
	Prop** pData;//数组内的元素为Prop*,每一个元素指向堆区的Prop
	int size;//存放个数
	int maxSize;//容器大小
};

