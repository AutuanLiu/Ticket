//实现各项功能的.c文件
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "PublicInfo.h"
char userhasTicket[COLUMN][50];
char seatNum2str[10];
int buyTickets()   //买票
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
    Pairl p = createplaneList(pf);
    Pairl air[9]; //指针数组
    char options[3][100];
    char ginfo[2][50],guestInfo[500]; //当前客户信息
    int i,max,chioces,number,seatNum;
    printf("请输入你的姓名与证件号(以enter或空格隔开)\n");
    scanf("%s%s",ginfo[0],ginfo[1]);
    printf("请输入你要到达的目的地、最早起飞时间，最晚降落时间，最大价格(以enter或空格隔开)\n");
    scanf("%s%s%s%d",options[0],options[1],options[2],&max);
    printf("请确认你的购票信息\n");
    printf("姓名：%s\n证件号：%s\n目的地：%s\n最早起飞时间：%s\n最晚降落时间：%s\n最大价格：%d\n"
           ,ginfo[0],ginfo[1],options[0],options[1],options[2],max);
    printf("是(0)否(1)有错误？ ");
    scanf("%d",&chioces);
    switch(chioces)
    {
        case 0: {system("cls");buyTickets();break;}
        case 1:
            {
                int sum=search(p, air, options, max);
                if(sum==0)
                    printf("对不起，没有满足条件的航班!!!\n");
                else
                {
                    printf("满足条件的航班如下：\n");
                    printf("序号   航线号 起飞时间 降落时间 折扣 机票价格  余票\n");
                    for(i = 0; i < sum; i++)
                    {
                        printf("%d:",i+1);
                        printf("\t%s\t%s\t%s\t%.2f\t%d\t%d\n",air[i]->line_num,air[i]->start_time,
                        air[i]->end_time,air[i]->discount,air[i]->price,air[i]->left);
                    }
                    printf("请输入你要购买航班的对应序号: ");
                    scanf("%d",&number);
                    seatNum=air[number-1]->total-air[number-1]->left+1;
                    printf("您在%s次航班的购票业务成功，您的机票的座位号为：%d\n",air[number-1]->line_num,seatNum);
                    printf("正在为您办理，请稍后 . . .\n");
                    itoa(seatNum,seatNum2str,10);
                    //把购买机票的用户信息存入文件
                    writefile(ginfo[0]);
                    writefile(",");
                    writefile(ginfo[1]);
                    writefile(",");
                    writefile(options[0]);
                    writefile(",");
                    writefile(air[number-1]->line_num);
                    writefile(",");
                    writefile(seatNum2str);
                    writefile("\n");
                    //修改余票信息
                    Pairl new=updateplane(air[number-1]->line_num, 0);
                    writePairl(new);
                    printf("手续办理成功，欢迎下次光临，乘机愉快！\n");
                }
            }
    }
    fclose(pf);
    return 1;
}

//退票
void refund(char *name)
{
    Pairl p1;
    Puser p2;
    FILE *pf = fopen("guest_info.csv","r");
    Puser temp;
    Puser p = createguestList(pf);
    fclose(pf);

    temp=p->next;
    while(temp!=NULL) {
        if(strcmp(temp->name, name) == 0) {
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("未查询到顾客订票信息");
        return;
    }
    p1=updateplane(temp->line_num,1);
    writePairl(p1);
    p2=updateguest(name);
    writeguest(p2);
    printf("退票成功！\n");
}

//根据姓名查询订票信息
void query(char *name)
{
        FILE *pf = fopen("guest_info.csv","r");
        if(pf==NULL)
            perror("guest_info.csv");
            //读入信息并创建链表
        Puser temp,p = createguestList(pf);
        if(p==NULL)
            printf("创建链表失败\n");
        temp=p;
        while(!(equals(temp->name,name))&&temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        printf("对不起，您还没有订票或订票不成功.\n");
        else
        {
            printf("您的机票信息为：\n");
            printf("姓名,ID,目的地,航班号,座位号\n");
            printf("%s,%s,%s,%s,%d\n",temp->name,temp->ID,temp->destination,temp->line_num,temp->seat_num);
        }
    fclose(pf);
}

//查询航线信息
int airInfo(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //读入信息并创建链表
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("创建链表失败\n");
    temp=p;
    while(!(equals(temp->line_num,airlineNum))&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
        printf("对不起，不存在该航班号！\n");
    else
    {
        printf("所查找的航线信息为：\n");
        printf("航线号 起飞时间 降落时间 目的地 折扣  机票价格  余票\n");
        printf("%s\t%s\t %s\t %s\t%.2f\t%d\t %d\n",temp->line_num,temp->start_time,
                        temp->end_time,temp->destination,temp->discount,temp->price,temp->left);
    }
    fclose(pf);
    return 1;
}

//航线是否存在
int isLineExist(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //读入信息并创建链表
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("创建链表失败\n");
    temp=p;
    while(!(equals(temp->line_num,airlineNum))&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
        return 0;//不存在为 0
    else
    return 1;
    fclose(pf);
}

//查询已卖机票
//have bugs  and need to fix
char *selled()
{
    //从guest-info读取即可

    char s[1000];
    FILE *pf = fopen("guest_info.csv","r");
    if(pf==NULL)
        perror("guest_info.csv");
    Puser pall = createguestList(pf);
    //遍历航班信息
    printf("姓名,ID,目的地,航班号,座位号\n\n");
    guest2String(pall, s);
    printf("%s\n",s);
    fclose(pf);
}

//查询所有的航班
void queryp()
{
    char s[1000];
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
    Pairl pall = createplaneList(pf);
    //遍历航班信息
    printf("航班号,起飞时刻,到达时刻,目的地,票价,折扣,每班载量,剩余载量\n\n");
    Pairl2String(pall, s);
    printf("%s\n",s);
    fclose(pf);
}


