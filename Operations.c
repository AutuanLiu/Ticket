//ʵ�ָ���ܵ�.c�ļ�
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "FlightInfo.h"
char seatNumtostr[10];
//char userhasTicket[MAX][50];
int buyTickets();
int refund(char *airlineNum);
int query(char *ID);
int airInfo(char *airlineNum);
char *selled();
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
                        printf("%d:",i);
                        printf("\t%s\t%s\t%s\t%.2f\t%d\t%d\n",air[i]->line_num,air[i]->start_time,
                        air[i]->end_time,air[i]->discount,air[i]->price,air[i]->left);
                    }
                    printf("��������Ҫ���򺽰�Ķ�Ӧ���: ");
                    scanf("%d",&number);
                    seatNum=air[number]->total-air[number]->left+1;
                    printf("����%s�κ���Ĺ�Ʊҵ��ɹ������Ļ�Ʊ����λ��Ϊ��%d\n",air[number]->line_num,seatNum);
                    printf("����Ϊ���������Ժ� . . .\n");
                    itoa(seatNum,seatNumtostr,10);
                    //�ѹ����Ʊ���û���Ϣ�����ļ�
                    writefile(ginfo[0]);
                    writefile(",");
                    writefile(ginfo[1]);
                    writefile(",");
                    writefile(options[0]);
                    writefile(",");
                    writefile(air[number]->line_num);
                    writefile(",");
                    writefile(seatNumtostr);
                    writefile("\n");
                    printf("��������ɹ�����ӭ�´ι��٣��˻���죡\n");
                }
            }
    }
                  //������          //�޸�flight_info�ļ��е���Ʊ��Ϣ
    fclose(pf);
    return 1;
}

//��Ʊ
int refund(char *airlineNum)
{

  //������  //�޸�flight_indo��Ʊ
}

//����֤�������ѯ��Ʊ��Ϣ
int query(char *ID)
{

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
        printf("���ߺ� ���ʱ�� ����ʱ�� Ŀ�ĵ� �ۿ� ��Ʊ�۸�  ��Ʊ\n");
        printf("%s\t%s\t %s\t %s\t%.2f\t%d\t %d\n",temp->line_num,temp->start_time,
                        temp->end_time,temp->destination,temp->discount,temp->price,temp->left);
    }
    fclose(pf);
    return 1;
}

//��ѯ������Ʊ
//have bugs  and need to fix
char *selled()
{
    //��guest-info��ȡ����
    char *sellinfo;
    FILE *fin;
    fin=fopen("guest_info.csv","r");
    if(fin==NULL)
        perror("guest_info.csv");
    else
        //��ȡ��Ϣ
        fscanf(fin,"%s",&sellinfo);
    fclose(fin);
    return sellinfo;
}


