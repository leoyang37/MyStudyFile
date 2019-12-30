#include "Array.h"
#include "Prop.h"
#include <string.h>
#include<conio.h>
#include <windows.h>
#include<iostream>
using namespace std;

Array::Array(int _size)
	:size(0),
	maxSize(_size),
	pData(new Prop*[_size])
{
}

Array::Array(const Array& ref)
	:size(ref.size),
	maxSize(ref.maxSize),
	pData(new Prop*[maxSize])
{
	//重新申请内存
	//将ref.pData指向的内容拷贝到pData中
	memcpy(pData, ref.pData, sizeof(Prop*) * size);
}

Array::~Array()
{
	//释放内存
	delete[] pData;
	//指针置空
	pData = nullptr;
}

void Array::add(Prop* Prop)
{
	if (isFull())//如果满
	{
		resize();//扩容
	}
	//添加元素
	pData[size] = Prop;
	size++;
}


bool Array::isFull() const
{
	return size == maxSize;
}

void Array::resize()
{
	//1.申请原先大小2倍的内存,用新指针保存
	Prop** pNew = new Prop*[maxSize * 2];
	//2.将旧内存中的内容拷贝到新内存中
	memcpy(pNew, pData, sizeof(Prop*) * size);
	//3.释放旧内存
	delete[] pData;
	//4.pData指向新内存
	pData = pNew;
	//5.maxSize*=2;
	maxSize *= 2;
}

//遍历
void Array::show()
{
	
	cout << "选择序号进行使用,输入P/p关闭背包" << endl;
	//展示物品
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << endl;
		pData[i]->show();//每一个物品的show方法
		cout << endl;
	}
	//操作物品
	char useInBag = _getch();
	for (int i = 0; i < size; i++)
	{
		if (0 == useInBag - '0' -1- i)
		{
			pData[i]->use();
			//删除物品
			int k = i;
			for (; k <= size-1; k++)
			{
				pData[k] = pData[k + 1];
			}
			size--;
		}
	}
	
	
	
	
}
