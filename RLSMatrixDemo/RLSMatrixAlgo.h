 /*输入矩阵*/
Status InPutRLSMatrix(RLSMatrix &T) { 
	int num[MAXROW+1];
    printf( "输入矩阵的行，列和非零元素个数:" );
    scanf("%d%d%d", &T.mu,&T.nu ,&T.tu);
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
    printf("输入矩阵的转置矩阵为:\n");
    OutPutRLSMatrix(T);
    return OK;
}



//进行两个稀疏矩阵之间的乘法，返回值为乘积矩阵
Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q){
		//求矩阵乘积Q=M*N,采用行逻辑链接存储表示
	int arow,tp,p,brow,t,q,ccol;
	int ctemp[MAXROW+1];
		 if(M.nu!=N.mu) return ERROR;
		Q.mu = M.mu;
		Q.nu = N.nu;
		Q.tu =0;			//Q初始化
		if(M.tu *N.tu != 0){		//Q是非零矩阵
			for(arow =1;arow<=M.mu;++arow){		//处理M的每一行
				ctemp[arow]= 0;			//当前行个元素累加器清零
				Q.rpos[arow]=Q.tu +1;
				if(arow<M.mu)tp =M.rpos[arow +1];
				else{tp =M.tu+1;}
			for(p=M.rpos[arow];p<tp;++p){//对当前行中每一个非零元
				brow =M.data[p].j;		//找到对应元在N中的行号
				if(brow<N.mu) t =N.rpos[brow+1];
				else{t=N.tu+1;}
				for(q =N.rpos[brow];q<t;++q){
					ccol = N.data[q].j;			//成绩元素在Q中列号
					ctemp[ccol] += M.data[p].e *N.data[q].e;
				}//for q
			}//求得Q中第crow( =aarow)行的非零元
			for(ccol =1;ccol<=Q.nu;++ccol)  //
				if(ctemp[ccol]){
					if(++Q.tu>MAXSIZE) return ERROR;
					Q.data[Q.tu].i = arow;
					Q.data[Q.tu].j = ccol;
					Q.data[Q.tu].e = ctemp[ccol];
				}//if
		}//for arow
	}//if
return OK;
}//MultSMatrix


