#pragma once
class Prop;
/*
Array:��Ʒ��̬����
*/
const int defaultSize = 6;//Ĭ�ϴ�С
class Array
{
public:
	Array(int size = defaultSize);
	Array(const Array& ref);
	~Array();
	//���
	void add(Prop* Prop);
	//ɾ��
	void remove(int index)
	{
	}
	//����
	void show();
	//����(����)
	void sort();
	//ͨ���±��ȡ����
	Prop* getProp(int index)
	{
		return pData[index];
	}
private:
	bool isFull() const;//�ж��Ƿ�����
	void resize();//����
private:
	Prop** pData;//�����ڵ�Ԫ��ΪProp*,ÿһ��Ԫ��ָ�������Prop
	int size;//��Ÿ���
	int maxSize;//������С
};

