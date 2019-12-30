class Player;
//保存地图
void saveFile(int(*pMap)[12], int row, int line, char* filename);
//读取地图
void readFile(int(*pMap)[12], int row, int line, char* filename);
//存储地图信息
void saveMapFile(int** pMap, int row,int line,char* filename);
//读取地图信息
void readMapFile(int** pMap, int row, int line, char* filename);
//保存关卡数
void saveCustoms(int cust, char* filename);
//读取关卡数
void readCustoms(int cust, char* filename);
//保存玩家信息
void savePlayerFile(Player*player,  char* filename);
//读取玩家信息
void readPlayerFile(Player*player, char* filename);
//菜单UI
void menuUI(int(*p)[20]);
//菜单选择移动
void menuAction(int(*p)[20], int size);
//菜单
void menu();
//游戏介绍UI
void gameInfoUI();
//猪学分类法
void tipsUI();
