 /*输入矩阵*/
Status InPutRLSMatrix(RLSMatrix &T) { 
	int num[MAXROW+1];
    printf( "输入矩阵的行,列,非零元素个数(英文逗号隔开):" );
    scanf("%d,%d,%d", &T.mu,&T.nu ,&T.tu);
    printf( "输入非零元素的位置和值:" );
    for (int k =1; k <=T.tu; k++)
        scanf("%d,%d,%d", &T.data[k].i,&T.data[k].j,&T.data[k].e);
	for (int row =1; row <=T.mu; row++) num[row] = 0;
    for (int t =1; t <= T.tu; t++) ++num[T.data[t].i];
    T.rpos[1] = 1;
    for (int i = 2; i <= T.mu; i++) T.rpos[i] = T.rpos[i-1]+num[i-1]; 
    return OK;
}

 /*输出矩阵*/
Status OutPutRLSMatrix(RLSMatrix T) {
    int m, n, k =1;
    for (m = 1; m <=T.mu; m++) {
        for (n = 1; n <=T.nu; n++) 
            if ((T.data[k].i) == m && (T.data[k].j ) == n) 
                printf("%4d", T.data[k++].e);
            else 
				printf("   0");
        printf("\n");
    }
    return OK;
}


 /*矩阵转置*/
Status TransposeSMatrix(RLSMatrix M) {
    RLSMatrix T; 
    int num[MAXROW+1];
    int cpot[MAXROW+1]; 
    int q, p, t;
    T.tu = M.tu;
    T.mu = M.nu;
    T.nu = M.mu;
    if (T.tu) {
        for (int col = 1; col < M.nu; col++) num[col] = 0;
        for (t = 1; t <= M.tu; t++) ++num[M.data[t].j];
        T.rpos[1] =cpot[1]= 1;
		for (int i = 2; i <=M.nu; i++) 
		{
			T.rpos[i] =T.rpos[i-1]+num[i-1];
			cpot[i]=T.rpos[i];
		}
        for (p =1; p <= M.tu; p++) {
            int col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = col;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
    return OK;
}



int comp(int c1, int c2){//比较这个数c1和c2的大小关系
    if (c1 < c2)
        return -1;
    if (c1 == c2)
        return 0;
    return 1;
}

void TransposeSMatrix(RLSMatrix M, RLSMatrix &T){//求稀疏矩阵M的转置矩阵T
    int i, j, k, num[MAXROW + 1];//[0]不用
    T.mu = M.nu;//矩阵T的行数 = 矩阵M的列数
    T.nu = M.mu;//矩阵T的列数 = 矩阵M的行数
    T.tu = M.tu;//矩阵T的非零元素个数 = 矩阵M的非零元素个数
    if (T.tu)//矩阵非空
    {
        for (i = 1; i <= T.mu; ++i)//从矩阵T的第1行到最后一行
            num[i] = 0;//矩阵T每行非零元素个数，初值设置为0
        for (i = 1; i <= M.tu; ++i)//对于M中的每一个非零元素，按列统计
            ++num[M.data[i].j];//num[] = T的每行（M的每列）非零元素个数
        T.rpos[1] = 1;//矩阵T中第1行的第1个非零元素的序号为1
        for (i = 2; i <= T.mu; ++i)//从矩阵T的第2行到最后一行
            T.rpos[i] = T.rpos[i - 1] + num[i - 1];//求T中第i行的第1个非零元素的序号
        for (i = 1; i <= M.tu; ++i)
            num[i] = T.rpos[i];//num[] = M 的当前非零元素在T中应存放的位置
        for (i = 1; i <= M.tu; ++i)//对于M中的每一个非零元素
        {
            j = M.data[i].j;//在矩阵T中的行数
            k = num[j] ++;//在矩阵T中的序号，num[j] + 1
            T.data[k].i = M.data[i].j;//将M.data[i]行列对调赋给T.data[k]
            T.data[k].j = M.data[i].i;
            T.data[k].e = M.data[i].e;
        }
    }
}


//稀疏矩阵的乘积
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q){//求稀疏矩阵乘积Q = M * N
    int arow, brow, p, q, ccol, ctemp[MAXROW + 1], t, tp;
    if (M.nu != N.mu)//矩阵M和N无法相乘
        return ERROR;
    Q.mu = M.mu;//Q的行数 = M的行数
    Q.nu = M.nu;//Q的列数 = N的列数
    Q.tu = 0;//Q的非零元素个数的初值为0
    if (M.tu * N.tu != 0)//Q是非零矩阵
    {
        for (arow = 1; arow <= M.mu; ++arow)//对M的每一行，arow是M的当前行
        {
            for (ccol = 0; ccol <= Q.nu; ++ccol)//从Q的第1列到最后一列
                ctemp[ccol] = 0;//Q的当前行的各列元素累加器清零
            Q.rpos[arow] = Q.tu + 1;//Q当前行的第1个元素位于上一行最后1个元素之后
            if (arow < M.mu)//不是最后一行
                tp = M.rpos[arow + 1];//下一行的第1个元素的位置是本行元素的上界
            else//是最后一行
                tp = M.tu + 1;//给最后一行设上界
            for (p = M.rpos[arow]; p < tp; ++p)//对M当前元行中每一个非零元
            {
                brow = M.data[p].j;//找到对应元在N中的行号（M当前元的列号）
                if (brow < N.mu)//不是最后一行
                    t = N.rpos[brow + 1];//下一行的第1个元素的位置是本行元素的上界
                else//不是最后一行
                    t = N.tu + 1;//给最后一行设上界
                for (q = N.rpos[brow]; q < t; ++q)//对N当前行中每一个非零元
                {
                    ccol = N.data[q].j;//乘积元素在Q中的列号
                    ctemp[ccol] += M.data[p].e * N.data[q].e;//将乘积累加到Q的arow行ccol列中
                }
            }//求得Q中第arow行的所有列的元素值，存于ctemp[]中
            for (ccol = 1; ccol <= Q.nu; ++ccol)//对于第arow行的所有列，只存储其中的非零元
            {
                if (ctemp[ccol])//该列的值不为0
                {
                    if (++Q.tu > MAXSIZE)//Q的非零元素个数+1，如果非零元个数太多
                        return ERROR;
                    Q.data[Q.tu].i = arow;//将Q[i][j]按顺序存入稀疏矩阵Q
                    Q.data[Q.tu].j = ccol;
                    Q.data[Q.tu].e = ctemp[ccol];
                }
            }
        }
    }
    return OK; 
}
