存储客户和航班的信息均采用链式结构进行存储
客户和航班分别定义结构体

模拟客户方的所有功能


//客户信息
struct user{
 char name[9];//顾客名
 char ps[6]; //password
 char line_num[8];//航班号
 int seat_num;//座位号
 char ID[20];
 struct user *next;//下一个结点
};
typedef struct user user,*Puser;

//航线信息
struct airline
{
 char line_num[8];//航班号
 char plane_num[8];//飞机号
 char destination[20];//目的的
 char start_time[10]; //起飞的时间
 char end_time[10];  //降落的时间
 int price;  //票价
 double discount;//折扣
 int total;//座位总数
 int left;//剩余座位
 Puser guest_info;//已经订票的客户信息
 struct airline *next;//下一个结点
};
typedef struct airline airl,*Pairl;

