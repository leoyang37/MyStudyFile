#include<iostream>
#include<conio.h>
#include"func.h"
#include"../Player.h"
#include"../FrameUI.h"
#include"../Map.h"
#include<Windows.h>
using namespace std;
//   6 = ��ɫ      E = ����ɫ
HANDLE h5 = GetStdHandle(STD_OUTPUT_HANDLE);
#define _Gold SetConsoleTextAttribute(h5, 0x06) // ��
#define _White SetConsoleTextAttribute(h5, 0x07) // ��


using namespace std;
// �����ļ�
void saveFile(int(*pMap)[12], int row, int line, char* filename)
{
	//1.���ļ�:���û�и��ļ�,�Զ�����һ���ļ�
	FILE* pfile = fopen(filename, "wb+");
	//2.д���ļ�:1.�׵�ַ(д�����ݵ��׵�ַ) 2.ÿһ���Ĵ�С 3.���� 4.FILE*
	//д�������ڴ������;
	fwrite(pMap, sizeof(int), row*line, pfile);
	//3.�ر��ļ�
	fclose(pfile);
}
// ��ȡ�ļ�
void readFile(int(*pMap)[12], int row, int line, char* filename)
{
	//1.���ļ�
	FILE* pfile = fopen(filename, "rb+");
	//2.��ȡ�ļ�:
	//1.�׵�ַ(��ȡ�����ݴ����ڴ���׵�ַ)
	//2.ÿһ���Ĵ�С
	//3.����
	//4.FILE*
	fread(pMap, sizeof(int), row*line, pfile);
	//3.�ر��ļ�
	fclose(pfile);
}
void savePlayer(Player* player, char* filename)
{
	//1.���ļ�:���û�и��ļ�,�Զ�����һ���ļ�
	FILE* pfile = fopen(filename, "wb+");
	//2.д���ļ�:1.�׵�ַ(д�����ݵ��׵�ַ) 2.ÿһ���Ĵ�С 3.���� 4.FILE*
	//д�������ڴ������;
	fwrite(player, sizeof(Player), 1, pfile);
	//3.�ر��ļ�
	fclose(pfile);
}
// ��ȡ�ļ�
void readPlayer(Player* player, char* filename)
{
	//1.���ļ�
	FILE* pfile = fopen(filename, "rb+");
	//2.��ȡ�ļ�:
	//1.�׵�ַ(��ȡ�����ݴ����ڴ���׵�ַ)
	//2.ÿһ���Ĵ�С
	//3.����
	//4.FILE*
	fread(player, sizeof(Player), 1, pfile);
	//3.�ر��ļ�
	fclose(pfile);
}

void savePlayerFile(Player*player, char* filename)
{
	//1.���ļ�:���û�и��ļ�,�Զ�����һ���ļ�
	FILE* pfile = fopen(filename, "wb+");
	//2.д���ļ�:1.�׵�ַ(д�����ݵ��׵�ַ) 2.ÿһ���Ĵ�С 3.���� 4.FILE*
	//д�������ڴ������;
	fwrite(player, sizeof(int), 1, pfile);
	//3.�ر��ļ�
	fclose(pfile);

}

void readPlayerFile(Player*player, char* filename)
{
	//1.���ļ�
	FILE* pfile = fopen(filename, "rb+");
	//2.��ȡ�ļ�:
	//1.�׵�ַ(��ȡ�����ݴ����ڴ���׵�ַ)
	//2.ÿһ���Ĵ�С
	//3.����
	//4.FILE*
	fread(player, sizeof(int), 1, pfile);
	//3.�ر��ļ�
	fclose(pfile);
}
//�洢��ͼ��Ϣ
void saveMapFile(int** pMap, int row, int line, char* filename)
{
	//1.���ļ�:���û�и��ļ�,�Զ�����һ���ļ�
	FILE* pfile = fopen(filename, "wb+");
	for (int i=0; i < row; i++)
	{
		//2.д���ļ�:1.�׵�ַ(д�����ݵ��׵�ַ) 2.ÿһ���Ĵ�С 3.���� 4.FILE*
		//д�������ڴ������;
		fwrite(pMap[i], sizeof(int), line, pfile);
	}
	//3.�ر��ļ�
	fclose(pfile);
}
//��ȡ��ͼ��Ϣ
void readMapFile(int** pMap, int row, int line, char* filename)
{
	//1.���ļ�
	FILE* pfile = fopen(filename, "rb+");
	for (int i = 0; i < row; i++)
	{
		//2.��ȡ�ļ�:
		//1.�׵�ַ(��ȡ�����ݴ����ڴ���׵�ַ)
		//2.ÿһ���Ĵ�С
		//3.����
		//4.FILE*
		fread(pMap[i], sizeof(int), line, pfile);
	}
	//3.�ر��ļ�
	fclose(pfile);
}
//����ؿ���
void saveCustoms(int cust,char* filename)
{
	//1.���ļ�:���û�и��ļ�,�Զ�����һ���ļ�
	FILE* pfile = fopen(filename, "wb+");
    //2.д���ļ�:1.�׵�ַ(д�����ݵ��׵�ַ) 2.ÿһ���Ĵ�С 3.���� 4.FILE*
	//д�������ڴ������;
	fwrite(&cust, sizeof(int), 1, pfile);
	//3.�ر��ļ�
	fclose(pfile);
}
//��ȡ�ؿ���
void readCustoms(int cust, char* filename)
{
	//1.���ļ�
	FILE* pfile = fopen(filename, "rb+");
	//2.��ȡ�ļ�:
	//1.�׵�ַ(��ȡ�����ݴ����ڴ���׵�ַ)
	//2.ÿһ���Ĵ�С
	//3.����
	//4.FILE*
	fread(&cust, sizeof(int), 1, pfile);
	//3.�ر��ļ�
	fclose(pfile);
}

// ��Ⱦ������
void menuUI(int(*p)[20])
{
	
	for (int i = 0; i < 16; i++)
	{
		cout << "\t";
		for (int j = 0; j < 20; j++)
		{
			switch (p[i][j])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "<<�����������ս>>";
				break;
			case 3:
				cout << "��ʼ��Ϸ    ";
				break;
			case 4:
				 cout << "��Ϸ����    ";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "�˳���Ϸ    ";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "\t" << " ������������������������������������������������������������������������" << endl;
	cout << "\t" << " ��    ������    ������    �س�ѡ��  ��" << endl;
	cout << "\t" << " ������������������������������������������������������������������������" << endl; 
}
// �������ѡ��
void menuAction(int(*p)[20], int size) // ���� ���� �����ƶ���ֵ
{
	for (int i = 8; i <= 12; i += 2)
	{
		if (7 == p[i][6]) // ���������ҵ�ѡ���ͼ��
		{
			if (((8 == i) && (size < 0)) || ((12 == i) && (size > 0)))
			{
				p[i][6] = 0;
				p[i - 2 * size][6] = 7;
				break; // �ı�ָ��������ѭ��
			}
			else
			{
				p[i][6] = 0;
				p[i + size][6] = 7;
				break; // �ı�ָ��������ѭ��
			}
		}
	}
}

void menu()
{
	// �������ͼ
	int menuUIMap[16][20] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 2, 0, 0, 0, 9,9, 9, 9, 9, 9, 9, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 7, 3, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	do
	{
		// ������
		int size; // �����ƶ��ĸ���
		bool start = false; // ѭ������
		do
		{
			system("cls");
			menuUI(menuUIMap); // ��Ⱦ�������ͼ
			char action1 = getch(); // ��ȡ������ַ�
			switch (action1)
			{
			case 72:  // ��������
				size = -2;
				menuAction(menuUIMap, size);
				break;
			case 80: // ��������
				size = 2;
				menuAction(menuUIMap, size);
				break;
			case 13:
				if (7 == menuUIMap[8][6]) // ��ʼ��Ϸ
				{
					return;
				}
				else if (7 == menuUIMap[10][6]) // ��Ϸ����
				{
					gameInfoUI();
				}
				else if (7 == menuUIMap[12][6]) // �˳���Ϸ
				{
					exit(1);
				}
				start = true;
				break;
			}
		} while (!start);
	} while (1);

}

void gameInfoUI()
{
	FrameUI::setPositionUI(3, 20);
	cout << "\t" << " ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	FrameUI::setPositionUI(3, 21);
	_Gold;
	cout << "\t" << "  ����Ϸ����:    ";
	_White;
	FrameUI::setPositionUI(3, 22);
	cout << "\t" << "  һ����飺�Ѳ�Ը������������˴��,�����ǵ�������ȥ���ࡣ"; 
	FrameUI::setPositionUI(3, 23);
	cout << "\t" << "  ����ʤ����������������ɣ���ս�ɹ��� ";
	FrameUI::setPositionUI(3, 24);
	cout << "\t" << "  ����ʧ�ܣ��ٷ���ʧ�ܽ�����ȡ���𣬵���ҽ��<=0ʱ����սʧ��                         ";
	FrameUI::setPositionUI(3, 25);
	cout << "\t" << "            �����������Ǹ���������������ֵ<=0����սʧ�� ";
	FrameUI::setPositionUI(3, 26);
	cout << "\t" << "  �ġ������� �ٵ��������ྭ��>=100ʱ��:";
	FrameUI::setPositionUI(3, 27);
	cout << "\t" << "             ����ȥ����Ͱ�������������������������ֵ������ֵ������ֵ��";
	FrameUI::setPositionUI(3, 28);
	cout << "\t" << "             ���Ը�����������:";
	FrameUI::setPositionUI(3, 29);
	cout << "\t" << "             �ڳ��й���ˮ���ԣ�����������Ʒ�������������͹���С��Ʒ�ı�����ֵ������ֵ������ֵ��";
	FrameUI::setPositionUI(3, 30);
	cout << "\t" << " ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	_getch();
}

//��ѧ���෨
void tipsUI()
{
	FrameUI::setPositionUI(60, 5);
	cout << "\t" << " ������������������������������������������������������";
	FrameUI::setPositionUI(60, 6);
	_Gold;
	cout << "\t" << "  ����ѧ���෨:    ";
	_White;
	FrameUI::setPositionUI(60, 7);
	cout << "\t" << "  �����ܳԵ���ʪ��������";
	FrameUI::setPositionUI(60, 8);
	cout << "\t" << "  �����ܳԵ��Ǹ����� ";
	FrameUI::setPositionUI(60, 9);
	cout << "\t" << "  ������˻��������к�����                         ";
	FrameUI::setPositionUI(60, 10);
	cout << "\t" << "  �������ܻ�����ǿɻ������� ";
	FrameUI::setPositionUI(60, 11);
	cout << "\t" << "  �����Ų���ǣͷ��";
	FrameUI::setPositionUI(60, 12);
	cout << "\t" << " ������������������������������������������������������";
	_getch();
}