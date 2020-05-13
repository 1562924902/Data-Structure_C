typedef int SElemType; /* 定义元素类型为整型*/ 
#include "pubuse.h" /* 常量定义与系统函数原型声明，与实验一中的相同*/ 
#include "RLSMatrixDef.h" /* 采用稀疏矩阵的类型定义*/ 
#include "RLSMatrixAlgo.h" /* 利用稀疏矩阵的基本操作*/ 


void main() 
{ 
	RLSMatrix M;
	printf("请输入矩阵M\n");
	InPutRLSMatrix(M);
	OutPutRLSMatrix(M);
    TransposeSMatrix(M);
	/*...................................
输入数据测试完成矩阵乘法函数*/
	RLSMatrix N1,N2;

	printf("\n------请输入矩阵N1-----\n");
	InPutRLSMatrix(N1);
	OutPutRLSMatrix(N1);



//------计算M与N1,N2的积-----
	RLSMatrix Q1,Q2;
	MultSMatrix(M,N1,Q1);
	printf("\n----M与N1的乘积为----\n");
	OutPutRLSMatrix(Q1);


} 
