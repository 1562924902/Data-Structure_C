#define MAXSIZE 20 /* һ������ʾ����С˳������󳤶�*/
typedef int KeyType; /* ����ؼ�������Ϊ����*/
typedef int InfoType;
typedef struct
{ KeyType key; /* �ؼ�����*/
InfoType otherinfo; /* ������������������������ж���*/
}sortstruct; /* ��¼����*/
typedef struct
{ sortstruct *r; /* r[0]���û������ڱ���Ԫ*/
int length; /* ˳�����*/
}SqList; /* ˳�������*/
