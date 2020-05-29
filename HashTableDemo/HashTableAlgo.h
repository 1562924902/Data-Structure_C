

int InitHashTable(HashTable *H)
{
	int i,m;
	m=size;
	H->count=m;
	H->elem=(ElemType*)malloc(m*sizeof(ElemType));
		for(i=0;i<m;i++){
		H->elem[i].key = NULLKEY;
		H->elem[i].otherinfo = -1;
		}
	return TRUE;
	if(!H->elem) return ERROR;
 }
 
 

 int Hash(int key)
 {
	key *=key;
	return key/10000;
  } 
  
  

  void InsertHash(HashTable *H,int key)
  {
  	int addr=Hash(key);			
  	while(H->elem[addr].key != NULLKEY)
  		addr=(addr+1)%size;
  	H->elem[addr].key = key;
	H->elem[addr].otherinfo = addr;			
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

