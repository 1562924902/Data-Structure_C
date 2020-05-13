/* 检验InsertSortAlgo.h 和SeqBinSearchAlgo.h 的程序*/
#include"pubuse.h" /* 通用常量定义和系统函数原型声明*/
#include"compare.h" /* 两个数值型关键字的比较约定宏定义*/
#include"ElemDef.h" /*是对待查询/排序记录的数据类型定义*/
#include "InsertSortAlgo.h" /* 顺序表插入排序的函数*/
#include "SeqBinSearchAlgo.h" /*静态查找表的基本操作*/
/*typedef int InfoType; 定义其它数据项的类型*/
#define N 10
#define T 3
void print1(SqList L)
{ //依次输出顺序表每个元素得关键字项和其它信息项
int i;
for(i=1;i<=L.length;i++)
printf("(%d,%d)",L.r[i].key,L.r[i].otherinfo);
printf("\n");
}
void main()
{
sortstruct d[N]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},{55,9},{4,10}};
SqList l1,l2,l3,st;
int i,s,j;
int dt[T]={5,3,1};
List_Creat_Sq(st,N); /* 由全局数组产生静态查找表st */
for(i=0;i<N;i++) /* 给l1.r 赋值*/
st.r[i+1]=d[i];
st.length=N;
l3=l2=l1=st; /* 复制顺序表l2、l3 与l1 相同*/
printf("排序前:\n");
print1(st);
printf("\n");
printf("请输入待查找的关键字: ");
scanf("%d",&s);
i=List_Search_Sq(st,s); /* 顺序查找*/
if(i)
printf("%d\n",(*(st.r+i)).otherinfo);
else
printf("没找到\n");
InsertSort(l1);
printf("直接插入排序后:\n");
print1(l1);
printf("\n") ;
BInsertSort(l2);
printf("折半插入排序后:\n");
print1(l2);
printf("\n") ;
printf("请输入待折半查找的关键字: ");
scanf("%d",&s);
j=List_BinSearch_Sq(l3,s);
if(j)
printf("查找了%d 次！\n",j);
else
printf("没找到\n");
}