#pragma once
//Ĭ�ϴ�С
const int defaultRow = 12;
const int defaultLine = 12;
class Map
{
public:
	Map(int r = defaultRow, int l = defaultLine, int customs=0);
	Map(const Map&ref);//���
	~Map();
public:
	void getMemory();//��̬�����ڴ�
	void init();//��ʼ��
	void draw();//����
	int**getPmap();//�õ���ͼָ��
	int getRow();//�õ���
	int getLine();//�õ���
	int getCustoms();//��ùؿ�
	void setCustoms(int c);//���ùؿ�
	void hintUI();//��ʾUI+�ؿ���Ϣ
	void changeMap(int dir);//����¥
private:
	int row;//��
	int line;//��
	int**pMap;
	int customs;//�ؿ�

};

