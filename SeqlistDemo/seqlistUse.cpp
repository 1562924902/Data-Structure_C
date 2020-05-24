#include"pubuse.h" /* 实现通用常量的定义，常用系统函数的声明*/ 
typedef int ElemType; /*实现一组整数的操作,将int 型特定义为通用的ElemType 类型名*/ 
#include"seqlistDef.h" /* 采用线性表的动态分配顺序存储结构定义*/ 
#include"seqlistAlgo.h" /* 采用顺序表的基本算法定义*/ 
void main() 
{ 
	SqList L; 
	Status i; 
	int j; 
	ElemType t; 
	ElemType e;
/* 首先一定要初始化顺序表*/ 
i=ListInit_Sq(L);
if(i==1) /* 创建空表L 成功*/ 
for(j=1;j<=5;j++) /* 在表L 中插入5 个元素，每个元素的值分别为2，4，6，8，10 */ 
i=ListInsert_Sq(L,j,2*j); 

ListPrint_Sq(L); /*检验一下插入的结果，输出表L 的内容*/ 
ListInsert_Sq(L,2,20);/* 随机指定插入点位置，假设在第二个元素前插入新的元素，其值为20 */ 
ListDelete_Sq(L,4,&t);/* 随机指定删除点位置，假设对第四个元素进行删除*/ 
printf("\n The Deleted value is %d",t);/* 检验一下删除点元素的值*/ 
ListPrint_Sq(L);/* 检验一下插入和删除后的结果，输出表La 的内容*/

ListReverse_Sq(L);/* 将顺序表La 的所有元素进行逆序*/ 
ListPrint_Sq(L);/* 检验一下逆序的结果，输出表L 的内容*/ 
printf("\n The List length is %d",ListLength_Sq(L));
printf("\n The List empty is %d\n",ListEmpty_Sq(L));

//----------测试代码---------- 
printf("\n--------测试代码----------");
printf("\n The List Max number is %d",MaxElem_Sq(L));//输出最大元素
printf("\n the third number is %d",GetElem_Sq(L,3,e));
printf("\n 20 是第%d个数",LocateElem_Sq(L,4));
}