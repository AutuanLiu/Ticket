//����main������.c�ļ�
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "FlightInfo.h"
int main()
{
    printf("\t\t***************       �˵�     ***************\n\n");
	printf("\t\t*************** 1   �����Ʊ   ***************\n");
	printf("\t\t*************** 2 ��ѯ�ѹ���Ʊ ***************\n");
	printf("\t\t*************** 3 ��ѯ������Ϣ ***************\n");
	printf("\t\t*************** 4 ��ѯ������Ʊ ***************\n");
	printf("\t\t*************** 5     ��Ʊ     ***************\n");
	printf("\t\t*************** 6 ����ǰ��Ļ ***************\n");
    printf("\t\t*************** 7   �˳�ϵͳ   ***************\n");

    int choice;

	while(choice)
 {
	printf("��������Ҫ���в�������Ӧ����ţ�(1~7) ");
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
                char id[20];
                printf("����������֤���ţ� ");
                scanf("%s",id);
                query(id);
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
                selled();
                break;
            }
        case 5:
            {
                char planeNum[20];
                printf("�����뺽��ţ� ");
                scanf("%s",planeNum);
                airInfo(planeNum);
                break;
            }
        case 6:
            {
              system("cls");
              main();
              break;
            }
        case 7:
		    exit(0);
    }
 }
 return 1;
}

