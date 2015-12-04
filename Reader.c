#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getline(char *pLine, size_t s, FILE *pf)        //���ļ���ǰ��꿪ʼ����һ�У������ļ���β����EOF
{
    char c;
    int pos = 0;
    while((c = fgetc(pf)) != EOF && c!= '\n' && pos < s)
    {
        pLine[pos++] = c;

    }
    pLine[pos] = '\0';
    if(c == EOF)
        return EOF;
    else
        return 1;
}

int read(char (*pInfo)[100], size_t s, FILE *pf)        //1.����getline���ļ���һ�ж��룬ͨ�����ŷָ������ָ������ַ����ŵ�info��
{
    char str[100];
    int pos = 0;

    if(getline(str, 100, pf) == EOF)
        return EOF;
    char *delims = ",";
    char *result = strtok( str, delims );
    while( result != NULL )
    {
        strcpy(pInfo[pos++], result);
        if(pos >= s)
            break;
        result = strtok( NULL, delims );
    }

    return 1;
}



