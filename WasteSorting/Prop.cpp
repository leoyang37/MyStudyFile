#include "Prop.h"
#include <iostream>
using namespace std;
Prop::Prop()
{
}
Prop::Prop(int ty, int pr,string n, string in, int av, int aa, int ad)
	: type(ty),
	price(pr),
	name(n),
	intro(in),
	addVit(av),
	addAtk(aa),
	addDef(ad)
{
}


Prop::~Prop()
{
}

void Prop::show()
{
	//string name;//����
	//string intro;//����
	//int addVit;//��������
	//int addAtk;//���ӹ�����
	//int addDef;//���ӷ�����
	cout << "*********** *********" << endl;
	cout << "��Ʒ����:" << name << endl;
	cout << "��Ʒ����:" << intro << endl;
	cout << "��Ʒ������:" << addVit << endl;
	cout << "��Ʒ�ӹ�����:" << addAtk << endl;
	cout << "��Ʒ�ӷ�����:" << addDef << endl;
	cout << "*************************" << endl;

}
