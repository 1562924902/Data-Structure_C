#define  MAXSIZE  100 
#define  MAXROW  10
typedef struct { // ������Ԫ��
    int i, j;
    SElemType e;
} Triple;

typedef struct { // ����ϡ�����
    Triple data[MAXSIZE+1];
    int rpos[MAXROW+1];
    int mu, nu, tu;
} RLSMatrix;

