//-------ѭ�����л����㷨----------
#define MAXQSIZE 5    //�������洢�ռ�
Status InitQueue(SqQueue &Q){
	//����һ���ն���Q
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base)exit(OVERFLOW);//�洢����ʧ��
	Q.front = Q.rear =0;
	return OK;
}

Status QueueEmpty(SqQueue Q){
	//���������Ԫ�شﵽ���ֵ-1
	//����TRUE;
	if(Q.rear==Q.front) return FALSE;
	else return TRUE;
}
int QueueLength(SqQueue Q){
	//����Q��Ԫ�ظ����������еĳ���
	return(Q.rear - Q.front +MAXQSIZE)% MAXQSIZE;
}

Status QueueFull(SqQueue Q){
	//�ж϶����Ƿ�����
	//������TURE�����򷵻�FALSE
	if(QueueLength(Q)==MAXQSIZE-1) return TRUE;
	else return FALSE;
}



Status EnQueue(SqQueue &Q,QElemType e){
	//����Ԫ��eΪQ���ĵĶ�βԪ��
	if((Q.rear+1)%MAXQSIZE == Q.front) return ERROR;//
	Q.base[Q.rear] =e ;
	Q.rear = (Q.rear +1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e){
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��
	//���򷵻�ERROR
	if(Q.front == Q.rear) return ERROR;
	e =Q.base[Q.front];
	Q.front = (Q.front +1) % MAXQSIZE;
	return OK;
}