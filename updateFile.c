#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
//���º�����Ϣ
Pairl updateplane1(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //������Ϣ����������
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("��������ʧ��\n");
    temp=p;
    while(!(equals(temp->next->line_num,airlineNum))&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }
        --temp->next->left;
     return p;
}

Pairl updateplane2(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //������Ϣ����������
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("��������ʧ��\n");
    temp=p;
    while(!(equals(temp->next->line_num,airlineNum))&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }
        ++temp->next->left;
     return p;
}
//���¿ͻ���Ϣ
Puser updateguest(char *name)
{
    if(!isGuestExist(name))
        printf("�Բ�������û�ж�Ʊ��Ʊ���ɹ�.\n");
    else
    {
        FILE *pf = fopen("guest_info.csv","r");
        if(pf==NULL)
            perror("guest_info.csv");
            //������Ϣ����������
        Puser q,temp,p = createguestList(pf);
        if(p==NULL)
            printf("��������ʧ��\n");
        temp=p;
        while(!(equals(temp->next->name,name))&&temp->next->next!=NULL)
        {
            q=temp->next;
            temp->next=q->next;
            free(q);
        }
        return p;
    }
}
