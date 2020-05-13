#include "pubuse.h" /* ��ʵ��һ��������ͬ*/ 
typedef char QElemType; /* ����ѭ��������Ԫ�����ַ�*/ 
#include "SeQueueDef.h" 
#include "SeQueueAlgo.h" 


void main() 
{ 
int i; 
QElemType d; 
SqQueue q; 
i=InitQueue(q); 
if(i) 
printf("�ɹ��ع�����һ���ն���!\n");
printf("\n�����Ƿ�Ϊ��(0:�գ�1:�ǿ�)��%d",QueueEmpty(q));
printf("\n���е���󳤶�Ϊ%d\n",MAXQSIZE-1);

//����3��Ԫ��'A' 'B' 'C'���ν������,���鿴���г���
printf("\n��'A','B','C'�������\n");
EnQueue(q,'A'); 
EnQueue(q,'B'); 
EnQueue(q,'C'); 
printf("����3 ��Ԫ��'A','B','C'��,���еĳ���Ϊ%d",QueueLength(q)); 
printf("\n�����Ƿ�����(0:δ����1:��)��%d\n",QueueFull(q));

//����1��Ԫ��'E' �������,���鿴�����Ƿ�����
printf("\n�ڲ���һ��Ԫ��'D'");
EnQueue(q,'D');
printf("\n����1��Ԫ��'D'��,���еĳ���Ϊ%d",QueueLength(q)); 
printf("\n�����Ƿ�����(0:δ����1:��)��%d\n",QueueFull(q));


//��4��Ԫ�����γ�����
printf("Ԫ��ȫ�������У�");
QElemType e;
for(int j=1;j<=MAXQSIZE-1;++j){
	DeQueue(q,e);
	printf("%c  ",e);
}
 
} 
