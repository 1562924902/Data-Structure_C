typedef int SElemType; /* ����Ԫ������Ϊ����*/ 
#include "pubuse.h" /* ����������ϵͳ����ԭ����������ʵ��һ�е���ͬ*/ 
#include "RLSMatrixDef.h" /* ����ϡ���������Ͷ���*/ 
#include "RLSMatrixAlgo.h" /* ����ϡ�����Ļ�������*/ 


void main() 
{ 
	RLSMatrix M;
	printf("���������M\n");
	InPutRLSMatrix(M);
	OutPutRLSMatrix(M);
    TransposeSMatrix(M);
	/*...................................
�������ݲ�����ɾ���˷�����*/
	RLSMatrix N1,N2;

	printf("\n------���������N1-----\n");
	InPutRLSMatrix(N1);
	OutPutRLSMatrix(N1);



//------����M��N1,N2�Ļ�-----
	RLSMatrix Q1,Q2;
	MultSMatrix(M,N1,Q1);
	printf("\n----M��N1�ĳ˻�Ϊ----\n");
	OutPutRLSMatrix(Q1);


} 
