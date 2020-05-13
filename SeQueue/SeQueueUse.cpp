#include "pubuse.h" /* 与实验一的意义相同*/ 
typedef char QElemType; /* 假设循环队列中元素是字符*/ 
#include "SeQueueDef.h" 
#include "SeQueueAlgo.h" 


void main() 
{ 
int i; 
QElemType d; 
SqQueue q; 
i=InitQueue(q); 
if(i) 
printf("成功地构造了一个空队列!\n");
printf("\n队列是否为空(0:空；1:非空)：%d",QueueEmpty(q));
printf("\n队列的最大长度为%d\n",MAXQSIZE-1);

//先让3个元素'A' 'B' 'C'依次进入队列,并查看队列长度
printf("\n让'A','B','C'进入队列\n");
EnQueue(q,'A'); 
EnQueue(q,'B'); 
EnQueue(q,'C'); 
printf("插入3 个元素'A','B','C'后,队列的长度为%d",QueueLength(q)); 
printf("\n队列是否已满(0:未满；1:满)：%d\n",QueueFull(q));

//再让1个元素'E' 进入队列,并查看队列是否已满
printf("\n在插入一个元素'D'");
EnQueue(q,'D');
printf("\n插入1个元素'D'后,队列的长度为%d",QueueLength(q)); 
printf("\n队列是否已满(0:未满；1:满)：%d\n",QueueFull(q));


//让4个元素依次出队列
printf("元素全部出队列：");
QElemType e;
for(int j=1;j<=MAXQSIZE-1;++j){
	DeQueue(q,e);
	printf("%c  ",e);
}
 
} 
