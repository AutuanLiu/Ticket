#include <stdio.h>
#include <string.h>
//д��ͻ���Ʊ��Ϣ
int writefile(char *str)
{
    FILE *fout;
    fout=fopen("guest_info.csv","ab");
    //��ĩβ׷��
    if(fout==NULL)
        perror("guest_info.csv");
    else
        fprintf(fout,"%s",str);
    fclose(fout);
    return 1;
}
//�ӿͻ���Ϣ�����ļ���Ϣ

