/* 以下的算法均是针对带表头结点的单链表*/ 
Status ListInit_Link(LinkList &L) 
{ /* 操作结果：构造一个空的线性表L */ 
L=(LinkList)malloc(sizeof(struct LNode)); /* 产生头结点,并使L 指向此头结点*/ 
if(!L) /* 存储分配失败*/ 
exit(OVERFLOW); 
L->next=NULL; /* 指针域为空*/ 
return OK; 
}

Status ListDestroy_Link (LinkList L) 
{ /* 初始条件：线性表L 已存在。*/ 
/* 操作结果：销毁线性表L */ 
LinkList q; 
while(L) 
{ 
q=L->next; 
free(L); 
L=q; 
}
return OK; 
}

Status ListClear_Link (LinkList L) /* 不改变L */ 
{ /* 初始条件：线性表L 已存在。*/ 
/* 操作结果：将L 重置为空表*/ 
LinkList p,q; 
p=L->next; /* p 指向第一个结点*/ 
while(p) /* 没到表尾*/ 
{ 
q=p->next; 
free(p); 
p=q; 
}
L->next=NULL; /* 头结点指针域为空*/ 
return OK; 
}

Status ListEmpty_Link (LinkList L) 
{ /* 初始条件：线性表L 已存在。*/ 
/* 操作结果：若L 为空表，则返回TRUE，否则返回FALSE */
if(L->next) /* 非空*/ 
return FALSE; 
else
return TRUE; 
}

int ListLength_Link (LinkList L) 
{ /* 初始条件：线性表L 已存在。*/ 
/* 操作结果：返回L 中数据元素个数*/ 
int i=0; 
LinkList p=L->next; /* p 指向第一个结点*/ 
while(p) /* 没到表尾*/ 
{ 
i++; 
p=p->next; 
}
return i; 
}

Status GetElem_Link (LinkList L,int i,ElemType &e) /* 算法2.8 */ 
{ /* 初始条件: L 为带头结点的单链表的头指针*/ 
/* 操作结果：当第i 个元素存在时,其值赋给e 并返回OK,否则返回ERROR */ 
int j=1; /* j 为计数器*/ 
LinkList p=L->next; /* p 指向第一个结点*/ 
while(p&&j<i) /* 顺指针向后查找,直到p 指向第i 个元素或p 为空*/ 
{ 
p=p->next; 
j++; 
}
if(!p||j>i) /* 第i 个元素不存在*/ 
return ERROR;
e=p->data; /* 取第i 个元素*/ 
return OK; 
}

int LocateElem_Link (LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)) 
{ /* 初始条件: 线性表L 已存在,compare()是数据元素判定函数(满足为1,否则为0) */ 
/* 操作结果: 返回L 中第1 个与e 满足关系compare()的数据元素的位序。*/ 
/* 若这样的数据元素不存在,则返回值为0 */ 
int i=0; 
LinkList p=L->next; 
while(p) 
{ 
i++; 
if(compare(p->data,e)) /* 找到这样的数据元素*/ 
return i; 
p=p->next; 
}
return 0; 
}

Status ListInsert_Link (LinkList L,int i,ElemType e) /* 算法2.9,不改变L */ 
{ /* 在带头结点的单链线性表L 中第i 个位置之前插入元素e */ 
int j=0; 
LinkList p=L,s; 
while(p&&j<i-1) /* 寻找第i-1 个结点*/ 
{ 
p=p->next; 
j++; 
}
if(!p||j>i-1) /* i 小于1 或者大于表长*/ 
return ERROR;
s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点*/ 
s->data=e; /* 插入L 中*/ 
s->next=p->next; 
p->next=s; 
return OK; 
}

Status ListDelete_Link (LinkList L,int i,ElemType &e) /* 算法2.10,不改变L */ 
{ /* 在带头结点的单链线性表L 中，删除第i 个元素,并由e 返回其值*/ 
int j=0; 
LinkList p=L,q; 
while(p->next&&j<i-1) /* 寻找第i 个结点,并令p 指向其前趋*/ 
{ 
p=p->next; 
j++; 
}
if(!p->next||j>i-1) /* 删除位置不合理*/ 
return ERROR; 
q=p->next; /* 删除并释放结点*/ 
p->next=q->next; 
e=q->data; 
free(q); 
return OK; 
}

Status ListTraverse_Link (LinkList L) 
{ /* 初始条件：线性表L 已存在*/ 
/* 操作结果:依次对L 的每个数据元素的值进行输出*/ 
LinkList p=L->next; 
while(p) 
{
printf("%d",p->data); 
p=p->next; 
}
printf("\n"); 
return OK; 
} 

void CreateList_Link (LinkList &L,int n) /* 算法2.11 */ 
{ /* 逆位序(插在表头)输入n 个元素的值，建立带表头结构的单链线性表L */ 
int i; 
LinkList p; 
L=(LinkList)malloc(sizeof(struct LNode)); 
L->next=NULL; /* 先建立一个带头结点的单链表*/ 
printf("请输入%d 个数据\n",n); 
for(i=n;i>0;--i) 
{ 
p=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点*/ 
scanf("%d",&p->data); /* 输入元素值*/ 
p->next=L->next; /* 插入到表头*/ 
L->next=p; 
} 
}

void CreateList2_Link (LinkList &L,int n) 
{ /* 正位序(插在表尾)输入n 个元素的值，建立带表头结构的单链线性表*/ 
int i; 
LinkList p,q; 
L=(LinkList)malloc(sizeof(struct LNode)); /* 生成头结点*/ 
L->next=NULL; 
q=L; 
printf("请输入%d 个数据\n",n); 
for(i=1;i<=n;i++)
{ 
p=(LinkList)malloc(sizeof(struct LNode)); 
scanf("%d",&p->data); 
q->next=p; 
q=q->next; 
}
p->next=NULL; 
} 

Status PriorElem_Link (LinkList L,ElemType cur_e,ElemType &pre_e) 
{ /* 初始条件: 线性表L 已存在*/
/* 操作结果: 若cur_e 是L 的数据元素,且不是第一个,则用pre_e 返回它的前驱, */
/* 返回OK;否则操作失败,pre_e 无定义,返回INFEASIBLE */
LinkList q,p=L->next; /* p 指向第一个结点*/
while(p->next) /* p 所指结点有后继*/
{
q=p->next; /* q 为p 的后继*/
if(q->data==cur_e)
{
pre_e=p->data;
return OK;
}
p=q; /* p 向后移*/
}
return INFEASIBLE;
}


Status NextElem_Link (LinkList L,ElemType cur_e,ElemType &next_e) 
{ /* 初始条件：线性表L 已存在*/
/* 操作结果：若cur_e 是L 的数据元素，且不是最后一个，则用next_e 返回它的后继， */
/* 返回OK;否则操作失败，next_e 无定义，返回INFEASIBLE */
LinkList p=L->next; /* p 指向第一个结点*/
while(p->next) /* p 所指结点有后继*/
{
if(p->data==cur_e)
{ next_e=p->next->data;
return OK;
}
p=p->next;
}
return INFEASIBLE;
}


void MergeList_Link (LinkList &La,LinkList &Lb,LinkList &Lc) 
{ /* 已知单链线性表La 和Lb 的元素按值非递减排列。*/
/* 归并La 和Lb 得到新的单链线性表Lc，Lc 的元素也按值非递减排列*/
LinkList pa=La->next,pb=Lb->next,pc;
Lc=pc=La; /* 用La 的头结点作为Lc 的头结点*/
while(pa&&pb)
if(pa->data<=pb->data)
{
pc->next=pa;
pc=pa;
pa=pa->next;
}
else
{
pc->next=pb;
pc=pb;
pb=pb->next;
}
pc->next=pa?pa:pb; /* 插入剩余段*/	
//free(La);   /* 释放La 的头结点*/
free(Lb); /* 释放Lb 的头结点*/
Lb=NULL;
}

void Sort_Link (LinkList &La) 
{ /*初始条件: 线性表La 已存在,La 的元素无序排列。*/
/* 操作结果：将La中所有元素排序，生成按值非递减排列的链表La*/
	int j;
	j=ListLength_Link(La);
	LinkList pa=La->next,pb=pa->next;
	for(int i=0;i<=j;i++)
		for(int k=0;k<j;k++)
		{
			if(pa->data <= pb->data)
			{
				int n;
				n=pa->data;
				pa->data=pb->data;
				pb->data=n;
			}
			pa=pa->next;
			pb=pb->next;
			while(!pa->next)
			{
				pa=La->next;
				pb=pa->next;
			}
		}
}