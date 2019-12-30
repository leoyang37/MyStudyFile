#include "Bag.h"
#include "Array.h"
#include "Prop.h"
#include"Task.h"


Bag::Bag()//����:һ����̬����
	:pArray(new Array)
{

}

Bag::~Bag()
{
	delete pArray;
	pArray = nullptr;
}

//ʰȡ/�������
void Bag::getProp(Prop* goods)
{
	//����:ʰȡ��Ʒ(���ö�̬�������ӷ���)
	pArray->add(goods);
	//��ʾ���ʰȡ��Ʒ����Ϣ
}


//ʹ�õ���
void Bag::useProp(int index)
{
	Prop* prop = pArray->getProp(index);
	prop->use();//ʹ�÷���:��̬��̬
	pArray->remove(index);
}

//չʾ����
void Bag::showProp()
{
	pArray->show();//���ö�̬�����show����
}

