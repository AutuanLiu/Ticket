#include <stdio.h>
#include <string.h>
#include "adt.h"
//д��ͻ���Ʊ��Ϣ
void  writefile(char *str)
{
    FILE *fout;
    fout=fopen("guest_info.csv","ab");
    //��ĩβ׷��
    if(fout==NULL)
        perror("guest_info.csv");
    else
        fprintf(fout,"%s",str);
    fclose(fout);
}

//д���º�����Ϣ
void writefilenew(char *str)
{
    FILE *fout;
    fout=fopen("flight_info.csv","ab");
    //��ĩβ׷��
    if(fout==NULL)
        perror("flight_info.csv");
    else
        fprintf(fout,"%s",str);
    fclose(fout);
}

//������Ϣת��Ϊ�ַ���
void Pairl2String(Pairl p, char *s)
{
    s[0] = '\0';
    //strcat(s,"�����,���ʱ��,����ʱ��,Ŀ�ĵ�,Ʊ��,�ۿ�,ÿ������,ʣ������");
    while(p)
        {
            strcat(s, p->line_num); strcat(s, ",");
            strcat(s, p->start_time); strcat(s, ",");
            strcat(s, p->end_time); strcat(s, ",");
            strcat(s, p->destination); strcat(s, ",");
            char tmp[500];
            //����������tmp
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
    //�������ڣ���ɾ��������д
    if(access("flight_info.csv",0)==0)
        remove("flight_info.csv");
    FILE *fp = fopen("flight_info.csv","w");
    fprintf(fp, "%s", s);
    fclose(fp);
}

//�˿���Ϣ�ַ���
void guest2String(Puser p, char *s)
{
    s[0] = '\0';
   // strcat(s,"����,ID,Ŀ�ĵ�,�����,��λ��");
    while(p)
        {
            strcat(s, p->name); strcat(s, ",");
            strcat(s, p->ID); strcat(s, ",");
            strcat(s, p->destination); strcat(s, ",");
            strcat(s, p->line_num); strcat(s, ",");
            char tmp[200];
            //����������tmp
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
    //�������ڣ���ɾ��������д
    if(access("guest_info.csv",0)==0)
        remove("guest_info.csv");
    FILE *fp = fopen("guest_info.csv","w");
    fprintf(fp, "%s", s);
    fclose(fp);
}
