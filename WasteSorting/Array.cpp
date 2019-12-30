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
	//���������ڴ�
	//��ref.pDataָ������ݿ�����pData��
	memcpy(pData, ref.pData, sizeof(Prop*) * size);
}

Array::~Array()
{
	//�ͷ��ڴ�
	delete[] pData;
	//ָ���ÿ�
	pData = nullptr;
}

void Array::add(Prop* Prop)
{
	if (isFull())//�����
	{
		resize();//����
	}
	//���Ԫ��
	pData[size] = Prop;
	size++;
}


bool Array::isFull() const
{
	return size == maxSize;
}

void Array::resize()
{
	//1.����ԭ�ȴ�С2�����ڴ�,����ָ�뱣��
	Prop** pNew = new Prop*[maxSize * 2];
	//2.�����ڴ��е����ݿ��������ڴ���
	memcpy(pNew, pData, sizeof(Prop*) * size);
	//3.�ͷž��ڴ�
	delete[] pData;
	//4.pDataָ�����ڴ�
	pData = pNew;
	//5.maxSize*=2;
	maxSize *= 2;
}

//����
void Array::show()
{
	
	cout << "ѡ����Ž���ʹ��,����P/p�رձ���" << endl;
	//չʾ��Ʒ
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << endl;
		pData[i]->show();//ÿһ����Ʒ��show����
		cout << endl;
	}
	//������Ʒ
	char useInBag = _getch();
	for (int i = 0; i < size; i++)
	{
		if (0 == useInBag - '0' -1- i)
		{
			pData[i]->use();
			//ɾ����Ʒ
			int k = i;
			for (; k <= size-1; k++)
			{
				pData[k] = pData[k + 1];
			}
			size--;
		}
	}
	
	
	
	
}
