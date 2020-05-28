Status List_Creat_Sq(SqList &L,int n)
{
L.r=(sortstruct *)calloc(n+1,sizeof(sortstruct));
if(!L.r)
return ERROR;
return OK;
}

void Ascend(SqList &L)
{ /* 重建静态查找表为按关键字非降序排序*/
int i,j,k;
for(i=1;i<L.length;i++)
{
k=i;
L.r[0]=L.r[i]; /* 待比较值存[0]单元*/
for(j=i+1;j<=L.length;j++)
if LT(L.r[j].key,L.r[0].key)
{
k=j;
L.r[0]=L.r[j];
}
if(k!=i) /* 有更小的值则交换*/
{
L.r[k]=L.r[i];
L.r[i]=L.r[0];
}
}
}

Status List_Creat_Ord(SqList &L,int n)
{ /* 操作结果: 构造一个含n 个数据元素的静态按关键字非降序查找表L */
/* 数据来自全局数组r */
Status f;
f=List_Creat_Sq(L,n);
if(f)
Ascend(L);
return f;
}

Status List_Destroy_Sq(SqList &L)
{ /* 初始条件: 静态查找表L 存在。操作结果: 销毁表L */
free(L.r);
L.r=NULL;
L.length=0;
return OK;
}

int List_Search_Sq(SqList L,KeyType key)/*顺序查找*/
{ /* 在顺序表L 中顺序查找其关键字等于key 的数据元素。若找到，则函数值为*/
/* 该元素在表中的位置，否则为0。算法9.1 */
int i;
L.r[0].key=key; /* 哨兵*/
for(i=L.length;!EQ(L.r[i].key,key);--i); /* 从后往前找*/
return i; /* 找不到时，i 为0 */
}

int List_BinSearch_Sq(SqList L,KeyType key)
{ /* 在有序表L 中折半查找其关键字等于key 的数据元素。若找到，则函数值为*/
/* 该元素在表中的位置，否则为0。算法9.2 */
int low,high,mid,i=0;
low=1; /* 置区间初值*/
high=L.length;
while(low<=high)
{
mid=(low+high)/2;
if EQ(key,L.r[mid].key) /* 找到待查元素*/
return i+1;
else if LT(key,L.r[mid].key)
high=mid-1; /* 继续在前半区间进行查找*/
else
low=mid+1; /* 继续在后半区间进行查找*/
i++;
}
return 0; /* 顺序表中不存在待查元素*/
}

Status Traverse(SqList L,void(*Visit)(sortstruct))
{ /* 初始条件: 静态查找表L 存在，Visit()是对元素操作的应用函数*/
/* 操作结果: 按顺序对L 的每个元素调用函数Visit()一次且仅一次。*/
/* 一旦Visit()失败，则操作失败*/
sortstruct *p;
int i;
p=++L.r; /* p 指向第一个元素*/
for(i=1;i<=L.length;i++)
Visit(*p++);
return OK;
}


