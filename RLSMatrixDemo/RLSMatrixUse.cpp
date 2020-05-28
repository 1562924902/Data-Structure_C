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
	printf("矩阵M的转置矩阵为:\n");
	TransposeSMatrix(M);
    OutPutRLSMatrix(M);


	/*...................................
输入数据测试完成矩阵乘法函数*/
	printf("----------稀疏矩阵乘法测试-----------");
	RLSMatrix N1,N2,Q;
	printf("\n------请输入矩阵N1-----\n");
	InPutRLSMatrix(N1);
	OutPutRLSMatrix(N1);
	printf("\n------请输入矩阵N2-----\n");
	InPutRLSMatrix(N2);
	OutPutRLSMatrix(N2);

	
//------计算N1与N2的积-----
	printf("\n----N1与N2的乘积为----\n");
	MultSMatrix(N1,N2,Q);
	OutPutRLSMatrix(Q);
	}