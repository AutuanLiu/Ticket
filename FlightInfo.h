#define PLANE_COUNT 9 //9��
#define COUNT 11  // 11��
Pairl init();   //������Ϣ��ʼ������
int addPlane(Pairl head, char (*plane)[100]); //��Ӻ��ߺ�����planeΪ��ָ��
Pairl createplaneList(FILE *pf);  //�������ں�����Ϣ���ļ�
//�Ժ��߽�������
int search(Pairl head, Pairl *arr, char (*options)[100], int maxPrice);
//����ȫ���ⲿ����
extern char flightPrintInfo[COUNT][100];
