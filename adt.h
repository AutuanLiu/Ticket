struct user
{
    char name[9];//�˿���//����Ա
    char ps[6]; //password
    int flag;  //flag=1��0�ֱ�Ϊ����Ա����ͨ�û�
    char line_num[8];//�����
    int seat_num;//��λ��
    char ID[20];
    struct user *next;//��һ�����
};
typedef struct user user,*Puser;

//������Ϣ
struct airline
{
    char line_num[8];//�����
    char plane_num[8];//�ɻ���
    char destination[20];//Ŀ�ĵ�
    char start_time[10]; //��ɵ�ʱ��
    char end_time[10];  //�����ʱ��
    int price;  //Ʊ��
    double discount;//�ۿ�
    int total;//��λ����
    int left;//ʣ����λ
    Puser guest_info;//�Ѿ���Ʊ�Ŀͻ���Ϣ
    struct airline *next;//��һ�����
};
typedef struct airline airl,*Pairl;
