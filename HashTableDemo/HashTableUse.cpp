#define size 20		//��ϣ����Ϊ20
#define NULLKEY -32768
#include "HashTableDef.h"
#include "pubuse.h"
#include "HashTableAlgo.h"


int main()
{
	int i,nun,value;
	HashTable H;
	InitHashTable(&H);
	printf("----------���Դ���----------");
	int a[size] ={309,312,321,318,305,317,301,304,328,331,409,416,432,410,411,415,413,422,431,420};
	printf("\nҪ����ѧ����ѧ��Ϊ����λ����ѧ�ţ���");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
		InsertHash(&H,a[i]);

	}
		
	printf("\n����֮��Ĺ�ϣ��Ϊ��");
	for(i=0;i<size;i++)
		printf("(%d,%d)  ",H.elem[i].key,H.elem[i].otherinfo);

	int value1,addr,j;
	printf("\n����Ҫ���ҵ�ѧ��:");
	scanf("%d",&value1);
	j=SearchHash(H,value1,&addr);
	printf("�����ĵ�ַ�ǣ�%d\n",j);
}
