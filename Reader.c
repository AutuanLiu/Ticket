//�ļ�������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

 //���ļ���ǰ��꿪ʼ����һ�У������ļ���β����EOF��End Of File Ϊ-1 ��
 //����size_t��stddef.h�еĶ���
 //typedef unsigned int size_t
int getline(char *Line, size_t s, FILE *pf)
{
    char c;
    int pos = 0;
    while((c = fgetc(pf)) != EOF && c!= '\n' && pos < s)
    {
        Line[pos++] = c;
    }
    Line[pos] = '\0';
    if(c == EOF)
        return EOF;
    else
        return 1;
}
//��ȡ�ļ�
int read(char (*Info)[100], size_t s, FILE *pf)
//����getline���ļ���һ�ж��룬ͨ�����ŷָ������ָ������ַ����ŵ�pinfo��
{
    char str[100];
    int pos = 0;
    if(getline(str, 100, pf) == EOF)
        return EOF;
    //�����жϱ��
    char *delims = ",";
    //strtok���������ַ���str�н��ӡ������Ĳ��ֵ�ָ��,
    char *result = strtok( str, delims );
    while( result != NULL )
    {
        strcpy(Info[pos++], result);
        if(pos >= s)
            break;
        result = strtok( NULL, delims );
    }
    return 1;
}


