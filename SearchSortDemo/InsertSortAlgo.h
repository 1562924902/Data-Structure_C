void InsertSort(SqList &L)
{ /* ��˳���L ��ֱ�Ӳ�������*/
int i,j;
for(i=2;i<=L.length;++i)
if LT(L.r[i].key,L.r[i-1].key) /* "<",�轫L.r[i]���������ӱ�*/
{
L.r[0]=L.r[i]; /* ����Ϊ�ڱ�*/
for(j=i-1;LT(L.r[0].key,L.r[j].key);--j)
L.r[j+1]=L.r[j]; /* ��¼����*/
L.r[j+1]=L.r[0]; /* ���뵽��ȷλ��*/
}
}

void BInsertSort(SqList &L)
{ /* ��˳���L ���۰�������� */
int i,j,m,low,high;
for(i=2;i<=L.length;++i)
{
L.r[0]=L.r[i]; /* ��L.r[i]�ݴ浽L.r[0] */
low=1;
high=i-1;
while(low<=high)
{ /* ��r[low..high]���۰������������λ��*/
m=(low+high)/2; /* �۰�*/
if LT(L.r[0].key,L.r[m].key)
high=m-1; /* ������ڵͰ���*/
else
low=m+1; /* ������ڸ߰���*/
}
for(j=i-1;j>=high+1;--j)
L.r[j+1]=L.r[j]; /* ��¼����*/
L.r[high+1]=L.r[0]; /* ����*/
}
}


//-----------ϣ������------------------
void ShellInsert(SqList &L,int dk){
	//��˳���L��һ������Ϊdk��ϣ����������
	for(int i=dk+1;i<=L.length;++i)
		if(L.r[i].key <L.r[i-dk].key)
		{
			L.r[0]=L.r[i];	//�ݴ���L.r[0]
			for(int j =i-dk; j>0&&L.r[0].key <L.r[j].key;j-=dk)
				L.r[j+dk]=L.r[j];	//��¼���ƣ�֪���ҵ�����λ��
			L.r[j+dk]=L.r[0];	//��r[0]��ԭr[i]�����뵽��ȷλ��
		}//if
}//ShellInsert

void ShellSort(SqList &L,int dt[],int t){
	//����������dt[0..t-1]��˳���L��t��ϣ������
	for(int k=0;k<t;++k)
		ShellInsert(L,dt[k]);	//һ������Ϊdt[t]��ϣ����������
}

























