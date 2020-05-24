/* BinTreeAlgo.h �������Ķ�������洢(�洢�ṹ��BinTreeDef.h ����)�Ļ�������*/ 

Status InitBiTree(BiTree &T) 
{ /* �������: ����ն�����T */ 
T=NULL; 
return OK; 
}

void DestroyBiTree(BiTree &T) 
{ /* ��ʼ����: ������T ���ڡ��������: ���ٶ�����T */ 
if(T) /* �ǿ���*/ 
{ 
if(T->lchild) /* ������*/ 
DestroyBiTree(T->lchild); /* ������������*/ 
if(T->rchild) /* ���Һ���*/ 
DestroyBiTree(T->rchild); /* �����Һ�������*/ 
free(T); /* �ͷŸ����*/ 
T=NULL; /* ��ָ�븳0 */ 
} 
}

#define ClearBiTree DestroyBiTree 

void CreateBiTree(BiTree &T) 
{ /* �������������������н���ֵ����Ϊ�ַ��ͻ����ͣ���������*/ 
/* ���壩��������������ʾ�Ķ�����T������Nil ��ʾ�գ��ӣ������иĶ�*/ 
TElemType ch; 
#ifdef CHAR 
scanf("%c",&ch); 
#endif 
#ifdef INT 
scanf("%d",&ch); 
#endif 
if(ch==Nil) /* ��*/ 
T=NULL; 
else 
{ 
T=(BiTree)malloc(sizeof(BiTNode)); 
if(!T) 
exit(OVERFLOW); 
T->data=ch; /* ���ɸ����*/ 
CreateBiTree(T->lchild); /* ����������*/ 
CreateBiTree(T->rchild); /* ����������*/ 
} 
}

Status BiTreeEmpty(BiTree T) 
{ /* ��ʼ����: ������T ����*/ 
/* �������: ��T Ϊ�ն�����,�򷵻�TRUE,����FALSE */ 
if(T) 
return FALSE; 
else
return TRUE; 
}


TElemType Root(BiTree T) 
{ /* ��ʼ����: ������T ���ڡ��������: ����T �ĸ�*/ 
if(BiTreeEmpty(T)) 
return Nil; 
else
return T->data; 
}
 
TElemType Value(BiTree p) 
{ /* ��ʼ����: ������T ���ڣ�p ָ��T ��ĳ�����*/ 
/* �������: ����p ��ָ����ֵ*/ 
return p->data; 
}

void Assign(BiTree p,TElemType value) 
{ /* ��p ��ָ��㸳ֵΪvalue */ 
p->data=value; 
}

void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType)) 
{ /* ��ʼ����: ������T ����,Visit �ǶԽ�������Ӧ�ú������㷨6.1���иĶ�*/ 
/* �������: ����ݹ����T,��ÿ�������ú���Visit һ���ҽ�һ��*/ 
if(T) /* T ����*/ 
{ 
Visit(T->data); /* �ȷ��ʸ����*/ 
PreOrderTraverse(T->lchild,Visit); /* ���������������*/ 
PreOrderTraverse(T->rchild,Visit); /* ����������������*/ 
} 
}

void InOrderTraverse(BiTree T,Status(*Visit)(TElemType)) 
{ /* ��ʼ����: ������T ����,Visit �ǶԽ�������Ӧ�ú���*/ 
/* �������: ����ݹ����T,��ÿ�������ú���Visit һ���ҽ�һ��*/ 
if(T) 
{ 
InOrderTraverse(T->lchild,Visit); /* ���������������*/ 
Visit(T->data); /* �ٷ��ʸ����*/ 
InOrderTraverse(T->rchild,Visit); /* ����������������*/ 
} 
} 

void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType)) 
{ /* ��ʼ����: ������T ����,Visit �ǶԽ�������Ӧ�ú���*/
/* �������: ����ݹ����T,��ÿ�������ú���Visit һ���ҽ�һ��*/ 
if(T) /* T ����*/ 
{ 
PostOrderTraverse(T->lchild,Visit); /* �Ⱥ������������*/ 
PostOrderTraverse(T->rchild,Visit); /* �ٺ������������*/ 
Visit(T->data); /* �����ʸ����*/ 
} 
} 


int Deepth(BiTree T)
{//���������T�����
	int m,n;
	if(T==NULL) return 0; //����ǿ��������Ϊ0���ݹ����
	else
{
	m=Deepth(T->lchild);//�ݹ���������������Ϊm
	n=Deepth(T->rchild);//�ݹ���������������Ϊn
	if(m>n) return (m+1);//�����������Ϊm��n�Ľϴ��߼�1
	else return (n+1);
}
}

Status StackInOrderTraverse(BiTree T,Status(*Visit)(TElemType)){
	//���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
	//�������������T�ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
	SqStack S;
	InitStack(S);
	Push(S,T);   //��ָ���ջ
	BiTree p = T;
	while(!StackEmpty(S)){
		while(GetTop(S,p)&&p) Push(S,p->lchild);  //�����ߵ���ͷ
		Pop(S,p);			 //��ָ����ջ
		if(!StackEmpty(S)){  //���ʽڵ㣬����һ��
			Pop(S,p); if(!Visit(p->data)) return ERROR;
			Push(S,p->rchild);
		}//if
	}//while
	return OK;
}//StackInOrderTraverse

