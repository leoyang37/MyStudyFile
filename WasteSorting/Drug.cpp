#include "Drug.h"
#include <iostream>
using namespace std;

Drug::Drug(int ty, int pr,string na, string inr, int adv, int ada, int add)
	:Prop(ty, pr,na, inr, adv, ada, add)
{
}
int Drug::getPrice()
{
	return price;
}

Drug::~Drug()
{
}
//ҩƷ��ʹ��
void Drug::use()
{
	//string name;//����
	//string intro;//����
	//int addVit;//��������
	//int addAtk;//���ӹ�����
	//int addDef;//���ӷ�����
	cout << "Ӣ��ʹ����" << name << endl;
	Player::getPlayer()->setchange(addVit, addAtk, addDef);
    
}
