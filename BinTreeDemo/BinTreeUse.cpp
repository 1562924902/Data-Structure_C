/* BinTreeUse.cpp 检验BinTreeAlgo.h 的主程序,利用条件编译选择数据类型(另一种方法) */ 
#include"pubuse.h" /* 与实验一的意义相同*/ 

/* 二叉树的数据类型可以以是字符型，也可以是整型，可在程序中使用条件编译作出判断和控制*/ 
#define CHAR /* 字符型， 本例是采用字符型作为数据类型*/ 
//-------------------------------------
/* #define INT /* 整型（二者选一） */ 
#ifdef CHAR 
typedef char TElemType; 
TElemType Nil=' '; /* 字符型以空格符为空*/
#endif 

#ifdef INT 
typedef int TElemType; 
TElemType Nil=0; /* 整型以0 为空*/ 
#endif 
//---------------------------------------
#include"BinTreeDef.h" /* 二叉树链式存储结构定义*/ 
#include"BinTreeAlgo.h" /* 二叉树基本算法和扩展算法定义*/ 
Status visitT(TElemType e) 
{
#ifdef CHAR
printf("%c ",e); 
#endif 
#ifdef INT 
printf("%d ",e); 
#endif 
return OK; 
}

void main() 
{
BiTree T; 
TElemType e1; 
/* 1---基本实验算法的验证*/ 
InitBiTree(T); 
printf("构造空二叉树后,树空否？%d(1:是0:否)\n",BiTreeEmpty(T)); 
e1=Root(T); 
if(e1!=Nil) 
#ifdef CHAR 
printf("二叉树的根为: %c\n",e1); 
#endif 
#ifdef INT 
printf("二叉树的根为: %d\n",e1); 
#endif 
else
printf("树空，无根\n"); 
#ifdef CHAR 
printf("请先序输入二叉树(如:ab 三个空格表示a 为根结点,b 为左子树的二叉树)\n"); 
#endif 
#ifdef INT 
printf("请先序输入二叉树(如:1 2 0 0 0 表示1 为根结点,2 为左子树的二叉树)\n"); 
#endif
CreateBiTree(T); 
printf("建立二叉树后,树空否？%d(1:是0:否) \n",BiTreeEmpty(T)); 
e1=Root(T); 
if(e1!=Nil) 
#ifdef CHAR 
printf("二叉树的根为: %c\n",e1); 
#endif 
#ifdef INT 
printf("二叉树的根为: %d\n",e1); 
#endif 
else
printf("树空，无根\n"); 
printf("中序递归遍历二叉树:\n"); 
InOrderTraverse(T,visitT); 
printf("\n后序递归遍历二叉树:\n"); 
PostOrderTraverse(T,visitT); 

printf("\n二叉树的深度为:\n");
Deepth(T);

}