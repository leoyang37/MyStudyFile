#pragma once
#include"Map.h"
#include"Store.h"
#include<string>
#include"Bag.h"
#include"Rival.h"
#include"Task.h"
#include"ArrayTask.h"
class Task;
class Store;
using namespace std;
//���������
class Player
{
public:
	static Player*getPlayer();//��̬����:��������
	~Player();
private:
	Player();
	static Player*pPlayer;//���徲ָ̬��,��¼�����ַ

public:
	void initPlayer();
	void findPlayer(Map&map);//Ѱ�����λ��
	void movePlayer(Map& map, Store store,Rival rival,Task task);//����ƶ�����
	void playerUI();
	void readPlayer();//��ȡ�����Ϣ
	void savePlayer();//���������Ϣ
public:
	void setPos(int x, int y);//�������λ��
	//��ȡ��Ǯ �ı��Ǯ
	int getMoney();
	void setMoney(int mon);
	//�����������ྭ�� �ж��Ƿ�����
	void addExp(int ex)
	{
		exp += ex;
		//���>200��������� ����ǿ��
		if (exp >= 200)
		{
			exp -= 200;
			lv++;
			vit += 25;
			atk += 25;
			def += 25;
		}
	}
	//��ȡ���� �ı�����
	int getVit()
	{
		return vit;
	}
	void setVit(int v)
	{
		vit = v;
	}
	//��ȡ������
	int getAtk()
	{
		return atk;
	}
	//��ȡ������
	int getDef()
	{
		return def;
	}
	//ʹ��ʳ��/װ���ı�Ӣ������
	void setchange(int l,int a,int d)
	{
		vit += l;
		atk += a;
		def += d;
	}
	Bag bag;//��ұ���
	ArrayTask* pArrayT;//����̬����
public:
	
	//1.��������
	void takeTask(Task* Task);
	//2.չʾ����
	void showTask();
	//3.�����������
	string getTaskName(Task* task);
	//4.�������
	void lvUpgrade();
private:
	string name;//����
	int lv;//�ȼ�
	int vit;//����ֵ
	int atk;//������
	int def;//������
	int money;//��Ǯ
	int exp;//����
	int posX;//�������
	int posY;
	

};

