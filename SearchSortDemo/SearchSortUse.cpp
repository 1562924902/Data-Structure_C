/* ����InsertSortAlgo.h ��SeqBinSearchAlgo.h �ĳ���*/
#include"pubuse.h" /* ͨ�ó��������ϵͳ����ԭ������*/
#include"compare.h" /* ������ֵ�͹ؼ��ֵıȽ�Լ���궨��*/
#include"ElemDef.h" /*�ǶԴ���ѯ/�����¼���������Ͷ���*/
#include "InsertSortAlgo.h" /* ˳����������ĺ���*/
#include "SeqBinSearchAlgo.h" /*��̬���ұ�Ļ�������*/
/*typedef int InfoType; �������������������*/
#define N 10
#define T 3
void print1(SqList L)
{ //�������˳���ÿ��Ԫ�صùؼ������������Ϣ��
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
List_Creat_Sq(st,N); /* ��ȫ�����������̬���ұ�st */
for(i=0;i<N;i++) /* ��l1.r ��ֵ*/
st.r[i+1]=d[i];
st.length=N;
l3=l2=l1=st; /* ����˳���l2��l3 ��l1 ��ͬ*/
printf("����ǰ:\n");
print1(st);
printf("\n");
printf("����������ҵĹؼ���: ");
scanf("%d",&s);
i=List_Search_Sq(st,s); /* ˳�����*/
if(i)
printf("%d\n",(*(st.r+i)).otherinfo);
else
printf("û�ҵ�\n");
InsertSort(l1);
printf("ֱ�Ӳ��������:\n");
print1(l1);
printf("\n") ;
BInsertSort(l2);
printf("�۰���������:\n");
print1(l2);
printf("\n") ;
printf("��������۰���ҵĹؼ���: ");
scanf("%d",&s);
j=List_BinSearch_Sq(l3,s);
if(j)
printf("������%d �Σ�\n",j);
else
printf("û�ҵ�\n");
}