class Player;
//�����ͼ
void saveFile(int(*pMap)[12], int row, int line, char* filename);
//��ȡ��ͼ
void readFile(int(*pMap)[12], int row, int line, char* filename);
//�洢��ͼ��Ϣ
void saveMapFile(int** pMap, int row,int line,char* filename);
//��ȡ��ͼ��Ϣ
void readMapFile(int** pMap, int row, int line, char* filename);
//����ؿ���
void saveCustoms(int cust, char* filename);
//��ȡ�ؿ���
void readCustoms(int cust, char* filename);
//���������Ϣ
void savePlayerFile(Player*player,  char* filename);
//��ȡ�����Ϣ
void readPlayerFile(Player*player, char* filename);
//�˵�UI
void menuUI(int(*p)[20]);
//�˵�ѡ���ƶ�
void menuAction(int(*p)[20], int size);
//�˵�
void menu();
//��Ϸ����UI
void gameInfoUI();
//��ѧ���෨
void tipsUI();
