#include "Equip.h"
#include <iostream>
using namespace std;

Equip::Equip(int ty, int pr, string na, string inr, int adv , int ada, int add )
	:Prop(ty, pr, na, inr, adv, ada, add)
{
}


Equip::~Equip()
{
}
int Equip::getPrice()
{
	return price;
}
//װ����ʹ��
void Equip::use()
{
	cout << "Ӣ�۴�����" << name << endl;
	Player::getPlayer()->setchange(addVit, addAtk, addDef);
	
}