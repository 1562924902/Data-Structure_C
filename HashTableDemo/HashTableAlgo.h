

int InitHashTable(HashTable *H)
{
	int i,m;
	m=size;
	H->count=m;
	H->elem=(ElemType*)malloc(m*sizeof(ElemType));
		for(i=0;i<m;i++){//初始化
		H->elem[i].key = NULLKEY;
		H->elem[i].otherinfo = -1;
		}
	return TRUE;
	if(!H->elem) return ERROR;
 }
 
 
 
//Hash函数:使用除留余数法
 int Hash(int key)
 {//带除留余法
 	return key%size;
  } 
  
  
//插入关键字到HashTable
  void InsertHash(HashTable *H,int key)
  {
  	int addr=Hash(key);			//计算key对应地址
  	while(H->elem[addr].key != NULLKEY)
  		addr=(addr+1)%size;
  	H->elem[addr].key = key;
	H->elem[addr].otherinfo = addr;			//利用otherinfo存储key存储的位置
   } 
  
  

int SearchHash(HashTable H,int key,int *addr)
{
	*addr=Hash(key);
	while(H.elem[*addr].key!=key)
	{
		*addr=(*addr+1)%size;
		if(H.elem[*addr].key ==NULLKEY ||*addr == Hash(key))
		{
			return FALSE;
		}
	}
	return *addr;
 } 

