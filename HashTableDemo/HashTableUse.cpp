#define size 12
#define NULLKEY -32768
#include "HashTableDef.h"
#include "pubuse.h"
#include "HashTableAlgo.h"


int main()
{
	int i;
	HashTable H;
	int a[12]={12,65,34,16,27,37,22,28,15,47,48,35};
	printf("----------���Դ���----------");
	printf("\nҪ��������֣�");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	InitHashTable(&H);
	for(i=0;i<size;i++)
		InsertHash(&H,a[i]);
	printf("\n����֮��Ĺ�ϣ��Ϊ��");
	for(i=0;i<size;i++)
		printf("(%d,%d)",H.elem[i].key,H.elem[i].otherinfo);
	int addr,j;
	j=SearchHash(H,a[6],&addr);
	printf("\n����%d�ĵ�ַ�ǣ�%d\n",a[6],j);
}
