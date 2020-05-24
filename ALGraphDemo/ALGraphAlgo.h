
int LocateVex(ALGraph G,VertexType u) 
{ /* ��ʼ����: ͼG ����,u ��G �ж�������ͬ����*/ 
/* �������: ��G �д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */ 
int i; 
for(i=0;i<G.vexnum;++i) 
if(strcmp(u,G.vertices[i].data)==0) 
return i; 
return -1; 
}

Status CreateGraph(ALGraph &G) 
{ /* �����ڽӱ�洢�ṹ,����û�������Ϣ��ͼG(��һ����������4 ��ͼ) */ 
int i,j,k; 
int w; /* Ȩֵ*/ 
VertexType va,vb; 
ArcNode *p; 
printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): "); 
scanf("%d",&(G.kind));
printf("������ͼ�Ķ�����,����: "); 
scanf("%d,%d",&(G.vexnum),&(G.arcnum)); 
printf("������%d �������ֵ(%d ���ַ�):\n",G.vexnum,MAX_NAME); 
for(i=0;i<G.vexnum;++i) /* ���춥������*/ 
{ 
scanf("%s",G.vertices[i].data); 
G.vertices[i].firstarc=NULL; 
}


if(G.kind==1||G.kind==3) /* ��*/ 
printf("��˳������ÿ����(��)��Ȩֵ����β�ͻ�ͷ(�Կո���Ϊ���):\n"); 
else /* ͼ*/ 
printf("��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n"); 

for(k=0;k<G.arcnum;++k) /* �����������*/ 
{ 
if(G.kind==1||G.kind==3) /* ��*/ 
scanf("%d%s%s",&w,&va,&vb); 
else /* ͼ*/ 
scanf("%s%s",&va,&vb); 
i=LocateVex(G,va); /* ��β*/ 
j=LocateVex(G,vb); /* ��ͷ*/ 
p=(ArcNode*)malloc(sizeof(ArcNode)); 
p->adjvex=j; 
if(G.kind==1||G.kind==3) /* ��*/ 
{ 
p->info=(int *)malloc(sizeof(int)); 
*(p->info)=w; 
}
else
p->info=NULL; /* ͼ*/ 
p->nextarc=G.vertices[i].firstarc; /* ���ڱ�ͷ*/ 
G.vertices[i].firstarc=p;
if(G.kind>=2) /* ����ͼ����,�����ڶ�������*/ 
{ 
p=(ArcNode*)malloc(sizeof(ArcNode)); 
p->adjvex=i; 
if(G.kind==3) /* ������*/ 
{ 
p->info=(int*)malloc(sizeof(int)); 
*(p->info)=w; 
}
else
p->info=NULL; /* ����ͼ*/ 
p->nextarc=G.vertices[j].firstarc; /* ���ڱ�ͷ*/ 
G.vertices[j].firstarc=p; 
} 
}
return OK; 
}

void DestroyGraph(ALGraph &G) 
{ /* ��ʼ����: ͼG ���ڡ��������: ����ͼG */ 
int i; 
ArcNode *p,*q; 
G.vexnum=0; 
G.arcnum=0; 
for(i=0;i<G.vexnum;++i) 
{ 
p=G.vertices[i].firstarc; 
while(p) 
{ 
q=p->nextarc; 
if(G.kind%2) /* ��*/
free(p->info); 
free(p); 
p=q; 
} 
} 
}

VertexType* GetVex(ALGraph G,int v) 
{ /* ��ʼ����: ͼG ����,v ��G ��ĳ���������š��������: ����v ��ֵ*/ 
if(v>=G.vexnum||v<0) 
exit(ERROR); 
return &G.vertices[v].data; 
}

int FirstAdjVex(ALGraph G,VertexType v) 
{ /* ��ʼ����: ͼG ����,v ��G ��ĳ������*/ 
/* �������: ����v �ĵ�һ���ڽӶ������š���������G ��û���ڽӶ���,�򷵻�-1 */ 
ArcNode *p; 
int v1; 
v1=LocateVex(G,v); /* v1 Ϊ����v ��ͼG �е����*/ 
p=G.vertices[v1].firstarc; 
if(p) 
return p->adjvex; 
else
return -1; 
}

int NextAdjVex(ALGraph G,VertexType v,VertexType w) 
{ /* ��ʼ����: ͼG ����,v ��G ��ĳ������,w ��v ���ڽӶ���*/ 
/* �������: ����v ��(�����w ��)��һ���ڽӶ������š�*/ 
/* ��w ��v �����һ���ڽӵ�,�򷵻�-1 */
ArcNode *p; 
int v1,w1; 
v1=LocateVex(G,v); /* v1 Ϊ����v ��ͼG �е����*/ 
w1=LocateVex(G,w); /* w1 Ϊ����w ��ͼG �е����*/ 
p=G.vertices[v1].firstarc; 
while(p&&p->adjvex!=w1) /* ָ��p ��������ָ���㲻��w */ 
p=p->nextarc; 
if(!p||!p->nextarc) /* û�ҵ�w ��w �����һ���ڽӵ�*/ 
return -1; 
else /* p->adjvex==w */ 
return p->nextarc->adjvex; /* ����v ��(�����w ��)��һ���ڽӶ�������*/ 
}

Boolean visited[MAX_VERTEX_NUM]; /* ���ʱ�־����(ȫ����) */ 
void(*VisitFunc)(char* v); /* ��������(ȫ����) */ 
void DFS(ALGraph G,int v) 
{ /* �ӵ�v ����������ݹ��������ȱ���ͼG�� */ 
int w; 
VertexType v1,w1; 
strcpy(v1,*GetVex(G,v)); 
visited[v]=TRUE; /* ���÷��ʱ�־ΪTRUE(�ѷ���) */ 
VisitFunc(G.vertices[v].data); /* ���ʵ�v ������*/ 
for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,strcpy(w1,*GetVex(G,w)))) 
if(!visited[w]) 
DFS(G,w); /* ��v ����δ���ʵ��ڽӵ�w �ݹ����DFS */ 
}

void DFSTraverse(ALGraph G,void(*Visit)(char*)) 
{ /* ��ͼG ��������ȱ����� */ 
int v; 
VisitFunc=Visit; /* ʹ��ȫ�ֱ���VisitFunc,ʹDFS �����躯��ָ�����*/
for(v=0;v<G.vexnum;v++) 
visited[v]=FALSE; /* ���ʱ�־�����ʼ��*/ 
for(v=0;v<G.vexnum;v++) 
if(!visited[v]) 
DFS(G,v); /* ����δ���ʵĶ������DFS */ 
printf("\n"); 
}

void Display(ALGraph G) 
{ /* ���ͼ���ڽӾ���G */ 
int i; 
ArcNode *p; 
switch(G.kind) 
{ case DG: printf("����ͼ\n"); break; 
case DN: printf("������\n"); break; 
case AG: printf("����ͼ\n"); break; 
case AN: printf("������\n"); 
}
printf("%d �����㣺\n",G.vexnum); 
for(i=0;i<G.vexnum;++i) 
printf("%s ",G.vertices[i].data); 
printf("\n%d ����(��):\n",G.arcnum); 
for(i=0;i<G.vexnum;i++) 
{ 
p=G.vertices[i].firstarc; 
while(p) 
{
if(G.kind<=1) /* ����*/ 
{ 
printf("%s��%s ",G.vertices[i].data,G.vertices[p->adjvex].data); 
if(G.kind==DN) /* ��*/ 
printf(":%d ",*(p->info)); 
}
else /* ����(�����������) */ 
{ 
if(i<p->adjvex) 
{ 
printf("%s��%s ",G.vertices[i].data,G.vertices[p->adjvex].data); 
if(G.kind==AN) /* ��*/ 
printf(":%d ",*(p->info)); 
} 
}
p=p->nextarc; 
}
printf("\n"); 
} 
} 


/*������ȱ���*/
void BFS(ALGraph G, int i) {//�����ڵ㿪ʼ���й�����ȱ���
	int q[MAX_VERTEX_NUM];//����ģ����ʹ����Ķ���
	int front, rear;//frontΪ���е�ͷ����rearΪ���е�β��
	int temp;//�ñ������ڽ��ܳ��ӵ�Ԫ��
	front = 0;
	rear = 0;
	printf("%s", G.vertices[i].data);
	visited[i]=TRUE;
	q[rear++] = i;//ģ�����
	ArcNode* p;
	while (rear > front) {
		temp = q[front++];//ģ�����
		p = G.vertices[temp].firstarc;
		while (p) {
			if (!visited[p->adjvex]) {
				printf("%s", G.vertices[p->adjvex].data);
				q[rear++] = p->adjvex;
				visited[p->adjvex] = TRUE;
			}
			p = p->nextarc;
   		}
	}
}

void Graph_BFS(ALGraph G,void(*Visit)(char*)) {//����ͼ�Ĺ�����ȱ���
	int i;
	for (i = 0; i < G.vexnum; i++)
		visited[i] = FALSE;
	for (i = 0; i < G.vexnum; i++)
		if (!visited[i])
			BFS(G, i);
		printf("\n");
}
