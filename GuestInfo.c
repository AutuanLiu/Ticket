//���ڳ˿͵�.c�ļ�
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "PublicInfo.h"
char userhasTicket[COLUMN][50];
//��������
void listSort(Puser info);
int read(char (*Info)[100], size_t s, FILE *pf);
int getline(char *Line, size_t s, FILE *pf);
int equals(char *a, char *b);
int check(Puser head, Puser *guestinfo, char (*options)[100]);

Puser initial()    //�����ʼ��
{
    Puser pnew = (Puser)malloc(sizeof(user));
    if(pnew != NULL)
        //����Ԫ�س�ʼ��Ϊ 0
        memset(pnew, 0, sizeof(user));
    return pnew;
}

int addguest(Puser head, char (*row)[100])        //��ӿͻ�
{
    Puser pnew = initial();
    if(pnew == NULL)
        return 0;
    //��ֵ
    strcpy(pnew->name,row[0]);
    strcpy(pnew->line_num,row[3]);
    strcpy(pnew->ID,row[1]);
    strcpy(pnew->destination,row[2]);
    //���ַ���ת��Ϊ����
    pnew->seat_num = atoi(row[4]);
    //���ַ���ת��Ϊ������
    pnew->next = head->next;
    head->next = pnew;
    return 1;
}

Puser createguestList(FILE *pf)
{
    Puser head = initial();
    if(head == NULL)
        return NULL;
        //��ͷ�Ѿ�����
    read(userhasTicket, COLUMN, pf);
    char splitStr[COLUMN][100];//ֻ�ڱ���������Ч
    while( read(splitStr, COLUMN, pf) != EOF)
        addguest(head, splitStr);
    return head;
}

//��巨����,������λ��
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


//�˿͵�����
int check(Puser head, Puser *guestinfo, char (*options)[100])
    // ָ���ָ�루�洢���������ĺ��ࣩ    //��������������
{
    int pos = 0;    //���������ĸ���
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
    printf("�����뺽��ţ� ");
    scanf("%s",option[0]);
    FILE *pf = fopen("guest_info.csv","r");
    if(pf==NULL)
        perror("guest_info.csv");
    Pairl g = createguestList(pf);
    sum=check(g,s,option);
    if(sum==0)
        printf("�Բ��𣬵�ǰ�������˴��\n");
    else
    {
       printf("���������еĳ˿���Ϣ���£�\n");
    printf("���\t ����\t    ID\t\tĿ�ĵ�\t�����\t��λ��\n");
    for(i = 0; i < sum; i++)
        {
            printf("%d:",i+1);
            printf("\t%s\t%s\t%s\t%s\t%d\n",s[i]->name,s[i]->ID,
            s[i]->destination,s[i]->line_num,s[i]->seat_num);
        }
    }
 fclose(pf);
}
