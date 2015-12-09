#include <stdio.h>
#include <string.h>
#include "adt.h"
//写入客户买票信息
void  writefile(char *str)
{
    FILE *fout;
    fout=fopen("guest_info.csv","ab");
    //在末尾追加
    if(fout==NULL)
        perror("guest_info.csv");
    else
        fprintf(fout,"%s",str);
    fclose(fout);
}

//写入新航班信息
void writefilenew(char *str)
{
    FILE *fout;
    fout=fopen("flight_info.csv","ab");
    //在末尾追加
    if(fout==NULL)
        perror("flight_info.csv");
    else
        fprintf(fout,"%s",str);
    fclose(fout);
}

//航班信息转化为字符串
void Pairl2String(Pairl p, char *s)
{
    s[0] = '\0';
    //strcat(s,"航班号,起飞时刻,到达时刻,目的地,票价,折扣,每班载量,剩余载量");
    while(p)
        {
            strcat(s, p->line_num); strcat(s, ",");
            strcat(s, p->start_time); strcat(s, ",");
            strcat(s, p->end_time); strcat(s, ",");
            strcat(s, p->destination); strcat(s, ",");
            char tmp[500];
            //发到缓冲区tmp
            sprintf(tmp, "%d", p->price);
            strcat(s, tmp); strcat(s, ",");
            sprintf(tmp, "%.2f", p->discount);
            strcat(s, tmp); strcat(s, ",");
            sprintf(tmp, "%d", p->total);
            strcat(s, tmp); strcat(s, ",");
            sprintf(tmp, "%d", p->left);
            strcat(s, tmp);
            if(p->next != NULL)
                strcat(s, "\n");
            p = p->next;
    }
}

void writePairl(Pairl p)
{
    char s[5000];
    Pairl2String(p, s);
    //若果存在，先删除，在重写
    if(access("flight_info.csv",0)==0)
        remove("flight_info.csv");
    FILE *fp = fopen("flight_info.csv","w");
    fprintf(fp, "%s", s);
    fclose(fp);
}

//乘客信息字符化
void guest2String(Puser p, char *s)
{
    s[0] = '\0';
   // strcat(s,"姓名,ID,目的地,航班号,座位号");
    while(p)
        {
            strcat(s, p->name); strcat(s, ",");
            strcat(s, p->ID); strcat(s, ",");
            strcat(s, p->destination); strcat(s, ",");
            strcat(s, p->line_num); strcat(s, ",");
            char tmp[200];
            //发到缓冲区tmp
            sprintf(tmp, "%d", p->seat_num);
            strcat(s, tmp);
            if(p->next != NULL)
                strcat(s, "\n");
            p = p->next;
    }
}

void writeguest(Puser p)
{
    char s[5000];
    guest2String(p, s);
    //若果存在，先删除，在重写
    if(access("guest_info.csv",0)==0)
        remove("guest_info.csv");
    FILE *fp = fopen("guest_info.csv","w");
    fprintf(fp, "%s", s);
    fclose(fp);
}
