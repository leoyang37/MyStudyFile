#pragma once
class Array;

class Prop;
class Bag
{
public:
	Bag();
	~Bag();
public:
	//1.ʰȡ��Ʒ
	void getProp(Prop* Prop);
	//2.ʹ����Ʒ
	void useProp(int index);
	//3.չʾ��Ʒ
	void showProp();

	
private:
	Array* pArray;//������̬����
	
};

