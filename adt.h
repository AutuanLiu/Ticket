struct user
{
    char name[9];//顾客名//管理员
    char ps[6]; //password
    int flag;  //flag=1或0分别为管理员和普通用户
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
