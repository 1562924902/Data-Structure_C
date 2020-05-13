Status ListInit_Sq(SqList &L) { /* �㷨2. 3 */
	/* �������������һ���յ�˳�����Ա�*/
	L. elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L. elem)
		exit(OVERFLOW); /* �洢����ʧ��*/
		L. length=0; /* �ձ���Ϊ0 */
	L. listsize=LIST_INIT_SIZE; /* ��ʼ�洢����*/
	return OK;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e) { /* �㷨2. 4 */
	/* ��ʼ������˳�����Ա�L �Ѵ��ڣ�1��i��ListLength(L)+1 */
	/* �����������L �е�i ��λ��֮ǰ�����µ�����Ԫ��e��L �ĳ��ȼ�1 */
	ElemType *newbase,*q,*p;
	if(i<1||i>L. length+1) /* i ֵ���Ϸ�*/
		return ERROR;
	if(L. length>=L. listsize) { /* ��ǰ�洢�ռ�����,���ӷ���*/
		newbase=(ElemType *)realloc(L. elem,(L. listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW); /* �洢����ʧ��*/
		L. elem=newbase; /* �»�ַ*/
		L. listsize+=LISTINCREMENT; /* ���Ӵ洢����*/
	}
	q=L. elem+i-1; /* q Ϊ����λ��*/
	for(p=L. elem+L. length-1; p>=q; --p) /* ����λ�ü�֮���Ԫ������*/
		*(p+1)=*p;
	*q=e; /* ����e */
	++L. length; /* ����1 */
	return OK;
}

Status ListDelete_Sq(SqList &L,int i,ElemType *e) { /* �㷨2. 5 */
	/* ��ʼ������˳�����Ա�L �Ѵ��ڣ�1��i��ListLength(L) */
	/* ���������ɾ��L �ĵ�i ������Ԫ�أ�����e ������ֵ��L �ĳ��ȼ�1 */
	ElemType *p,*q;
	if(i<1||i>L. length) /* i ֵ���Ϸ�*/
		return ERROR;
	p=L. elem+i-1; /* p Ϊ��ɾ��Ԫ�ص�λ��*/
	*e=*p; /* ��ɾ��Ԫ�ص�ֵ����e */
	q=L. elem+L. length-1; /* ��βԪ�ص�λ��*/
	for(++p; p<=q; ++p) /* ��ɾ��Ԫ��֮���Ԫ������*/
		*(p-1)=*p;
	L. length--; /* ����1 */
	return OK;
}

Status ListReverse_Sq(SqList &L) {
	/* ��ʼ������˳�����Ա�L �Ѵ���*/
	/* ������������ζ�L ������Ԫ�سɶԽ���*/
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
	/* ��ʼ������˳�����Ա�L �Ѵ���*/
	/* ������������ζ�L ������Ԫ�����*/
	printf("\n");
	for(int i=0; i<L. length; i++)
		printf("%d ", L. elem[i]);
	return OK;
}

int ListLength_Sq(SqList L) {
	/* ��ʼ������˳�����Ա�L �Ѵ���*/
	/* �������������L ������Ԫ�ظ���*/
	return L.length;
}

Status ListEmpty_Sq(SqList L) {
	/* ��ʼ������˳�����Ա�L �Ѵ���*/
	/* �����������L Ϊ�ձ��򷵻�TRUE�����򷵻�FALSE*/
	if(L.length==0) return FALSE;
	else return TRUE;
}

Status ListIndex_Sq(SqList &L,int i,ElemType e){
	//˳�����Ա�L �Ѵ��ڣ�Ԫ��λ��Ϊi����1��i��ListLength(L) 
	//����������ҵ�L �е�i ������Ԫ�ص�ֵ,����e������ֵ 
    	int p;
	if(i<1||i>L. length) /* i ֵ���Ϸ�*/
		return ERROR;
	e=L. elem[i-1]; 
	return e;
}

Status LocateElem_Sq(SqList &L,ElemType e){
	//��ʼ������˳�����Ա�L �Ѵ��ڣ�Ԫ��ֵΪe�� 
	//�������������L ������Ԫ��ֵΪe ��Ԫ��λ�ã�
	for(int i=0;i<=L.length;i++)
		if(L.elem[i]==e)
		{
			return i+1;
			break;
		}
}    
 
Status MaxElem_Sq(SqList &L){
	//��ʼ������˳�����Ա�L �Ѵ��ڣ� 
	//�������������L ����������Ԫ��ֵ��
	int e=0;
	for(int i=0;i<=L.length;i++)if(L.elem[i]>=e)e=L.elem[i];
	return e;	
	}