#include "Store.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Player.h"
using namespace std;
HANDLE h2 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Green SetConsoleTextAttribute(h2, 0x0a) // ��
COORD coord2;
Store::Store()
{
}


Store::~Store()
{
}

void Store::showStoreUI()
{
	/*coord2.X = 51;*/
	coord2.X = 33;
	coord2.Y = 3;
	SetConsoleCursorPosition(h2, coord2);
	cout << "����������������������������������������������������������������������������������" << endl;
	

	coord2.Y = 5;
	SetConsoleCursorPosition(h2, coord2);
	cout << "��                                       ��" << endl;

	coord2.Y = 4;
	SetConsoleCursorPosition(h2, coord2);
	cout << "��           ����С��������          ��" << endl;

	coord2.Y = 6;
	SetConsoleCursorPosition(h2, coord2);
	cout << "�� �ٱ�ը��ʵ:����С���汬ը             ��" << endl;
	coord2.Y = 7;
	SetConsoleCursorPosition(h2, coord2);
	cout << "��   �۸�200,����+50,����+50,���ݶ�-80   ��" << endl;

	coord2.Y = 8;
	SetConsoleCursorPosition(h2, coord2);
	cout << "�� �ںɻ�ͼ  :��������ƽ��.              ��" << endl;
	coord2.Y =9;
	SetConsoleCursorPosition(h2, coord2);
	cout << "��   �۸�200,����-50,���ݶ�+80.          ��" << endl;

	coord2.Y = 10;
	SetConsoleCursorPosition(h2, coord2);
	cout << "�� �ۿ��ּӱ� :����������.               ��" << endl;
	coord2.Y = 11;
	SetConsoleCursorPosition(h2, coord2);
	cout << "��   �۸�50,����+25,����+25,���ݶ�+25.   ��" << endl;

	coord2.Y = 12;
	SetConsoleCursorPosition(h2, coord2);
	cout << "�� ���°����� :���ʹ�.                   ��" << endl;
	coord2.Y = 13;
	SetConsoleCursorPosition(h2, coord2);
	cout << "��   �۸�100,������+100.                 ��" << endl;

	coord2.Y = 14;
	SetConsoleCursorPosition(h2, coord2);
	cout << "�� �ݼӺ���¼� :��ú���.               ��" << endl;
	coord2.Y = 15;
	SetConsoleCursorPosition(h2, coord2);
	cout << "��   �۸�12,������+20.                   ��" << endl;

	coord2.Y = 16;
	SetConsoleCursorPosition(h2, coord2);
	cout << "����������������������������������������������������������������������������������" << endl;

}

void Store::purchase()
{
	while (1)
	{
		system("cls");
		showStoreUI();
		cout << "��ѡ�����빺�����Ʒ���" << endl;
		char choice = getchar();

		switch (choice)
		{
		case 'p':case 'P'://�˳�
			return;
			break;
		case '1'://��ը��ʵ
		{
			//��� �۸� ���� ������ ������
			Drug* angryFru = new Drug(1, 200, "��ը��ʵ", "����С���汬ը", 50, 50, -80);
			Player::getPlayer()->bag.getProp(angryFru);
			//�ı���ҽ�Ǯ
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= angryFru->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "����ɹ�!" << endl;
		}
		break;
		case '2'://�ɻ�ͼ
		{
			Drug* lotusPic = new Drug(1, 200, "�ɻ�ͼ", "��������ƽ��", 0, -50, 80);
			Player::getPlayer()->bag.getProp(lotusPic);
			//�ı���ҽ�Ǯ
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= lotusPic->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "����ɹ�!" << endl;
		}

		break;
		case '3'://���ּӱ�
		{
			Drug* iceCola = new Drug(1, 50, "���ּӱ�", "����������", 25, 25, 25);
			Player::getPlayer()->bag.getProp(iceCola);
			//�ı���ҽ�Ǯ
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= iceCola->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "����ɹ�!" << endl;
		}
		break;

		case '4'://�°�����
		{
			Equip* fatCoat = new Equip(2, 100, "�°�����", "���ʹ�", 0, 0, 100);
			Player::getPlayer()->bag.getProp(fatCoat);
			//�ı���ҽ�Ǯ
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= fatCoat->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "����ɹ�!" << endl;
		}
		break;

		case '5'://�Ӻ���¼�
		{
			Equip* coatHanger = new Equip(2, 12, "�Ӻ���¼�", "��ú���", 0, 20, 0);
			Player::getPlayer()->bag.getProp(coatHanger);
			//�ı���ҽ�Ǯ
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= coatHanger->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "����ɹ�!" << endl;
		}
		break;
		

		}
		_getch();
	}
	
	
	

}