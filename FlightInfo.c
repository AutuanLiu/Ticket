#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "FlightInfo.h"

int read(char (*pInfo)[100], size_t s, FILE *pf);
int getline(char *pLine, size_t s, FILE *pf);
int equals(char *a, char *b);
typedef struct
{
    int hour;
    int minute;
} Date;

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


Pairl init()    //链表初始化
{
    Pairl pnew = (Pairl)malloc(sizeof(airl));
    if(pnew != NULL)
        memset(pnew, 0, sizeof(airl));
    return pnew;
}

int addPlane(Pairl head, char (*plane)[100])        //添加航班
{
    Pairl pnew = init();
    if(pnew == NULL)
        return 0;

    strcpy(pnew->line_num, plane[0]);
    strcpy(pnew->start_time, plane[2]);
    strcpy(pnew->end_time, plane[3]);
    strcpy(pnew->destination, plane[4]);
    pnew->price = atoi(plane[7]);
    pnew->discount = atof(plane[8]);
    pnew->total = atoi(plane[9]);
    pnew->left = atoi(plane[10]);
    pnew->next = head->next;
    head->next = pnew;
    return 1;
}

Pairl createplaneList(FILE *pf)         //从文件添加所有航班
{
    Pairl head = init();
    if(head == NULL)
        return NULL;
    read(flightPrintInfo, COUNT, pf);
    char splitStr[COUNT][100];
    while( read(splitStr, COUNT, pf) != EOF)
        addPlane(head, splitStr);
    return head;
}

int search(Pairl head, Pairl *arr, char (*options)[100], int maxPrice,  int isDiscount, int hasLeft)
{
    int pos = 0;
    head = head->next;
    while(head!=NULL)
    {
        if(equals(head->destination, options[0]))
        {

            Date flightStartDate = convert2Date(head->start_time);
            Date flightEndDate = convert2Date(head->end_time);
            if(options[1][0]!="\0" && options[2][0]!='\0')
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
            if(isDiscount == 1 && head->discount == 1)
            {
                head = head->next;
                continue;
            }
            if(hasLeft == 1 && head->left == 0)
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

void exch(Pairl *arr, int i, int j) {
    Pairl tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

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
            exch(arr, lt++, i++);
        }
        else if(now > v)
        {
            exch(arr, gt--, i);
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

int equals(char *a, char *b)
{
    if(b[0] == '\0' || strcmp(a, b) == 0)
        return 1;
    else
        return 0;
}

int main()
{

    FILE *pf = fopen("F:/flight_info.csv","r");

    Pairl p = createplaneList(pf);
    Pairl parr[9];
    char options[4][100] = {"大阪"};
    int pos = search(p, parr, options, 0,0,0);
    int i;
    for(i = 0; i < pos; i++)
        printf("%s\n",parr[i]->line_num);
    return 0;
}




