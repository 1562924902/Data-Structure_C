#include<string.h> 
#include<ctype.h> 
#include<malloc.h> /* malloc()等*/ 
#include<limits.h> /* INT_MAX 等*/ 
#include<stdio.h> /* EOF(=^Z 或F6),NULL */ 
#include<stdlib.h> /* atoi() */ 
#include<io.h> /* eof() */ 
#include<math.h> /* floor(),ceil(),abs() */ 
#include<process.h> /* exit() */ 
/* 函数结果状态代码*/ 
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define INFEASIBLE -1 
/* #define OVERFLOW -2 因为在math.h 中已定义OVERFLOW 的值为3,故去掉此行*/
typedef int Status; /* Status 是函数的类型,其值是函数结果状态代码，如OK 等*/ 
typedef int Boolean; /* Boolean 是布尔类型,其值是TRUE 或FALSE */ 
