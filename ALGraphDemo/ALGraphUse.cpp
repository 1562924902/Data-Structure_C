 #include "pubuse.h" 
#define MAX_NAME 1 /* �����ַ�������󳤶�+1 */ 
typedef int InfoType; /* �������Ȩֵ*/ 
typedef char VertexType[MAX_NAME]; /* �ַ�������*/ 


#include"ALGraphDef.h" 
#include"ALGraphAlgo.h" 



void print(char *i) 
{ 
printf("%s ",i);
}

void main() 
{ 
ALGraph g; 
printf("��ѡ������ͼ\n"); 
CreateGraph(g); 
Display(g); 
printf("������������Ľ��:\n"); 
DFSTraverse(g,print); 


//--------���Դ���----------
printf("--------���Դ���----------");
printf("\n����������������\n");
Graph_BFS(g,print);
DestroyGraph(g); /* ����ͼ*/ 

} 
