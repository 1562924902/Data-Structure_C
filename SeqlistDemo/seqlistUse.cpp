#include"pubuse.h" /* ʵ��ͨ�ó����Ķ��壬����ϵͳ����������*/ 
typedef int ElemType; /*ʵ��һ�������Ĳ���,��int ���ض���Ϊͨ�õ�ElemType ������*/ 
#include"seqlistDef.h" /* �������Ա�Ķ�̬����˳��洢�ṹ����*/ 
#include"seqlistAlgo.h" /* ����˳���Ļ����㷨����*/ 
void main() 
{ 
	SqList L; 
	Status i; 
	int j; 
	ElemType t; 
	ElemType e;
/* ����һ��Ҫ��ʼ��˳���*/ 
i=ListInit_Sq(L);
if(i==1) /* �����ձ�L �ɹ�*/ 
for(j=1;j<=5;j++) /* �ڱ�L �в���5 ��Ԫ�أ�ÿ��Ԫ�ص�ֵ�ֱ�Ϊ2��4��6��8��10 */ 
i=ListInsert_Sq(L,j,2*j); 

ListPrint_Sq(L); /*����һ�²���Ľ���������L ������*/ 
ListInsert_Sq(L,2,20);/* ���ָ�������λ�ã������ڵڶ���Ԫ��ǰ�����µ�Ԫ�أ���ֵΪ20 */ 
ListDelete_Sq(L,4,&t);/* ���ָ��ɾ����λ�ã�����Ե��ĸ�Ԫ�ؽ���ɾ��*/ 
printf("\n The Deleted value is %d",t);/* ����һ��ɾ����Ԫ�ص�ֵ*/ 
ListPrint_Sq(L);/* ����һ�²����ɾ����Ľ���������La ������*/

ListReverse_Sq(L);/* ��˳���La ������Ԫ�ؽ�������*/ 
ListPrint_Sq(L);/* ����һ������Ľ���������L ������*/ 
printf("\n The List length is %d",ListLength_Sq(L));
printf("\n The List empty is %d\n",ListEmpty_Sq(L));

//----------���Դ���---------- 
printf("\n--------���Դ���----------");
printf("\n The List Max number is %d",MaxElem_Sq(L));//������Ԫ��
printf("\n the third number is %d",GetElem_Sq(L,3,e));
printf("\n 20 �ǵ�%d����",LocateElem_Sq(L,4));
}