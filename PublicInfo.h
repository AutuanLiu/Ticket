
#define PLANE_COUNT 100 //100��
#define COUNT 8  // 8��
#define COLUMN 5
Pairl init();   //������Ϣ��ʼ������
int addPlane(Pairl head, char (*plane)[100]); //��Ӻ��ߺ�����planeΪ��ָ��
Pairl createplaneList(FILE *pf);  //�������ں�����Ϣ���ļ�
//�Ժ��߽�������
int search(Pairl head, Pairl *arr, char (*options)[100], int maxPrice);
int addguest(Puser head, char (*row)[100]);
Puser createguestList(FILE *pf) ;
int check(Puser head, Puser *guestinfo, char (*options)[100]);
//����ȫ���ⲿ����
extern char flightPrintInfo[COUNT][100];
extern char userhasTicket[COLUMN][50];

