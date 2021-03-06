void InsertSort(SqList &L)
{ /* 对顺序表L 作直接插入排序。*/
int i,j;
for(i=2;i<=L.length;++i)
if LT(L.r[i].key,L.r[i-1].key) /* "<",需将L.r[i]插入有序子表*/
{
L.r[0]=L.r[i]; /* 复制为哨兵*/
for(j=i-1;LT(L.r[0].key,L.r[j].key);--j)
L.r[j+1]=L.r[j]; /* 记录后移*/
L.r[j+1]=L.r[0]; /* 插入到正确位置*/
}
}

void BInsertSort(SqList &L)
{ /* 对顺序表L 作折半插入排序。 */
int i,j,m,low,high;
for(i=2;i<=L.length;++i)
{
L.r[0]=L.r[i]; /* 将L.r[i]暂存到L.r[0] */
low=1;
high=i-1;
while(low<=high)
{ /* 在r[low..high]中折半查找有序插入的位置*/
m=(low+high)/2; /* 折半*/
if LT(L.r[0].key,L.r[m].key)
high=m-1; /* 插入点在低半区*/
else
low=m+1; /* 插入点在高半区*/
}
for(j=i-1;j>=high+1;--j)
L.r[j+1]=L.r[j]; /* 记录后移*/
L.r[high+1]=L.r[0]; /* 插入*/
}
}


//-----------希尔排序------------------
void ShellInsert(SqList &L,int dk){
	//对顺序表L做一趟增量为dk的希尔插入排序
	for(int i=dk+1;i<=L.length;++i)
		if(L.r[i].key <L.r[i-dk].key)
		{
			L.r[0]=L.r[i];	//暂存在L.r[0]
			for(int j =i-dk; j>0&&L.r[0].key <L.r[j].key;j-=dk)
				L.r[j+dk]=L.r[j];	//记录后移，知道找到插入位置
			L.r[j+dk]=L.r[0];	//将r[0]即原r[i]，插入到正确位置
		}//if
}//ShellInsert

void ShellSort(SqList &L,int dt[],int t){
	//按增量序列dt[0..t-1]对顺序表L做t趟希尔排序
	for(int k=0;k<t;++k)
		ShellInsert(L,dt[k]);	//一趟增量为dt[t]的希尔插入排序
}

























