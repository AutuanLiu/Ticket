//关于乘客的.c文件
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "PublicInfo.h"
char userhasTicket[COLUMN][50];
//函数声明
void listSort(Puser info);
int read(char (*Info)[100], size_t s, FILE *pf);
int getline(char *Line, size_t s, FILE *pf);
int equals(char *a, char *b);
int check(Puser head, Puser *guestinfo, char (*options)[100]);

Puser initial()    //链表初始化
{
    Puser pnew = (Puser)malloc(sizeof(user));
    if(pnew != NULL)
        //所有元素初始化为 0
        memset(pnew, 0, sizeof(user));
    return pnew;
}

int addguest(Puser head, char (*row)[100])        //添加客户
{
    Puser pnew = initial();
    if(pnew == NULL)
        return 0;
    //赋值
    strcpy(pnew->name,row[0]);
    strcpy(pnew->line_num,row[3]);
    strcpy(pnew->ID,row[1]);
    strcpy(pnew->destination,row[2]);
    //将字符串转换为整型
    pnew->seat_num = atoi(row[4]);
    //将字符串转换为浮点型
    pnew->next = head->next;
    head->next = pnew;
    return 1;
}

Puser createguestList(FILE *pf)
{
    Puser head = initial();
    if(head == NULL)
        return NULL;
        //开头已经定义
    read(userhasTicket, COLUMN, pf);
    char splitStr[COLUMN][100];//只在本函数中有效
    while( read(splitStr, COLUMN, pf) != EOF)
        addguest(head, splitStr);
    return head;
}

//表插法排序,按照座位号
void listSort(Puser info)
{
    Puser  now,pre,p,q,head;
	head=info;
	pre=head->next;
	if(pre==NULL)
	now=pre->next;
	if(now==NULL)
	while(now!=NULL)
        {
            q=head;
            p=head->next;
            while(p!=now && p->seat_num<=now->seat_num)
                {
                    q=p;
                    p=p->next;
                }
            if(p==now)
                {
                    pre=pre->next;
                    now=pre->next;
                    continue;
                }
            pre->next=now->next;
            q->next=now;
            now->next=p;
            now=pre->next;
        }
}


//乘客的搜索
int check(Puser head, Puser *guestinfo, char (*options)[100])
    // 指针的指针（存储满足条件的航班）    //查找条件，航线
{
    int pos = 0;    //满足条件的个数
    head = head->next;
    while(head!=NULL)
    {
        if(!equals(head->line_num, options[0]))
        {
            head = head->next;
                    continue;
        }
        guestinfo[pos++] = head;
        head = head->next;
    }
    listSort(guestinfo);
    return pos;
}

void  allguest()
{
    int sum,i;
    char option[1][100];
    Puser s[50];
    printf("请输入航班号： ");
    scanf("%s",option[0]);
    FILE *pf = fopen("guest_info.csv","r");
    if(pf==NULL)
        perror("guest_info.csv");
    Pairl g = createguestList(pf);
    sum=check(g,s,option);
    if(sum==0)
        printf("对不起，当前航班无人搭乘\n");
    else
    {
       printf("航班内所有的乘客信息如下：\n");
    printf("序号\t 姓名\t    ID\t\t目的地\t航班号\t座位号\n");
    for(i = 0; i < sum; i++)
        {
            printf("%d:",i+1);
            printf("\t%s\t%s\t%s\t%s\t%d\n",s[i]->name,s[i]->ID,
            s[i]->destination,s[i]->line_num,s[i]->seat_num);
        }
    }
 fclose(pf);
}
