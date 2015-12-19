#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
//更新航班信息
Pairl updateplane(char *airlineNum, int flag)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //读入信息并创建链表
    Pairl temp,p = createplaneList(pf);
    fclose(pf);
    if(p==NULL)
        printf("创建链表失败\n");
    temp=p;
    while(temp != NULL) {
        if(strcmp(airlineNum, temp->line_num) == 0) {
            if(flag == 1)
                temp->left++;
            else if(flag == 0)
                temp->left--;
            break;
        }
        temp = temp->next;
    }

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
        fclose(pf);
        if(p==NULL)
            printf("创建链表失败\n");
        temp=p;
        while(temp->next != NULL) {
            if(strcmp(temp->next->name, name) == 0) {
                q = temp->next->next;
                free(temp->next);
                temp->next = q;
                return p;
            }
            temp=temp->next;
        }
        return p;

}
