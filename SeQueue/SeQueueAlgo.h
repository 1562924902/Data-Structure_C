//-------循环队列基本算法----------
#define MAXQSIZE 5    //定义最大存储空间
Status InitQueue(SqQueue &Q){
	//构造一个空队列Q
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base)exit(OVERFLOW);//存储分配失败
	Q.front = Q.rear =0;
	return OK;
}

Status QueueEmpty(SqQueue Q){
	//如果队列中元素达到最大值-1
	//返回TRUE;
	if(Q.rear==Q.front) return FALSE;
	else return TRUE;
}
int QueueLength(SqQueue Q){
	//返回Q的元素个数，即队列的长度
	return(Q.rear - Q.front +MAXQSIZE)% MAXQSIZE;
}

Status QueueFull(SqQueue Q){
	//判断队列是否已满
	//满返回TURE，否则返回FALSE
	if(QueueLength(Q)==MAXQSIZE-1) return TRUE;
	else return FALSE;
}



Status EnQueue(SqQueue &Q,QElemType e){
	//插入元素e为Q的心的队尾元素
	if((Q.rear+1)%MAXQSIZE == Q.front) return ERROR;//
	Q.base[Q.rear] =e ;
	Q.rear = (Q.rear +1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e){
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
	//否则返回ERROR
	if(Q.front == Q.rear) return ERROR;
	e =Q.base[Q.front];
	Q.front = (Q.front +1) % MAXQSIZE;
	return OK;
}