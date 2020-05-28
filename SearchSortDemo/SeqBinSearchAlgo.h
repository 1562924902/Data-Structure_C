Status List_Creat_Sq(SqList &L,int n)
{
L.r=(sortstruct *)calloc(n+1,sizeof(sortstruct));
if(!L.r)
return ERROR;
return OK;
}

void Ascend(SqList &L)
{ /* �ؽ���̬���ұ�Ϊ���ؼ��ַǽ�������*/
int i,j,k;
for(i=1;i<L.length;i++)
{
k=i;
L.r[0]=L.r[i]; /* ���Ƚ�ֵ��[0]��Ԫ*/
for(j=i+1;j<=L.length;j++)
if LT(L.r[j].key,L.r[0].key)
{
k=j;
L.r[0]=L.r[j];
}
if(k!=i) /* �и�С��ֵ�򽻻�*/
{
L.r[k]=L.r[i];
L.r[i]=L.r[0];
}
}
}

Status List_Creat_Ord(SqList &L,int n)
{ /* �������: ����һ����n ������Ԫ�صľ�̬���ؼ��ַǽ�����ұ�L */
/* ��������ȫ������r */
Status f;
f=List_Creat_Sq(L,n);
if(f)
Ascend(L);
return f;
}

Status List_Destroy_Sq(SqList &L)
{ /* ��ʼ����: ��̬���ұ�L ���ڡ��������: ���ٱ�L */
free(L.r);
L.r=NULL;
L.length=0;
return OK;
}

int List_Search_Sq(SqList L,KeyType key)/*˳�����*/
{ /* ��˳���L ��˳�������ؼ��ֵ���key ������Ԫ�ء����ҵ�������ֵΪ*/
/* ��Ԫ���ڱ��е�λ�ã�����Ϊ0���㷨9.1 */
int i;
L.r[0].key=key; /* �ڱ�*/
for(i=L.length;!EQ(L.r[i].key,key);--i); /* �Ӻ���ǰ��*/
return i; /* �Ҳ���ʱ��i Ϊ0 */
}

int List_BinSearch_Sq(SqList L,KeyType key)
{ /* �������L ���۰������ؼ��ֵ���key ������Ԫ�ء����ҵ�������ֵΪ*/
/* ��Ԫ���ڱ��е�λ�ã�����Ϊ0���㷨9.2 */
int low,high,mid,i=0;
low=1; /* �������ֵ*/
high=L.length;
while(low<=high)
{
mid=(low+high)/2;
if EQ(key,L.r[mid].key) /* �ҵ�����Ԫ��*/
return i+1;
else if LT(key,L.r[mid].key)
high=mid-1; /* ������ǰ��������в���*/
else
low=mid+1; /* �����ں��������в���*/
i++;
}
return 0; /* ˳����в����ڴ���Ԫ��*/
}

Status Traverse(SqList L,void(*Visit)(sortstruct))
{ /* ��ʼ����: ��̬���ұ�L ���ڣ�Visit()�Ƕ�Ԫ�ز�����Ӧ�ú���*/
/* �������: ��˳���L ��ÿ��Ԫ�ص��ú���Visit()һ���ҽ�һ�Ρ�*/
/* һ��Visit()ʧ�ܣ������ʧ��*/
sortstruct *p;
int i;
p=++L.r; /* p ָ���һ��Ԫ��*/
for(i=1;i<=L.length;i++)
Visit(*p++);
return OK;
}


