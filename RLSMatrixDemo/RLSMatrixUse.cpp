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
	printf("����M��ת�þ���Ϊ:\n");
	TransposeSMatrix(M);
    OutPutRLSMatrix(M);


	/*...................................
�������ݲ�����ɾ���˷�����*/
	printf("----------ϡ�����˷�����-----------");
	RLSMatrix N1,N2,Q;
	printf("\n------���������N1-----\n");
	InPutRLSMatrix(N1);
	OutPutRLSMatrix(N1);
	printf("\n------���������N2-----\n");
	InPutRLSMatrix(N2);
	OutPutRLSMatrix(N2);

	
//------����N1��N2�Ļ�-----
	printf("\n----N1��N2�ĳ˻�Ϊ----\n");
	MultSMatrix(N1,N2,Q);
	OutPutRLSMatrix(Q);
	}