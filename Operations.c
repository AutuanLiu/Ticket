//ʵ�ָ���ܵ�.c�ļ�
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "PublicInfo.h"
char userhasTicket[COLUMN][50];
char seatNum2str[10];
int buyTickets()   //��Ʊ
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
    Pairl p = createplaneList(pf);
    Pairl air[9]; //ָ������
    char options[3][100];
    char ginfo[2][50],guestInfo[500]; //��ǰ�ͻ���Ϣ
    int i,max,chioces,number,seatNum;
    printf("���������������֤����(��enter��ո����)\n");
    scanf("%s%s",ginfo[0],ginfo[1]);
    printf("��������Ҫ�����Ŀ�ĵء��������ʱ�䣬������ʱ�䣬���۸�(��enter��ո����)\n");
    scanf("%s%s%s%d",options[0],options[1],options[2],&max);
    printf("��ȷ����Ĺ�Ʊ��Ϣ\n");
    printf("������%s\n֤���ţ�%s\nĿ�ĵأ�%s\n�������ʱ�䣺%s\n������ʱ�䣺%s\n���۸�%d\n"
           ,ginfo[0],ginfo[1],options[0],options[1],options[2],max);
    printf("��(0)��(1)�д��� ");
    scanf("%d",&chioces);
    switch(chioces)
    {
        case 0: {system("cls");buyTickets();break;}
        case 1:
            {
                int sum=search(p, air, options, max);
                if(sum==0)
                    printf("�Բ���û�����������ĺ���!!!\n");
                else
                {
                    printf("���������ĺ������£�\n");
                    printf("���   ���ߺ� ���ʱ�� ����ʱ�� �ۿ� ��Ʊ�۸�  ��Ʊ\n");
                    for(i = 0; i < sum; i++)
                    {
                        printf("%d:",i+1);
                        printf("\t%s\t%s\t%s\t%.2f\t%d\t%d\n",air[i]->line_num,air[i]->start_time,
                        air[i]->end_time,air[i]->discount,air[i]->price,air[i]->left);
                    }
                    printf("��������Ҫ���򺽰�Ķ�Ӧ���: ");
                    scanf("%d",&number);
                    seatNum=air[number-1]->total-air[number-1]->left+1;
                    printf("����%s�κ���Ĺ�Ʊҵ��ɹ������Ļ�Ʊ����λ��Ϊ��%d\n",air[number-1]->line_num,seatNum);
                    printf("����Ϊ���������Ժ� . . .\n");
                    itoa(seatNum,seatNum2str,10);
                    //�ѹ����Ʊ���û���Ϣ�����ļ�
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
                    //�޸���Ʊ��Ϣ
                    Pairl new=updateplane1(air[number-1]->line_num);
                    writePairl(new);
                    printf("��������ɹ�����ӭ�´ι��٣��˻���죡\n");
                }
            }
    }
    fclose(pf);
    return 1;
}

//��Ʊ
void refund(char *name)
{
    Pairl p1;
    Puser p2;
    FILE *pf = fopen("guest_info.csv","r");
    Puser temp,p = createguestList(pf);
    temp=p;
    while(!(equals(temp->name,name))&&temp->next!=NULL)
        temp=temp->next;
    p1=updateplane2(temp->line_num);
    writePairl(p1);
    p2=updateguest(name);
    writeguest(p2);
    printf("��Ʊ�ɹ���\n");
}

//����������ѯ��Ʊ��Ϣ
void query(char *name)
{
        FILE *pf = fopen("guest_info.csv","r");
        if(pf==NULL)
            perror("guest_info.csv");
            //������Ϣ����������
        Puser temp,p = createguestList(pf);
        if(p==NULL)
            printf("��������ʧ��\n");
        temp=p;
        while(!(equals(temp->name,name))&&temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        printf("�Բ�������û�ж�Ʊ��Ʊ���ɹ�.\n");
        else
        {
            printf("���Ļ�Ʊ��ϢΪ��\n");
            printf("����,ID,Ŀ�ĵ�,�����,��λ��\n");
            printf("%s,%s,%s,%s,%d\n",temp->name,temp->ID,temp->destination,temp->line_num,temp->seat_num);
        }
    fclose(pf);
}

//��ѯ������Ϣ
int airInfo(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //������Ϣ����������
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("��������ʧ��\n");
    temp=p;
    while(!(equals(temp->line_num,airlineNum))&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
        printf("�Բ��𣬲����ڸú���ţ�\n");
    else
    {
        printf("�����ҵĺ�����ϢΪ��\n");
        printf("���ߺ� ���ʱ�� ����ʱ�� Ŀ�ĵ� �ۿ�  ��Ʊ�۸�  ��Ʊ\n");
        printf("%s\t%s\t %s\t %s\t%.2f\t%d\t %d\n",temp->line_num,temp->start_time,
                        temp->end_time,temp->destination,temp->discount,temp->price,temp->left);
    }
    fclose(pf);
    return 1;
}

//�����Ƿ����
int isLineExist(char *airlineNum)
{
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
        //������Ϣ����������
    Pairl temp,p = createplaneList(pf);
    if(p==NULL)
        printf("��������ʧ��\n");
    temp=p;
    while(!(equals(temp->line_num,airlineNum))&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
        return 0;//������Ϊ 0
    else
    return 1;
    fclose(pf);
}

//��ѯ������Ʊ
//have bugs  and need to fix
char *selled()
{
    //��guest-info��ȡ����

    char s[1000];
    FILE *pf = fopen("guest_info.csv","r");
    if(pf==NULL)
        perror("guest_info.csv");
    Puser pall = createguestList(pf);
    //����������Ϣ
    printf("����,ID,Ŀ�ĵ�,�����,��λ��\n\n");
    guest2String(pall, s);
    printf("%s\n",s);
    fclose(pf);
}

//��ѯ���еĺ���
void queryp()
{
    char s[1000];
    FILE *pf = fopen("flight_info.csv","r");
    if(pf==NULL)
        perror("flight_info.csv");
    Pairl pall = createplaneList(pf);
    //����������Ϣ
    printf("�����,���ʱ��,����ʱ��,Ŀ�ĵ�,Ʊ��,�ۿ�,ÿ������,ʣ������\n\n");
    Pairl2String(pall, s);
    printf("%s\n",s);
    fclose(pf);
}


