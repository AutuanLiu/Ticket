#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
//д��һ��
//���ܴ�����
writefile(char *str)
{
    char c;
    FILE *fout;
    if((fout=fopen("guest_info.csv","w"))==NULL)
        perror("guest_info.csv");
    while((c=fgetc(fout))!=EOF&&c== '\n')
        fprintf(fout,"%s",str);
}
