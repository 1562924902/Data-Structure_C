/* linlistUse.cpp ��Ҫʵ���㷨2.9��2.10��2.11��2.12�ĳ���*/ 
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
	printf("���ǵݼ�˳��, "); 
	CreateList2_Link (La,n); /* ��λ������n ��Ԫ�ص�ֵ,����һ��������*/ 
	printf("La="); /* �������La ������*/ 

	ListTraverse_Link (La); 
	printf("���ǵ���˳��, "); 
	CreateList_Link (Lb,n); /* ��λ������n ��Ԫ�ص�ֵ*/ 
	printf("Lb="); /* �������Lb ������*/ 
	ListTraverse_Link (Lb); 
	MergeList_Link (La,Lb,Lc); /* ���ǵݼ�˳��鲢La ��Lb,�õ��±�Lc */ 
	printf("Lc="); /* �������Lc ������*/
	ListTraverse_Link (Lc); 

	/* �㷨2.9 �Ĳ���*/ 
	printf("\n enter insert location and value : "); 
	scanf("%d %d",&i,&e); 
	ListInsert_Link (Lc,i,e); 
	/* ��Lc �����е�i ����㴦����һ���µĽ�㣬��ֵΪe;*/ 
	printf("Lc="); /* �������Lc ������*/ 
	ListTraverse_Link (Lc); 

	/* �㷨2.10 �Ĳ���*/ 
	printf("\n enter deletd location : "); 
	scanf("%d",&i); 
	ListDelete_Link (Lc,i,e); /* ��Lc ������ɾ����i ����㣬��ֵΪ���ظ�e ����*/ 
	printf("The Deleted e=%d\n",e); /* �����ɾ��������*/ 
	printf("Lc="); /* �������Lc ������*/ 
	ListTraverse_Link (Lc); 

	/*...................................
	�������ݲ�����ɵ�Sort_Link����*/
	printf("Lc�ķǵ���˳��Ϊ:");
	Sort_Link(Lc);
	ListTraverse_Link (Lc); 
}
