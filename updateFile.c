#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
//更新航班信息
Pairl updateplane1(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //读入信息并创建链表
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("创建链表失败\n");
    temp=p;
    while(!(equals(temp->next->line_num,airlineNum))&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }
        temp->next->left-=1;
     return p;
}

Pairl updateplane2(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //读入信息并创建链表
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("创建链表失败\n");
    temp=p;
    while(!(equals(temp->next->line_num,airlineNum))&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }
        temp->next->left+=1;
     return p;
}
//更新客户信息
Puser updateguest(char *name)
{
        FILE *pf = fopen("guest_info.csv","r");
        if(pf==NULL)
            perror("guest_info.csv");
            //读入信息并创建链表
        Puser q,temp,p = createguestList(pf);
        if(p==NULL)
            printf("创建链表失败\n");
        temp=p;
        while(temp->next->name==name&&temp->next->next!=NULL)
        {
            q=temp->next;
            temp->next=q->next;
            free(q);
        }
        return p;
    fclose(pf);
}
