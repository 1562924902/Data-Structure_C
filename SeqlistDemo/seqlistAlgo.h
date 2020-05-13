Status ListInit_Sq(SqList &L) { /* 算法2. 3 */
	/* 操作结果：构造一个空的顺序线性表*/
	L. elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L. elem)
		exit(OVERFLOW); /* 存储分配失败*/
		L. length=0; /* 空表长度为0 */
	L. listsize=LIST_INIT_SIZE; /* 初始存储容量*/
	return OK;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e) { /* 算法2. 4 */
	/* 初始条件：顺序线性表L 已存在，1≤i≤ListLength(L)+1 */
	/* 操作结果：在L 中第i 个位置之前插入新的数据元素e，L 的长度加1 */
	ElemType *newbase,*q,*p;
	if(i<1||i>L. length+1) /* i 值不合法*/
		return ERROR;
	if(L. length>=L. listsize) { /* 当前存储空间已满,增加分配*/
		newbase=(ElemType *)realloc(L. elem,(L. listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW); /* 存储分配失败*/
		L. elem=newbase; /* 新基址*/
		L. listsize+=LISTINCREMENT; /* 增加存储容量*/
	}
	q=L. elem+i-1; /* q 为插入位置*/
	for(p=L. elem+L. length-1; p>=q; --p) /* 插入位置及之后的元素右移*/
		*(p+1)=*p;
	*q=e; /* 插入e */
	++L. length; /* 表长增1 */
	return OK;
}

Status ListDelete_Sq(SqList &L,int i,ElemType *e) { /* 算法2. 5 */
	/* 初始条件：顺序线性表L 已存在，1≤i≤ListLength(L) */
	/* 操作结果：删除L 的第i 个数据元素，并用e 返回其值，L 的长度减1 */
	ElemType *p,*q;
	if(i<1||i>L. length) /* i 值不合法*/
		return ERROR;
	p=L. elem+i-1; /* p 为被删除元素的位置*/
	*e=*p; /* 被删除元素的值赋给e */
	q=L. elem+L. length-1; /* 表尾元素的位置*/
	for(++p; p<=q; ++p) /* 被删除元素之后的元素左移*/
		*(p-1)=*p;
	L. length--; /* 表长减1 */
	return OK;
}

Status ListReverse_Sq(SqList &L) {
	/* 初始条件：顺序线性表L 已存在*/
	/* 操作结果：依次对L 的数据元素成对交换*/
	ElemType t;
	int i;
	for(i=0; i<L. length/2; i++) {
		t=L. elem[i];
		L. elem[i]= L. elem[L. length-i-1];
		L. elem[L. length-i-1]=t;
	}
	printf("\n");
	return OK;
}

Status ListPrint_Sq(SqList L) {
	/* 初始条件：顺序线性表L 已存在*/
	/* 操作结果：依次对L 的数据元素输出*/
	printf("\n");
	for(int i=0; i<L. length; i++)
		printf("%d ", L. elem[i]);
	return OK;
}

int ListLength_Sq(SqList L) {
	/* 初始条件：顺序线性表L 已存在*/
	/* 操作结果：返回L 中数据元素个数*/
	return L.length;
}

Status ListEmpty_Sq(SqList L) {
	/* 初始条件：顺序线性表L 已存在*/
	/* 操作结果：若L 为空表，则返回TRUE，否则返回FALSE*/
	if(L.length==0) return FALSE;
	else return TRUE;
}

Status ListIndex_Sq(SqList &L,int i,ElemType e){
	//顺序线性表L 已存在，元素位置为i，且1≤i≤ListLength(L) 
	//操作结果：找到L 中第i 个数据元素的值,并用e返回其值 
    	int p;
	if(i<1||i>L. length) /* i 值不合法*/
		return ERROR;
	e=L. elem[i-1]; 
	return e;
}

Status LocateElem_Sq(SqList &L,ElemType e){
	//初始条件：顺序线性表L 已存在，元素值为e； 
	//操作结果：返回L 中数据元素值为e 的元素位置；
	for(int i=0;i<=L.length;i++)
		if(L.elem[i]==e)
		{
			return i+1;
			break;
		}
}    
 
Status MaxElem_Sq(SqList &L){
	//初始条件：顺序线性表L 已存在， 
	//操作结果：返回L 中最大的数据元素值；
	int e=0;
	for(int i=0;i<=L.length;i++)if(L.elem[i]>=e)e=L.elem[i];
	return e;	
	}