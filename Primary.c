//����main������.c�ļ�
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "PublicInfo.h"
int main()
{
    printf("\n\t**********        ��ӭ������ݰ��ƻ�������ϵͳ  \t*********\n\n");
    printf("\t\t***************       �˵�     ***************\n\n");
	printf("\t\t*************** 1   �����Ʊ   ***************\n");
	printf("\t\t*************** 2 ��ѯ�ѹ���Ʊ ***************\n");
	printf("\t\t*************** 3 ��ѯ������Ϣ ***************\n");
	printf("\t\t*************** 4 ��ѯ������Ʊ ***************\n");
	printf("\t\t*************** 5     ��Ʊ     ***************\n");
	printf("\t\t*************** 6 ����ǰ��Ļ ***************\n");
	printf("\t\t*************** 7  �����º���  ***************\n");
	printf("\t\t*************** 8 �鿴���к��� ***************\n");
	printf("\t\t*************** 9 �鿴����˿� ***************\n");
    printf("\t\t*************** 10   �˳�ϵͳ   ***************\n");
    int choice;
	while(choice)
 {
	printf("��������Ҫ���в�������Ӧ����ţ�(1~10) ");
	scanf("%d",&choice);
	switch(choice)
	{
        case 1:
            {
                buyTickets();
                break;
            }
        case 2:
            {
                char name[20];
                printf("���������������� ");
                scanf("%s",name);
                query(name);
                break;
            }
        case 3:
            {
                char airNum[20];
                printf("�����뺽��ţ� ");
                scanf("%s",airNum);
                airInfo(airNum);
                break;
            }
        case 4:
            {
                printf("���й˿���Ϣ���£�\n");
                selled();
                break;
            }
        case 5:
            {
                char name[20];
                printf("������������ ");
                scanf("%s",name);
                refund(name);
                break;
            }
        case 6:
            {
              system("cls");
              main();
              break;
            }
        case 7:
            {
              char s1[500],s[500];
              printf("�����뺽���: ");
              scanf("%s",s1);
              if(isLineExist(s1))
                printf("�Բ���,�ú�����Ϣ�Ѿ�����,�������������.\n");
              else
              {
                printf("���������ʱ��,����ʱ��,Ŀ�ĵ�,����ʱ��,����,Ʊ��,�ۿ�,ÿ������,ʣ����������Ӣ��','�ָ���\n");
                scanf("%s",s);
                strcat(s1,",");
                strcat(s1,"����,");
                strcat(s1,s);
                writefilenew(s1);
                writefilenew("\n");
                printf("��Ӻ���ɹ���\n");
              }
              break;
            }
        case 8:
            {
               printf("���еĺ�����Ϣ���£�\n");
               queryp();
               break;
            }
        case 9:
            {
               allguest();
               break;
            }
        case 10:
              exit(0);
    }
 }
 return 1;
}

