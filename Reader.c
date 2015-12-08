//文件读功能
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

 //从文件当前光标开始读入一行，遇到文件结尾返回EOF（End Of File 为-1 ）
 //关于size_t在stddef.h中的定义
 //typedef unsigned int size_t
int getline(char *pLine, size_t s, FILE *pf)
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
//读取文件
int read(char (*pInfo)[100], size_t s, FILE *pf)
//调用getline将文件中一行读入，通过逗号分隔符将分隔开的字符串放到pinfo中
{
    char str[100];
    int pos = 0;
    if(getline(str, 100, pf) == EOF)
        return EOF;
    //定义中断标记
    char *delims = ",";
    //strtok函数返回字符串str中紧接“，”的部分的指针,
    char *result = strtok( str, delims );
    while( result != NULL )
    {
        strcpy(pInfo[pos++], result);
        if(pos >= s)
            break;
        result = strtok( NULL, delims );
    }
     //关闭文件
   // fclose(pf);
    return 1;
}



