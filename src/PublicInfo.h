
#define PLANE_COUNT 100 //100行
#define COUNT 8  // 8列
#define COLUMN 5
Pairl init();   //航线信息初始化函数
int addPlane(Pairl head, char (*plane)[100]); //添加航线函数，plane为列指针
Pairl createplaneList(FILE *pf);  //创建关于航线信息的文件
//对航线进行搜索
int search(Pairl head, Pairl *arr, char (*options)[100], int maxPrice);
int addguest(Puser head, char (*row)[100]);
Puser createguestList(FILE *pf) ;
int check(Puser head, Puser *guestinfo, char (*options)[100]);
//定义全局外部变量
extern char flightPrintInfo[COUNT][100];
extern char userhasTicket[COLUMN][50];

