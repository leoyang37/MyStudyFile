#include "Store.h"
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Player.h"
using namespace std;
HANDLE h2 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Green SetConsoleTextAttribute(h2, 0x0a) // 绿
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
	cout << "┍┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┑" << endl;
	

	coord2.Y = 5;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆                                       ┆" << endl;

	coord2.Y = 4;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆           ●●●小卖部●●●          ┆" << endl;

	coord2.Y = 6;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆ ①爆炸果实:让你小宇宙爆炸             ┆" << endl;
	coord2.Y = 7;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆   价格200,体力+50,力量+50,敏捷度-80   ┆" << endl;

	coord2.Y = 8;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆ ②荷花图  :让你内心平静.              ┆" << endl;
	coord2.Y =9;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆   价格200,力量-50,敏捷度+80.          ┆" << endl;

	coord2.Y = 10;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆ ③可乐加冰 :让你乐乐乐.               ┆" << endl;
	coord2.Y = 11;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆   价格50,体力+25,力量+25,敏捷度+25.   ┆" << endl;

	coord2.Y = 12;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆ ④月半外套 :很耐打.                   ┆" << endl;
	coord2.Y = 13;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆   价格100,防御力+100.                 ┆" << endl;

	coord2.Y = 14;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆ ⑤加厚的衣架 :打得很疼.               ┆" << endl;
	coord2.Y = 15;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┆   价格12,攻击力+20.                   ┆" << endl;

	coord2.Y = 16;
	SetConsoleCursorPosition(h2, coord2);
	cout << "┕┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┙" << endl;

}

void Store::purchase()
{
	while (1)
	{
		system("cls");
		showStoreUI();
		cout << "请选择你想购买的商品序号" << endl;
		char choice = getchar();

		switch (choice)
		{
		case 'p':case 'P'://退出
			return;
			break;
		case '1'://爆炸果实
		{
			//类别 价格 体力 攻击力 防御力
			Drug* angryFru = new Drug(1, 200, "爆炸果实", "让你小宇宙爆炸", 50, 50, -80);
			Player::getPlayer()->bag.getProp(angryFru);
			//改变玩家金钱
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= angryFru->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "购买成功!" << endl;
		}
		break;
		case '2'://荷花图
		{
			Drug* lotusPic = new Drug(1, 200, "荷花图", "让你内心平静", 0, -50, 80);
			Player::getPlayer()->bag.getProp(lotusPic);
			//改变玩家金钱
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= lotusPic->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "购买成功!" << endl;
		}

		break;
		case '3'://可乐加冰
		{
			Drug* iceCola = new Drug(1, 50, "可乐加冰", "让你乐乐乐", 25, 25, 25);
			Player::getPlayer()->bag.getProp(iceCola);
			//改变玩家金钱
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= iceCola->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "购买成功!" << endl;
		}
		break;

		case '4'://月半外套
		{
			Equip* fatCoat = new Equip(2, 100, "月半外套", "很耐打", 0, 0, 100);
			Player::getPlayer()->bag.getProp(fatCoat);
			//改变玩家金钱
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= fatCoat->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "购买成功!" << endl;
		}
		break;

		case '5'://加厚的衣架
		{
			Equip* coatHanger = new Equip(2, 12, "加厚的衣架", "打得很疼", 0, 20, 0);
			Player::getPlayer()->bag.getProp(coatHanger);
			//改变玩家金钱
			int temMoney = Player::getPlayer()->getMoney();
			temMoney -= coatHanger->getPrice();
			Player::getPlayer()->setMoney(temMoney);
			cout << "购买成功!" << endl;
		}
		break;
		

		}
		_getch();
	}
	
	
	

}