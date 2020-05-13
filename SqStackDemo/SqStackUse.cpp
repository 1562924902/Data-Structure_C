typedef int SElemType; /* 定义栈元素类型为整型*/ 
#include "pubuse.h" /* 常量定义与系统函数原型声明，与实验一中的相同*/ 
#include "SqStackDef.h" /* 采用顺序栈的类型定义*/ 
#include "SqStackAlgo.h" /* 利用顺序栈的基本操作*/ 
void main() 
{ 

	printf("十进制-->八进制\n");
	conversion10_8(); /* 十进制数到八进制转换的验证*/ 
	printf("十进制-->十六进制\n");
	conversion10_16(); /* 十进制数到十六进制转换的验证*/ 
} 