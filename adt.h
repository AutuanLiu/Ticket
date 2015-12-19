﻿//存储结构文件
//字典结构存储
//已购票用户信息


struct user
{
    char name[9];//顾客名
    char line_num[8];//航班号
    char destination[20];//目的地
    int seat_num;//座位号
    char ID[20];//证件号
    struct user *next;//下一个结点
};
typedef struct user user,*Puser;

//航线信息
struct airline
{
    char line_num[8];//航班号
    char plane_num[8];//飞机号
    char destination[20];//目的地
    char start_time[10]; //起飞的时间
    char end_time[10];  //降落的时间
    int price;  //票价
    float discount;//折扣
    int total;//座位总数
    int left;//剩余座位
    struct airline *next;//下一个结点
};
typedef struct airline airl,*Pairl;


