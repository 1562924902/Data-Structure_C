#define  MAXSIZE  100 
#define  MAXROW  10
typedef struct { // 定义三元组
    int i, j;
    SElemType e;
} Triple;

typedef struct { // 定义稀疏矩阵
    Triple data[MAXSIZE+1];
    int rpos[MAXROW+1];
    int mu, nu, tu;
} RLSMatrix;

