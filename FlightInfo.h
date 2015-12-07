#define PLANE_COUNT 9 //9行
#define COUNT 11  // 11列
Pairl init();   //航线信息初始化函数
int addPlane(Pairl head, char (*plane)[100]); //添加航线函数，plane为列指针
Pairl createplaneList(FILE *pf);  //创建关于航线信息的文件
//对航线进行搜索
int search(Pairl head, Pairl *arr, char (*options)[100], int maxPrice);
//定义全局外部变量
extern char flightPrintInfo[COUNT][100];
