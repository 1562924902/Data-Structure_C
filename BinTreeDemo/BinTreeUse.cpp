/* BinTreeUse.cpp ����BinTreeAlgo.h ��������,������������ѡ����������(��һ�ַ���) */ 
#include"pubuse.h" /* ��ʵ��һ��������ͬ*/ 

/* ���������������Ϳ��������ַ��ͣ�Ҳ���������ͣ����ڳ�����ʹ���������������жϺͿ���*/ 
#define CHAR /* �ַ��ͣ� �����ǲ����ַ�����Ϊ��������*/ 
//-------------------------------------
/* #define INT /* ���ͣ�����ѡһ�� */ 
#ifdef CHAR 
typedef char TElemType; 
TElemType Nil=' '; /* �ַ����Կո��Ϊ��*/
#endif 

#ifdef INT 
typedef int TElemType; 
TElemType Nil=0; /* ������0 Ϊ��*/ 
#endif 
//---------------------------------------
#include"BinTreeDef.h" /* ��������ʽ�洢�ṹ����*/ 
#include"BinTreeAlgo.h" /* �����������㷨����չ�㷨����*/ 
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
/* 1---����ʵ���㷨����֤*/ 
InitBiTree(T); 
printf("����ն�������,���շ�%d(1:��0:��)\n",BiTreeEmpty(T)); 
e1=Root(T); 
if(e1!=Nil) 
#ifdef CHAR 
printf("�������ĸ�Ϊ: %c\n",e1); 
#endif 
#ifdef INT 
printf("�������ĸ�Ϊ: %d\n",e1); 
#endif 
else
printf("���գ��޸�\n"); 
#ifdef CHAR 
printf("���������������(��:ab �����ո��ʾa Ϊ�����,b Ϊ�������Ķ�����)\n"); 
#endif 
#ifdef INT 
printf("���������������(��:1 2 0 0 0 ��ʾ1 Ϊ�����,2 Ϊ�������Ķ�����)\n"); 
#endif
CreateBiTree(T); 
printf("������������,���շ�%d(1:��0:��) \n",BiTreeEmpty(T)); 
e1=Root(T); 
if(e1!=Nil) 
#ifdef CHAR 
printf("�������ĸ�Ϊ: %c\n",e1); 
#endif 
#ifdef INT 
printf("�������ĸ�Ϊ: %d\n",e1); 
#endif 
else
printf("���գ��޸�\n"); 
printf("����ݹ����������:\n"); 
InOrderTraverse(T,visitT); 
printf("\n����ݹ����������:\n"); 
PostOrderTraverse(T,visitT); 

printf("\n�����������Ϊ:\n");
Deepth(T);

}