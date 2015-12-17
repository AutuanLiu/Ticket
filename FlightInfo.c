//���ں����.c�ļ�
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "PublicInfo.h"

char flightPrintInfo[COUNT][100];
//��������
void flightSort(Pairl *arr, int lo, int hi, int d);
int read(char (*pInfo)[100], size_t s, FILE *pf);
int getline(char *pLine, size_t s, FILE *pf);
int equals(char *a, char *b);
//ʱ��ṹ��
typedef struct
{
    int hour;
    int minute;
} Date;

//ʱ��Ƚ�
int dateCompare(Date a, Date b)
{
    if(a.hour < b.hour)
        return -1;
    else if(a.hour == b.hour)
    {
        if(a.minute < b.minute)
            return -1;
        else if(a.minute == b.minute)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}

//ת��Ϊ��������
Date convert2Date(char *d)
{
    Date dat;
    char copy[10];
    strcpy(copy, d);
    char *nowSplit = strtok(copy,":");
    dat.hour = atoi(nowSplit);
    nowSplit = strtok(NULL,":");
    dat.minute = atoi(nowSplit);
    return dat;
}

Pairl init()    //�����ʼ��
{
    Pairl pnew = (Pairl)malloc(sizeof(airl));
    if(pnew != NULL)
        //����Ԫ�س�ʼ��Ϊ 0
        memset(pnew, 0, sizeof(airl));
    return pnew;
}

int addPlane(Pairl head, char (*plane)[100])        //��Ӻ���
{
    Pairl pnew = init();
    if(pnew == NULL)
        return 0;
    //��ֵ
    strcpy(pnew->line_num,plane[0]);
    strcpy(pnew->start_time,plane[1]);
    strcpy(pnew->end_time,plane[2]);
    strcpy(pnew->destination,plane[3]);
    //���ַ���ת��Ϊ����
    pnew->price = atoi(plane[4]);
    //���ַ���ת��Ϊ������
    pnew->discount = atof(plane[5]);
    pnew->total = atoi(plane[6]);
    pnew->left = atoi(plane[7]);
    pnew->next = head->next;
    head->next = pnew;
    return 1;
}

Pairl createplaneList(FILE *pf)         //���ļ�������к��ൽPairl��ָ
{
    Pairl head = init();
    if(head == NULL)
        return NULL;
        //��ͷ�Ѿ�����
    read(flightPrintInfo, COUNT, pf);
    char splitStr[COUNT][100];//ֻ�ڱ���������Ч
    while( read(splitStr, COUNT, pf) != EOF)
        addPlane(head, splitStr);
    return head;
}

int equals(char *a, char *b)
{
    if(b[0] == '\0' || strcmp(a, b) == 0)
        return 1;
    else
        return 0;
}

//��������Ԫ��λ��
void exchange(Pairl *arr, int i, int j)
{
    Pairl tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

//�������򣨰����ߣ�
void flightSort(Pairl *arr, int lo, int hi, int d)
{
    if(lo >= hi) return;
    int lt = lo;
    int gt = hi;
    int v = arr[lo]->line_num[d];
    int i = lt + 1;
    while(i <= gt)
    {
        int now = arr[i]->line_num[d];
        if(now < v)
        {
            exchange(arr, lt++, i++);
        }
        else if(now > v)
        {
            exchange(arr, gt--, i);
        }
        else
        {
            i++;
        }
    }
    flightSort(arr, lo, lt-1, d);
    if(v > 0) flightSort(arr, lt, gt, d+1);
    flightSort(arr, gt+1, hi, d);
}

//���ߵ�����
int search(Pairl head, Pairl *arr, char (*options)[100], int maxPrice)
    // ָ���ָ�루�洢���������ĺ��ࣩ    //�������� //�ܽ��ܵ����۸���Ҫ��Ϊ0
{
    int pos = 0;    //���������ĸ���
    head = head->next;
    while(head!=NULL)
    {
        if(equals(head->destination, options[0]))
        {
            Date flightStartDate = convert2Date(head->start_time);
            Date flightEndDate = convert2Date(head->end_time);
            if(options[1][0]!='\0' && options[2][0]!='\0')
            {
                Date userStartDate = convert2Date(options[1]);
                Date userEndDate = convert2Date(options[2]);
                if(!(dateCompare(flightStartDate,userStartDate) >=0 && dateCompare(userEndDate, flightEndDate) >=0))
                {
                    head = head->next;
                    continue;
                }
            }
            else if(options[1][0]!='\0' && options[2][0] == '\0')
            {
                Date userStartDate = convert2Date(options[1]);
                if(dateCompare(flightStartDate,userStartDate) == -1)
                {
                    head = head->next;
                    continue;
                }
            }
            else if(options[2][0] != '\0')
            {
                Date userEndDate = convert2Date(options[2]);
                if(dateCompare(userEndDate, flightStartDate) == 1)
                {
                    head = head->next;
                    continue;
                }
            }
            if(maxPrice != 0 && maxPrice < head->price)
            {
                head = head->next;
                continue;
            }
            if(head->left == 0)
            {
                head = head->next;
                continue;
            }
            arr[pos++] = head;
        }
        head = head->next;
    }
    flightSort(arr, 0, pos-1, 0);
    return pos;
}





