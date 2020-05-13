/* linlistUse.cpp 主要实现算法2.9、2.10、2.11、2.12的程序*/ 
#include"pubuse.h" 
typedef int ElemType; 
#include"linklistDef.h" 
#include"linklistAlgo.h" 

void main() 
{ 
	int n=5; 
	LinkList La,Lb,Lc; 
	int i; 
	ElemType e; 
	printf("按非递减顺序, "); 
	CreateList2_Link (La,n); /* 正位序输入n 个元素的值,建立一个单链表*/ 
	printf("La="); /* 输出链表La 的内容*/ 

	ListTraverse_Link (La); 
	printf("按非递增顺序, "); 
	CreateList_Link (Lb,n); /* 逆位序输入n 个元素的值*/ 
	printf("Lb="); /* 输出链表Lb 的内容*/ 
	ListTraverse_Link (Lb); 
	MergeList_Link (La,Lb,Lc); /* 按非递减顺序归并La 和Lb,得到新表Lc */ 
	printf("Lc="); /* 输出链表Lc 的内容*/
	ListTraverse_Link (Lc); 

	/* 算法2.9 的测试*/ 
	printf("\n enter insert location and value : "); 
	scanf("%d %d",&i,&e); 
	ListInsert_Link (Lc,i,e); 
	/* 在Lc 链表中第i 个结点处插入一个新的结点，其值为e;*/ 
	printf("Lc="); /* 输出链表Lc 的内容*/ 
	ListTraverse_Link (Lc); 

	/* 算法2.10 的测试*/ 
	printf("\n enter deletd location : "); 
	scanf("%d",&i); 
	ListDelete_Link (Lc,i,e); /* 在Lc 链表中删除第i 个结点，其值为返回给e 变量*/ 
	printf("The Deleted e=%d\n",e); /* 输出被删结点的内容*/ 
	printf("Lc="); /* 输出链表Lc 的内容*/ 
	ListTraverse_Link (Lc); 

	/*...................................
	输入数据测试完成的Sort_Link函数*/
	printf("Lc的非递增顺序为:");
	Sort_Link(Lc);
	ListTraverse_Link (Lc); 
}
