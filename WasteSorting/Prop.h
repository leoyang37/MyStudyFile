#pragma once
#include <string>
using namespace std;
//Prop:�������̳ǵ���
class Prop
{
public:
	Prop();
	Prop(int ty,int pr,string n, string in, int av , int aa , int ad );
	~Prop();
public:
	virtual void use() = 0;//ʹ��//use:���麯��
	void show();//չʾ
protected:
	int type;
	int price;
	string name;//����
	string intro;//����
	int addVit;//��������
	int addAtk;//���ӹ�����
	int addDef;//���ӷ�����
};

