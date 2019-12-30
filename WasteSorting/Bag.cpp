#include "Bag.h"
#include "Array.h"
#include "Prop.h"
#include"Task.h"


Bag::Bag()//背包:一个动态数组
	:pArray(new Array)
{

}

Bag::~Bag()
{
	delete pArray;
	pArray = nullptr;
}

//拾取/购买道具
void Bag::getProp(Prop* goods)
{
	//背包:拾取物品(调用动态数组的添加方法)
	pArray->add(goods);
	//提示玩家拾取物品的信息
}


//使用道具
void Bag::useProp(int index)
{
	Prop* prop = pArray->getProp(index);
	prop->use();//使用方法:动态多态
	pArray->remove(index);
}

//展示道具
void Bag::showProp()
{
	pArray->show();//调用动态数组的show方法
}

