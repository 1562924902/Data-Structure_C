 /*�������*/
Status InPutRLSMatrix(RLSMatrix &T) { 
	int num[MAXROW+1];
    printf( "����������,��,����Ԫ�ظ���(Ӣ�Ķ��Ÿ���):" );
    scanf("%d,%d,%d", &T.mu,&T.nu ,&T.tu);
    printf( "�������Ԫ�ص�λ�ú�ֵ:" );
    for (int k =1; k <=T.tu; k++)
        scanf("%d,%d,%d", &T.data[k].i,&T.data[k].j,&T.data[k].e);
	for (int row =1; row <=T.mu; row++) num[row] = 0;
    for (int t =1; t <= T.tu; t++) ++num[T.data[t].i];
    T.rpos[1] = 1;
    for (int i = 2; i <= T.mu; i++) T.rpos[i] = T.rpos[i-1]+num[i-1]; 
    return OK;
}

 /*�������*/
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


 /*����ת��*/
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



int comp(int c1, int c2){//�Ƚ������c1��c2�Ĵ�С��ϵ
    if (c1 < c2)
        return -1;
    if (c1 == c2)
        return 0;
    return 1;
}

void TransposeSMatrix(RLSMatrix M, RLSMatrix &T){//��ϡ�����M��ת�þ���T
    int i, j, k, num[MAXROW + 1];//[0]����
    T.mu = M.nu;//����T������ = ����M������
    T.nu = M.mu;//����T������ = ����M������
    T.tu = M.tu;//����T�ķ���Ԫ�ظ��� = ����M�ķ���Ԫ�ظ���
    if (T.tu)//����ǿ�
    {
        for (i = 1; i <= T.mu; ++i)//�Ӿ���T�ĵ�1�е����һ��
            num[i] = 0;//����Tÿ�з���Ԫ�ظ�������ֵ����Ϊ0
        for (i = 1; i <= M.tu; ++i)//����M�е�ÿһ������Ԫ�أ�����ͳ��
            ++num[M.data[i].j];//num[] = T��ÿ�У�M��ÿ�У�����Ԫ�ظ���
        T.rpos[1] = 1;//����T�е�1�еĵ�1������Ԫ�ص����Ϊ1
        for (i = 2; i <= T.mu; ++i)//�Ӿ���T�ĵ�2�е����һ��
            T.rpos[i] = T.rpos[i - 1] + num[i - 1];//��T�е�i�еĵ�1������Ԫ�ص����
        for (i = 1; i <= M.tu; ++i)
            num[i] = T.rpos[i];//num[] = M �ĵ�ǰ����Ԫ����T��Ӧ��ŵ�λ��
        for (i = 1; i <= M.tu; ++i)//����M�е�ÿһ������Ԫ��
        {
            j = M.data[i].j;//�ھ���T�е�����
            k = num[j] ++;//�ھ���T�е���ţ�num[j] + 1
            T.data[k].i = M.data[i].j;//��M.data[i]���жԵ�����T.data[k]
            T.data[k].j = M.data[i].i;
            T.data[k].e = M.data[i].e;
        }
    }
}


//ϡ�����ĳ˻�
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q){//��ϡ�����˻�Q = M * N
    int arow, brow, p, q, ccol, ctemp[MAXROW + 1], t, tp;
    if (M.nu != N.mu)//����M��N�޷����
        return ERROR;
    Q.mu = M.mu;//Q������ = M������
    Q.nu = M.nu;//Q������ = N������
    Q.tu = 0;//Q�ķ���Ԫ�ظ����ĳ�ֵΪ0
    if (M.tu * N.tu != 0)//Q�Ƿ������
    {
        for (arow = 1; arow <= M.mu; ++arow)//��M��ÿһ�У�arow��M�ĵ�ǰ��
        {
            for (ccol = 0; ccol <= Q.nu; ++ccol)//��Q�ĵ�1�е����һ��
                ctemp[ccol] = 0;//Q�ĵ�ǰ�еĸ���Ԫ���ۼ�������
            Q.rpos[arow] = Q.tu + 1;//Q��ǰ�еĵ�1��Ԫ��λ����һ�����1��Ԫ��֮��
            if (arow < M.mu)//�������һ��
                tp = M.rpos[arow + 1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
            else//�����һ��
                tp = M.tu + 1;//�����һ�����Ͻ�
            for (p = M.rpos[arow]; p < tp; ++p)//��M��ǰԪ����ÿһ������Ԫ
            {
                brow = M.data[p].j;//�ҵ���ӦԪ��N�е��кţ�M��ǰԪ���кţ�
                if (brow < N.mu)//�������һ��
                    t = N.rpos[brow + 1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
                else//�������һ��
                    t = N.tu + 1;//�����һ�����Ͻ�
                for (q = N.rpos[brow]; q < t; ++q)//��N��ǰ����ÿһ������Ԫ
                {
                    ccol = N.data[q].j;//�˻�Ԫ����Q�е��к�
                    ctemp[ccol] += M.data[p].e * N.data[q].e;//���˻��ۼӵ�Q��arow��ccol����
                }
            }//���Q�е�arow�е������е�Ԫ��ֵ������ctemp[]��
            for (ccol = 1; ccol <= Q.nu; ++ccol)//���ڵ�arow�е������У�ֻ�洢���еķ���Ԫ
            {
                if (ctemp[ccol])//���е�ֵ��Ϊ0
                {
                    if (++Q.tu > MAXSIZE)//Q�ķ���Ԫ�ظ���+1���������Ԫ����̫��
                        return ERROR;
                    Q.data[Q.tu].i = arow;//��Q[i][j]��˳�����ϡ�����Q
                    Q.data[Q.tu].j = ccol;
                    Q.data[Q.tu].e = ctemp[ccol];
                }
            }
        }
    }
    return OK; 
}
