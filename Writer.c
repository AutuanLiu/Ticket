#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "adt.h"
//写入客户买票信息
int writefile(char *str)
{
    FILE *fout;
    fout=fopen("guest_info.csv","ab");
    //在末尾追加
    if(fout==NULL)
        perror("guest_info.csv");
    else
        fprintf(fout,"%s",str);
    fclose(fout);
    return 1;
}
//从客户信息读入文件信息


void Pairl2String(Pairl p, char *s) {
    p = p->next;
    s[0] = '\0';
    while(p) {
        strcat(s, p->line_num); strcat(s, ",");
        strcat(s, p->start_time); strcat(s, ",");
        strcat(s, p->end_time); strcat(s, ",");
        strcat(s, p->destination); strcat(s, ",");
        char tmp[10];
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
    char s[500];
    Pairl2String(p, s);
    FILE *fp = fopen("flight_info.csv","w");
    fprintf(fp, "%s", s);
    fclose(fp);
}
