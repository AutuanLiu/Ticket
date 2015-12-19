//含有main方法的.c文件
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "PublicInfo.h"
int main()
{
    printf("\n\t**********     欢迎进入广州白云机场服务系统  \t*********\n\n");
    printf("\t\t***********                 菜单            ***********\n\n");
	printf("\t\t***********         1   购买机票            ***********\n");
	printf("\t\t***********         2 查询已购机票          ***********\n");
	printf("\t\t***********         3 查询航线信息          ***********\n");
	printf("\t\t***********         4 查询售出机票          ***********\n");
	printf("\t\t***********         5     退票              ***********\n");
	printf("\t\t***********         6   刷新屏幕            ***********\n");
	printf("\t\t***********         7  增加新航班           ***********\n");
	printf("\t\t***********         8 机场所有航班的信息    ***********\n");
	printf("\t\t***********         9 查看某航班上的乘客信息***********\n");
    printf("\t\t***********         10   退出系统           ***********\n");
    int choice;
	while(choice)
 {
	printf("请输入你要进行操作所对应的序号：(1~10) ");
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
                printf("请输入您的姓名： ");
                scanf("%s",name);
                query(name);
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
                printf("所有顾客信息如下：\n");
                selled();
                break;
            }
        case 5:
            {
                char name[20];
                printf("请输入姓名： ");
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
              printf("请输入航班号: ");
              scanf("%s",s1);
              if(isLineExist(s1))
                printf("对不起,该航班信息已经存在,请添加其他航班.\n");
              else
              {
                printf("请输入起飞时刻,到达时刻,目的地,票价,折扣,每班载量,剩余载量（以英文','分隔）\n");
                scanf("%s",s);
                strcat(s1,",");
                strcat(s1,s);
                writefilenew(s1);
                writefilenew("\n");
                printf("添加航班成功！\n");
              }
              break;
            }
        case 8:
            {
               printf("所有的航班信息如下：\n");
               //printf("%s","航班号,起飞时刻,到达时刻,目的地,票价,折扣,每班载量,剩余载量\n");
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

