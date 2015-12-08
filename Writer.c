#include <stdio.h>
#include <string.h>
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

