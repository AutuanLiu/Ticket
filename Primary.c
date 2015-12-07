//含有main方法的.c文件
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "FlightInfo.h"
int main()
{
    printf("\t\t***************       菜单     ***************\n\n");
	printf("\t\t*************** 1   购买机票   ***************\n");
	printf("\t\t*************** 2 查询已购机票 ***************\n");
	printf("\t\t*************** 3 查询航线信息 ***************\n");
	printf("\t\t*************** 4 查询已卖机票 ***************\n");
	printf("\t\t*************** 5     退票     ***************\n");
	printf("\t\t*************** 6 整理当前屏幕 ***************\n");
    printf("\t\t*************** 7   退出系统   ***************\n");

    int choice;

	while(choice)
 {
	printf("请输入你要进行操作所对应的序号：(1~7) ");
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
                printf("请输入您的证件号： ");
                scanf("%s",id);
                query(id);
                break;
            }
        case 3:
            {
                char airNum[20];
                printf("请输入航班号： ");
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
                printf("请输入航班号： ");
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

