 #include "pubuse.h" 
#define MAX_NAME 1 /* 顶点字符串的最大长度+1 */ 
typedef int InfoType; /* 存放网的权值*/ 
typedef char VertexType[MAX_NAME]; /* 字符串类型*/ 


#include"ALGraphDef.h" 
#include"ALGraphAlgo.h" 



void print(char *i) 
{ 
printf("%s ",i);
}

void main() 
{ 
ALGraph g; 
printf("请选择有向图\n"); 
CreateGraph(g); 
Display(g); 
printf("深度优先搜索的结果:\n"); 
DFSTraverse(g,print); 


//--------测试代码----------
printf("--------测试代码----------");
printf("\n广度优先搜索结果：\n");
Graph_BFS(g,print);
DestroyGraph(g); /* 销毁图*/ 

} 
