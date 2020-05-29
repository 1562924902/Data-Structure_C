#define size 20		//哈希表长度为20
#define NULLKEY -32768
#include "HashTableDef.h"
#include "pubuse.h"
#include "HashTableAlgo.h"


int main()
{
	int i,nun,value;
	HashTable H;
	InitHashTable(&H);
	printf("----------测试代码----------");
	int a[size] ={309,312,321,318,305,317,301,304,328,331,409,416,432,410,411,415,413,422,431,420};
	printf("\n要输入学生的学号为（三位数的学号）：");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
		InsertHash(&H,a[i]);

	}
		
	printf("\n插入之后的哈希表为：");
	for(i=0;i<size;i++)
		printf("(%d,%d)  ",H.elem[i].key,H.elem[i].otherinfo);

	int value1,addr,j;
	printf("\n输入要查找的学号:");
	scanf("%d",&value1);
	j=SearchHash(H,value1,&addr);
	printf("搜索的地址是：%d\n",j);
}
