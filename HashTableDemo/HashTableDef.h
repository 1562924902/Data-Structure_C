typedef int KeyType; /* ����ؼ�������Ϊ���� */
typedef int InfoType;


typedef struct
{  KeyType key; /* �ؼ����� */
InfoType otherinfo; /* ������������������������ж��� */
}ElemType; /* ��¼���� */

typedef struct
{
ElemType *elem; /* ����Ԫ�ش洢��ַ����̬�������� */
int count; /* ��ǰ����Ԫ�ظ��� */
 /* Ϊ��ǰ���� */
}HashTable;





  
