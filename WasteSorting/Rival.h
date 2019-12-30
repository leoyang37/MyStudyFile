#pragma once
#include<string>
#include"Map.h"
using namespace std;
enum WasteSorting
{
	HaWaste,//�к�����Hazardous Waste
	ReWaste,//�ɻ�������Recyclable Waste
	HFWaste,//ʪ����Household Food Waste
	RiWaste //������Residual Waste
};
class Rival
{
public:
	
	Rival();
	void initRivalCount();
	~Rival();
	//��ʼ��
	void initRival(string rn, string fn,int rv, int ra, int rd, int rf,int re, WasteSorting rws);
	//pk����
	void pk(int index,int& pkFlag,int& winFlag);
	//ʧ�ܽ���
	void failedUI();
	//��̬�����������������
	Rival*creatRival(int index);
	//�жϷ����Ƿ���ȷ
	bool sortingJudge();
public:
	string getRivalName()
	{
		return name;
	}
	int sHaCount;//�к�����
	int sReCount;//�ɻ�������
	int sHFCount;//ʪ����
	int sRiCount;//������
private:
	string name;//����
	string foodName;//ʳ������
	int vit;//����ֵ
	int atk;//������
	int def;//������
	int fine;//����
	int exp;//����
	int posx;
	int posy;
	WasteSorting ws;


};

